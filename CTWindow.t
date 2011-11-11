module CTWindow where

import CTContainer
    
--------------------------------------------------------------------------------------------------
------          ** WINDOW **            ---------------------------------------------------------- 

mkCocoaWindow :: World -> Class CocoaWindow
mkCocoaWindow w = class    
    
    state := Inactive        
    
    rootContainer = new mkCocoaContainer w
    
    defaultResponder = new defaultInputResponder this rootContainer
    defaultResponderAdded := False
    
    DefaultEventResponder {setResponders=setRespondersImpl;addResponder=addResponderImpl;
        respondToInputEvent=respondToInputEventImpl;..} = new basicHasResponders 
    
    respondToInputEvent e m = request
        respond e m
        result NotConsumed -- do not block Cocoa from processing events
    
    respond = new class
        act e m = action
            respondToInputEventImpl e m
        result act

    addResponder r = request
        if not defaultResponderAdded then
            addResponderImpl defaultResponder
            defaultResponderAdded := True
        addResponderImpl r
    
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
    windowResizing size = request
        resize size 
        containerSize = {width=size.width;height=(size.height-23)}
        setSizeImpl containerSize
    windowClosing = request
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
            if not defaultResponderAdded then
                addResponderImpl defaultResponder
                defaultResponderAdded := True
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

mkNewEventAt (MousePressed _) p           = MousePressed p
mkNewEventAt (MouseReleased _) p          = MouseReleased p
mkNewEventAt (MouseClicked _) p           = MouseClicked p
mkNewEventAt (MouseMoved _) p             = MouseMoved p
mkNewEventAt (MouseWheelScroll _ dx dy) p = MouseWheelScroll p dx dy

defaultInputResponder :: CocoaWindow -> Container -> Class RespondsToInputEvents
defaultInputResponder window rootContainer = class
    
    currentFocus := rootContainer
    
    respondToInputEvent (KeyEvent keyEventType) modifiers = request
        {- default implementation that uses rootContainer as the default focus target.
           allows the currently focused component to respond to the event, and if its not 
           consumed it will in case of a tab or shift-tab event pass focus to the "next" 
           (ordered by time added) focusable component. -}
        currentFocus := (<- window.getFocus)
        
        if isDestroyed (<- currentFocus.getState) then
            window.setFocus rootContainer
        
        -- first let the current focus target be able to consume the event
        res <- currentFocus.respondToInputEvent (KeyEvent keyEventType) modifiers
        
        if res == NotConsumed then
            if tabPressed keyEventType then
                -- the focused component did not consume the event AND it was a tab-event.
                
                -- step 1. get a list of all components that are focusable  
                cmps <- rootContainer.getAllChildren
                focusables = concat (<- forall c <- cmps do
                                            if (<- c.getIsFocusable) then
                                                result [c]
                                            else
                                                result [])
                                                
                {- change the order of the list to move focus in the right direction in 
                relation to if shift is pressed -}
                listToScan = if (elem Shift modifiers) then focusables else reverse focusables
                
                {- step 2. scan the list of focusables until we find the currently focused 
                   component, and set focus to the successor in the list -}
                foundFocus := False
                scanList listToScan findKeyFocus
                
                {- a special case: if the currently focused component is the last element in 
                    the list (or if it has removed), the head of the list should be focused -}
                if (length listToScan > 0 && currentFocus == rootContainer) then
                    window.setFocus (head listToScan)

        -- TODO: Allow menu to consume key events
        result NotConsumed

    respondToInputEvent (MouseEvent me) modifiers = request
        {- default implementation of mouse event dispatching, that "flattens out" the component 
           structure to a list where the first component is the component that was added last. 
           The list is then traversed and each component that contains the point of the event 
           inside its coordinates is given the possibility to consume it until one component 
           has consumed it. -}
        cmps <- rootContainer.getAllChildren
        scanList (reverse cmps) (findMouseFocus me modifiers)
        result (<- rootContainer.respondToInputEvent (MouseEvent me) modifiers)
    
    foundFocus := False
    {- this procedure is used in combination with scanList to scan the list of focusable components 
       until we find the currently focused component and then set focus to its successor -}
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
    
    {- this procedure is used in combination with scanList to scan the list of components and allow each component where the position of the event is inside its rectangle to consume it, and once its been consumed the dispatching stops. -}
    findMouseFocus event modifiers cmp = do
        originBottomLeft  = getMousePosition event
        windowSize        <- window.getSize
        eventPosition     = ({x=originBottomLeft.x; y=windowSize.height-originBottomLeft.y})
        parentPosition    <- getParentPosition cmp
        relativePosition  = getRelativePosition parentPosition eventPosition

        -- Construct new event based on local coordinates.
        eventInLocalCoords = mkNewEventAt event relativePosition
        
        cmpPos  <- cmp.getPosition
        cmpSize <- cmp.getSize
        if clickInsideBox relativePosition cmpPos cmpSize then
            isFocusable <- cmp.getIsFocusable
            if (isMouseClick event && isFocusable) then
                window.setFocus cmp
            result isConsumed (<- cmp.respondToInputEvent (MouseEvent eventInLocalCoords) modifiers)
        else
            result False
        
    result RespondsToInputEvents {..}

-- procedure that runs cmd with each element in the list as a parameter (one at a time starting with the first, then the second etc) 
-- until cmd elem results in True
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

getRelativePosition from to =
    {x=to.x-from.x; y=to.y-from.y}

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