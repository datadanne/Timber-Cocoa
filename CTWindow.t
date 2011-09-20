module CTWindow where

import POSIX
import CTCommon
import CTContainer

--------------------------------------------------------------------------------------------------
------          ** WINDOW **            ---------------------------------------------------------- 
mkWindow env = class        
    windowId = new mkCocoaID
    keyListener := Nothing
    windowListener := Nothing
    nr := 0
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

    handlers = new basicHasHandlers 
    addHandler = handlers.addHandler
    setHandlers = handlers.setHandlers
    getHandlers = handlers.getHandlers
    handleEvent = handlers.handleEvent

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
    
    getId = request
        result nr
    
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
        
        eventHandler = new windowEventHandler this rootContainer env
        handlers.addHandler eventHandler

    destroyWindow = request
        if (state == Active) then 
            state := Destroyed
            rootContainer.destroy
            destroyCocoaWindow windowId

    installWindowListener wl = request
        windowListener := Just wl

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
    
    this := CocoaWindow {..}
    
    result this


windowEventHandler window rootContainer env = class

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
    
    result HandlesEvents {..}

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