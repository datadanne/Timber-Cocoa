module CTWindow where

import POSIX
import CTCommon
import CTContainer

--------------------------------------------------------------------------------------------------
------          ** WINDOW **            ---------------------------------------------------------- 
mkWindow env = class        
    windowId = new mkCocoaID
    state := Inactive
    isVisible := False
    position := {x=0;y=0}
    
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
    handleEvent = handlers.handleEvent
       
    dwh = new defaultWindowResponder this env
    onWindowResize = dwh.onWindowResize
    onWindowCloseRequest = dwh.onWindowCloseRequest
    setWindowResponder = dwh.setWindowResponder
    

    getContainerID = request
        result rootContainer.id
        
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
        nr := <- initCocoaWindow this app
        rootContainer.init app
        rootContainer.setName "rootContainer"
        
        state := Active
        isVisible := True
        
        inithelper 
        
    inithelper = do
        windowSetPosition windowId position
        windowSetSize windowId (<- rootContainer.getSize)
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
    setFocus cmp = action
         currentFocus := cmp
         if (state == Active) then
             windowSetFocus windowId cmp.id

         env.stdout.write ("FOCUS SET TO: " ++ (<- cmp.getName) ++ "\n")
         
    getFocus = request
        result currentFocus

    -- VISIBILITY
    hide = request
        if (state == Active && isVisible == True) then
            windowSetHidden windowId
            isVisible := False
            result True
        else
            result False
                              
    setVisible = request
        if (state == Active && isVisible == False) then
            windowSetVisible windowId
            isVisible := True
            result True
        else
            result False
    
    this = CocoaWindow {..}
    
    result this

defaultWindowResponder window env = class
    max := 0
    onWindowResize toSize modifiers = request
        env.stdout.write ("Resizing window to width: " ++ (show toSize.width) ++ ", height: " ++ (show toSize.height) ++ "\n")
        max := toSize.width
        if (toSize.height > toSize.width) then
            max := toSize.height
        result ({width=max; height=max})

    onWindowCloseRequest modifiers = request
        result False

    setWindowResponder responder = request

    result RespondsToWindowEvents {..}
    
defaultInputResponder window rootContainer env = class
    getKey (KeyPressed theKey) = theKey
    getKey _ = raise 9

    getType (MousePressed _) = MousePressed
    getType (MouseReleased _) = MouseReleased
    getType (MouseClicked _) = MouseClicked

    posget (MousePressed p) = p 
    posget (MouseReleased p) = p 
    posget (MouseClicked p) = p 
    
    currentFocus := rootContainer

    focusables := []
    handleEvent (KeyEvent keyEventType) modifiers = request
        currentFocus := <- window.getFocus
        
        if ((<- currentFocus.getState) == Destroyed) then
            window.setFocus rootContainer

        consumed = (<- currentFocus.handleEvent (KeyEvent keyEventType) modifiers)
    
        if (consumed == False) then
            env.stdout.write "moving focus" 
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
    
    handleEvent (WindowEvent eventType) modifiers = request
        case eventType of
            WindowClose -> 
                rootContainer.setState Inactive
                result False
            WindowResize toSize -> 
                width = toSize.width
                height = toSize.height
                scale = max width height
                newSize = {width=scale;height=scale}
                result False
            _ ->
                result False
    
    handleEvent (MouseEvent me) modifiers = request
        cmps <- rootContainer.getAllComponents
        scanList cmps (findMouseFocus me modifiers)
        result (<- rootContainer.handleEvent (MouseEvent me) modifiers)
    
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
    
    consume := False
    findMouseFocus event modifiers cmp = do
        consume := False

        pos = posget event
        et = getType event
        parent <- cmp.getParent
        p <- if (isJust parent) then ((fromJust parent).getPosition) else (do result {x=0;y=0})    
        pos2 = ({x=pos.x-p.x;y=pos.y-p.y})

        -- "create" new event to the containers coordsystem
        eventInNewCoordsystem = ((getType event) pos)
        cmpPos <- cmp.getPosition
        cmpSize <- cmp.getSize               

        if (inInterval pos2.x cmpPos.x cmpSize.width && inInterval pos2.y cmpPos.y cmpSize.height) then
            cmp.handleEvent (MouseEvent eventInNewCoordsystem) modifiers

            env.stdout.write ("Sending event to " ++ (<- cmp.getName) ++ "\n")
            focusable <- cmp.getIsFocusable
            if (focusable) then
                window.setFocus cmp
        result consume
    
    result RespondsToInputEvents {..}

inInterval x startPos width = (x >= startPos && x <= (startPos+width))

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--window
extern initCocoaWindow :: CocoaWindow -> App -> Request Int
extern destroyCocoaWindow :: CocoaID -> Request ()
extern windowSetContentView :: CocoaWindow -> CocoaID -> Request ()      -- external method for changing contentView for a window!
extern windowSetHidden :: CocoaID -> Action
extern windowSetVisible :: CocoaID -> Action
extern windowSetSize :: CocoaID -> Size -> Action
extern windowSetPosition :: CocoaID -> Position -> Action
extern windowSetFocus :: CocoaID -> CocoaID -> Request ()