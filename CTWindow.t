module CTWindow where

import CTContainer
    
--------------------------------------------------------------------------------------------------
------          ** WINDOW **            ---------------------------------------------------------- 

mkCocoaWindow :: World -> Class CocoaWindow
mkCocoaWindow w = class    
    
    state := Inactive        
    
    rootContainer = new mkCocoaContainer w
    defaultResponder = new defaultInputResponder this rootContainer
    
    DefaultEventResponder {setResponders=setRespondersImpl;respondToInputEvent=respondToInputEventImpl;..} = 
        new basicHasResponders 
    
    respondToInputEvent e m = request
        respond e m
        result False -- do not block Cocoa from processing events
    
    respond = new class
        act e m = action
            respondToInputEventImpl e m
        result act
    
    setResponders rs = request
        setRespondersImpl (defaultResponder:rs)
    
    Container {setPosition=dummy1;getPosition=dummy2;setSize=setSizeImpl;..} = rootContainer
    setSize size = request
        if isActive state then 
            Active ref = state
            windowSetSize ref size
        setSizeImpl size

    -- the position of the window may change, but the position of root container is (0,0)
    position := {x=0;y=0}
    getPosition = request
        result position
    setPosition pos = request
        if isActive state then 
            Active ref = state
            windowSetPosition ref pos
        position := pos

    resizable := True
    getResizable = request
        result resizable
    setResizable bool = request
        if isActive state then 
            Active ref = state
            windowSetResizable ref bool
        resizable := bool
    
    title := "CocoaWindow"
    getTitle = request
        result title            
    setTitle s = request
        if isActive state then
            Active ref = state
            windowSetTitle ref s
        title := s
        
    overrideWindowCloseRequest := False
    setWindowResponder resp override = request 
        overrideWindowCloseRequest := override
        set resp
    onWindowResize size = request
        resize size
        setSizeImpl size
    onWindowCloseRequest = request
        close
        if overrideWindowCloseRequest then
            result True
        else
            state := destroyState state
            result False

    (resize,close,set) = new class
        windowResponder := Nothing
        resize size = action
            if isJust windowResponder then
                (fromJust windowResponder).onWindowResize size
        close = action
            if isJust windowResponder then
                (fromJust windowResponder).onWindowCloseRequest
        set resp = request 
            windowResponder := Just resp
        result (resize,close,set)

    windowId := 0
    getId = request
        result windowId

    isVisible := True
    initWindow app = request
        if isInactive state then
            (ref,id) <- initCocoaWindow w
            state    := Active ref
            windowId := id
            container_ref <- rootContainer.initComp app
            rootContainer.setName "RootContainer"
            addResponder defaultResponder
            windowSetHidden ref
            windowSetContentView ref container_ref
            windowSetSize ref (<-getSize)        
            windowSetPosition ref position 
            windowSetResizable ref resizable
            windowSetTitle ref title
            if isVisible then
                windowSetVisible ref

    destroyWindow = request
        if isActive state then 
            Active ref = state
            destroyCocoaWindow ref -- Is this the right order for Cocoa?
            rootContainer.destroyComp
        state := destroyState state

    currentFocus := rootContainer
    setFocus cmp = request
         currentFocus := cmp
         if isActive state then
            Active ref = state
            cmp_state <- cmp.getState
            if isActive cmp_state then
                Active cmp_ref = cmp_state
                windowSetFocus ref cmp_ref
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
                windowSetVisible ref
            else
                windowSetHidden ref
            result True
        else
            result False 

    this = CocoaWindow {..}
    
    result this

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
        scanList (reverse cmps) (findMouseFocus me modifiers)
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

extern initCocoaWindow      :: World -> Request (CocoaRef, WindowID)
extern destroyCocoaWindow   :: CocoaRef -> Request ()
extern windowSetContentView :: CocoaRef -> CocoaRef -> Request ()
extern windowSetHidden      :: CocoaRef -> Request ()
extern windowSetVisible     :: CocoaRef -> Request ()
extern windowSetSize        :: CocoaRef -> Size -> Request ()
extern windowSetPosition    :: CocoaRef -> Position -> Request ()
extern windowSetFocus       :: CocoaRef -> CocoaRef -> Request () 
extern windowSetResizable   :: CocoaRef -> Bool -> Request ()  
extern windowSetTitle       :: CocoaRef -> String -> Request ()