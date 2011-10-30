module CTWindow where

import CTContainer
    
--------------------------------------------------------------------------------------------------
------          ** WINDOW **            ---------------------------------------------------------- 

mkCocoaWindow :: Class CocoaWindow
mkCocoaWindow = class    
    
    state := Inactive        
    
    rootContainer = new mkCocoaContainer
    defaultResponder = new defaultInputResponder this rootContainer
    
    DefaultEventResponder {setResponders=setRespondersImpl;..} = new basicHasResponders 
    
    setResponders rs = request
        setRespondersImpl (defaultResponder:rs)
    
    Container {setPosition=dummy1;getPosition=dummy2;setSize=setSizeImpl;..} = rootContainer
    setSize size = request
        if isActive state then 
            Active ref = state
            _ = windowSetSize ref size
        setSizeImpl size

    -- the position of the window may change, but the position of root container is (0,0)
    position := {x=0;y=0}
    getPosition = request
        result position
    setPosition pos = request
        if isActive state then 
            Active ref = state
            _ = windowSetPosition ref pos
        position := pos

    resizable := True
    getResizable = request
        result resizable
    setResizable bool = request
        if isActive state then 
            Active ref = state
            _ = windowSetResizable ref bool
        resizable := bool

    windowResponder := new defaultWindowResponder this        
    setWindowResponder resp = request 
        windowResponder := resp
        
    onWindowResize size = request
        windowResponder.onWindowResize size
    onWindowCloseRequest = request
        result (<- windowResponder.onWindowCloseRequest)

    windowId := 0
    getId = request
        result windowId

    isVisible := True
    initWindow app = request
        if isInactive state then
            (ref,id) = initCocoaWindow ()
            state    := Active ref
            windowId := id
            container_ref <- rootContainer.initComp app
            rootContainer.setName "RootContainer"
            addResponder defaultResponder
            _ = windowSetHidden ref
            _ = windowSetContentView ref container_ref
            _ = windowSetSize ref (<-getSize)        
            _ = windowSetPosition ref position 
            _ = windowSetResizable ref resizable
            if isVisible then
                _ = windowSetVisible ref

    destroyWindow = request
        if isActive state then 
            Active ref = state
            _ = destroyCocoaWindow ref -- Is this the right order for Cocoa?
            rootContainer.destroyComp
            state := Destroyed

    currentFocus := rootContainer
    setFocus cmp = request
         currentFocus := cmp
         if isActive state then
            Active ref = state
            cmp_state <- cmp.getState
            if isActive cmp_state then
                Active cmp_ref = cmp_state
                _ = windowSetFocus ref cmp_ref
    getFocus = request
        result currentFocus

    setVisible b = request
        if isVisible /= b then
            isVisible := b
            result (<- setVisibleImpl)
        else
            result False
            
    setVisibleImpl = do
        if isActive state then
            Active ref = state
            if isVisible then
                _ = windowSetVisible ref
            else
                _ = windowSetHidden ref
            result True
        else
            result False

    this = CocoaWindow {..}
    
    result this

defaultWindowResponder :: CocoaWindow -> Class RespondsToWindowEvents
defaultWindowResponder window = class
    onWindowResize toSize = request
    onWindowCloseRequest = request 
        result True
    result RespondsToWindowEvents {..}

getKey (KeyPressed k)  = k
getKey (KeyReleased k) = k
getKey _               = raise 99

mkNewEventAt (MousePressed _) p           = MousePressed p
mkNewEventAt (MouseReleased _) p          = MouseReleased p
mkNewEventAt (MouseClicked _) p           = MouseClicked p
mkNewEventAt (MouseMoved _) p             = MouseMoved p
mkNewEventAt (MouseWheelScroll _ dx dy) p = MouseWheelScroll p dx dy

getMousePosition (MousePressed p)         = p 
getMousePosition (MouseReleased p)        = p 
getMousePosition (MouseClicked p)         = p
getMousePosition (MouseWheelScroll p _ _) = p   

defaultInputResponder :: CocoaWindow -> Container -> Class RespondsToInputEvents
defaultInputResponder window rootContainer = class
    
    currentFocus := rootContainer
    focusables := []
    
    respondToInputEvent (KeyEvent keyEventType) modifiers = request
        currentFocus := (<- window.getFocus)
        
        if isDestroyed (<- currentFocus.getState) then
            window.setFocus rootContainer

        consumed <- currentFocus.respondToInputEvent (KeyEvent keyEventType) modifiers
        if (not consumed) then
            theKey = getKey keyEventType
            isPressed = case keyEventType of (KeyPressed _) -> True; _ -> False
            if (theKey == Tab && isPressed) then
                cmps <- rootContainer.getAllChildren
                foundFocus := False
                focusables := []
            
                forall c <- cmps do
                    if (<- c.getIsFocusable) then
                        focusables := c : focusables
            
                if (elem Shift modifiers) then
                    focusables := reverse focusables
        
                scanList focusables findKeyFocus

                if (length focusables > 0 && currentFocus == rootContainer) then
                    window.setFocus (head focusables)

        -- TODO: Allow menu to consume key events
        
        result False

    respondToInputEvent (MouseEvent me) modifiers = request
        cmps <- rootContainer.getAllChildren
        scanList cmps (findMouseFocus me modifiers)
        result (<- rootContainer.respondToInputEvent (MouseEvent me) modifiers)
    
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
        originBottomLeft = getMousePosition event
        windowSize <- window.getSize
        eventPosition = ({x=originBottomLeft.x; y=windowSize.height-originBottomLeft.y})
        parentPosition <- getParentPosition cmp
        relativePosition = getRelativePosition parentPosition eventPosition

        -- Construct new event based on local coordinates.
        eventInLocalCoords = mkNewEventAt event relativePosition
        
        cmpPos <- cmp.getPosition
        cmpSize <- cmp.getSize
        if clickInsideBox relativePosition cmpPos cmpSize then
            if (<- cmp.getIsFocusable) then
                window.setFocus cmp
            result (<- cmp.respondToInputEvent (MouseEvent eventInLocalCoords) modifiers)
        else
            result False
        
    result RespondsToInputEvents {..}

scanList [] _ = do 
    result False 
    
scanList x cmd = do
    if (<- cmd (head x)) then
        result True
    else
        result (<- (scanList (tail x) cmd))
    
getParentPosition cmp = do
    parent <- cmp.getParent
    if (isJust parent) then
        result <- (fromJust parent).getPosition
    else
        result ({x=0;y=0})

getRelativePosition from to = {x=to.x-from.x; y=to.y-from.y}

clickInsideBox mousePos boxPos boxSize = 
    (inInterval mousePos.x boxPos.x boxSize.width) && (inInterval mousePos.y boxPos.y boxSize.height)
    
inInterval x startPos width = 
    (x >= startPos && x <= (startPos+width))

instance eqCocoaKey :: Eq CocoaKey where
  (==) = compareKeys
  (/=) a b = not (compareKeys a b)

private

extern compareKeys          :: CocoaKey -> CocoaKey -> Bool
extern initCocoaWindow      :: () -> (CocoaRef, WindowID)
extern destroyCocoaWindow   :: CocoaRef -> ()
extern windowSetContentView :: CocoaRef -> CocoaRef -> ()
extern windowSetHidden      :: CocoaRef -> ()
extern windowSetVisible     :: CocoaRef -> ()
extern windowSetSize        :: CocoaRef -> Size -> ()
extern windowSetPosition    :: CocoaRef -> Position -> ()
extern windowSetFocus       :: CocoaRef -> CocoaRef -> () 
extern windowSetResizable   :: CocoaRef -> Bool -> ()