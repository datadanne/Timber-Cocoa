module CTWindow where

import POSIX -- temporary, only needed for Env
import COCOA
import CTContainer
    
--------------------------------------------------------------------------------------------------
------          ** WINDOW **            ---------------------------------------------------------- 
mkCocoaWindow :: Env -> Class CocoaWindow
mkCocoaWindow env = class    
    windowId = new mkCocoaID
    state := Inactive

    rootContainer = new mkCocoaContainer env
    addComponent = rootContainer.addComponent
    getComponents = rootContainer.getComponents
    removeComponent = rootContainer.removeComponent
    removeAllComponents = rootContainer.removeAllComponents
    setBackgroundColor = rootContainer.setBackgroundColor
    getBackgroundColor = rootContainer.getBackgroundColor
 
    handlers = new basicHasResponders 
    addResponder = handlers.addResponder
    setResponders = handlers.setResponders
    getResponders = handlers.getResponders
    respondToInputEvent = handlers.respondToInputEvent
    
    
    dwh := new defaultWindowResponder this env
    
    onWindowResize size modifiers = request
        result (<- dwh.onWindowResize size modifiers)

    onWindowCloseRequest modifiers = request
        result (<- dwh.onWindowCloseRequest modifiers)

    setWindowResponder resp = request 
        dwh := resp  
    
    getContainerID = request
        result rootContainer.id
        
    position := {x=0;y=0}
    getPosition = request
        result position

    setPosition pos = request
        if (state == Active) then 
            windowSetPosition windowId pos
        position := pos

    getSize = rootContainer.getSize
    setSize size = request
        if (state == Active) then 
            windowSetSize windowId size
        rootContainer.setSize size
    
    nr := 0
    initWindow app = request
        if (state == Inactive) then
            nr := <- initCocoaWindow this app
            rootContainer.init app
            rootContainer.setName "rootContainer"
            
            state := Active
            inithelper 
        
    inithelper = do
        _ <- internalSetVisible isVisible

        windowSetSize windowId (<- rootContainer.getSize)        
        windowSetPosition windowId position
        windowSetContentView this rootContainer.id
        
        wh = new defaultInputResponder this rootContainer env
        handlers.addResponder wh
            


    getId = request
        result nr

    destroyWindow = request
        if (state == Active) then 
            state := Destroyed
            rootContainer.destroy
            destroyCocoaWindow windowId

    currentFocus := rootContainer
    setFocus cmp = request
         currentFocus := cmp
         if (state == Active) then
             windowSetFocus windowId cmp.id
         
    getFocus = request
        result currentFocus

    isVisible := True
    setVisible b = request
        if (isVisible /= b)  then
            isVisible := b
            result (<- internalSetVisible isVisible)
        else
            result False
            
    internalSetVisible vis = do
        isActive = (state == Active)
        if (isActive) then
            if (vis) then
                windowSetVisible windowId
            else
                windowSetHidden windowId
        result isActive
    
    this = CocoaWindow {..}
    
    result this

defaultWindowResponder window env = class

    onWindowResize toSize modifiers = request
        env.stdout.write ("Resizing window to width: " ++ (show toSize.width) ++ ", height: " ++ (show toSize.height) ++ "\n")

    onWindowCloseRequest modifiers = request
        result True

    setWindowResponder responder = request

    result RespondsToWindowEvents {..}
    
defaultInputResponder window rootContainer env = class
    getKey (KeyPressed theKey) = theKey
    getKey _ = raise 9

    mkNewEvent (MousePressed _) p = MousePressed p
    mkNewEvent (MouseReleased _) p = MouseReleased p
    mkNewEvent (MouseClicked _) p = MouseClicked p
    mkNewEvent (MouseMoved _) p = MouseMoved p
    mkNewEvent (MouseWheelScroll _ dx dy) p = MouseWheelScroll p dx dy

    posget (MousePressed p) = p 
    posget (MouseReleased p) = p 
    posget (MouseClicked p) = p
    posget (MouseWheelScroll p _ _) = p   
    
    currentFocus := rootContainer

    focusables := []
    respondToInputEvent (KeyEvent keyEventType) modifiers = request
        currentFocus := <- window.getFocus
        
        if ((<- currentFocus.getState) == Destroyed) then
            window.setFocus rootContainer

        consumed <- currentFocus.respondToInputEvent (KeyEvent keyEventType) modifiers
    
        if (not consumed) then
            theKey = getKey keyEventType
            if (theKey == Tab) then
                cmps <- rootContainer.getAllComponents
                foundFocus := False
                focusables := []
            
                forall c <- cmps do
                    if (<- c.getIsFocusable) then
                        focusables := c : focusables
            
                if (elem Shift modifiers) then
                    focusables := reverse focusables
        
                scanList focusables findKeyFocus

                if (focusables /= [] && currentFocus == rootContainer) then
                    window.setFocus (head focusables)

        -- TODO: Resolve menu key event capture. No listener if consumed.    
        result False

    respondToInputEvent (MouseEvent me) modifiers = request
        cmps <- rootContainer.getAllComponents
        scanList cmps (findMouseFocus me modifiers)
        result (<- rootContainer.respondToInputEvent (MouseEvent me) modifiers)
    
    scanList [] _ = do 
        result False 
    
    scanList x func = do
        if (<- func (head x)) then
            result True
        else
            result (<- (scanList (tail x) func))
        
    foundFocus := False
    findKeyFocus cmp = do
        if (foundFocus) then
            currentFocus := cmp
            window.setFocus cmp
            result True
        elsif (cmp == currentFocus) then
            currentFocus := rootContainer
            foundFocus := True
            result False
        else
            result False

    findMouseFocus event modifiers cmp = do
        originBottomLeft = posget event
        windowSize = <- window.getSize
        eventPosition = ({x=originBottomLeft.x;y=windowSize.height-originBottomLeft.y})
        parentPosition <- (getParentPosition cmp)
        relativePosition = getRelativePosition parentPosition eventPosition

        -- Construct new event based on local coordinates.
        eventInLocalCoords = mkNewEvent event relativePosition
        
        cmpPos <- cmp.getPosition
        cmpSize <- cmp.getSize
        if (clickInsideBox relativePosition cmpPos cmpSize) then
            if ( <- cmp.getIsFocusable ) then
                window.setFocus cmp
            result (<- cmp.respondToInputEvent (MouseEvent eventInLocalCoords) modifiers)
        else
            result False
        
    result RespondsToInputEvents {..}
    
getParentPosition cmp = do
    parent <- cmp.getParent
    if (isJust parent) then
        result <- (fromJust parent).getPosition
    else
        result ({x=0;y=0})

getRelativePosition from to = {x=to.x-from.x;y=to.y-from.y}

clickInsideBox mousePos boxPos boxSize = inInterval mousePos.x boxPos.x boxSize.width && inInterval mousePos.y boxPos.y boxSize.height
inInterval x startPos width = (x >= startPos && x <= (startPos+width))

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--window
private
extern initCocoaWindow :: CocoaWindow -> App -> Request Int
extern destroyCocoaWindow :: CocoaID -> Request ()
extern windowSetContentView :: CocoaWindow -> CocoaID -> Request ()      -- external method for changing contentView for a window!
extern windowSetHidden :: CocoaID -> Request ()
extern windowSetVisible :: CocoaID -> Request ()
extern windowSetSize :: CocoaID -> Size -> Request ()
extern windowSetPosition :: CocoaID -> Position -> Request ()
extern windowSetFocus :: CocoaID -> CocoaID -> Request ()