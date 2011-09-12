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

    destroyWindow = request
        if (state == Active) then 
            state := Destroyed
            rootContainer.destroy
            destroyCocoaWindow windowId

    
    getKey (KeyPressed theKey) = theKey
    getKey _ = raise 9
    
    currentFocus := rootContainer
    newFocus := Nothing
    
    getType (MousePressed _) = MousePressed
    getType (MouseReleased _) = MouseReleased
    getType (MouseClicked _) = MouseClicked

    posget (MousePressed p) = p 
    posget (MouseReleased p) = p 
    posget (MouseClicked p) = p 
        
    consumed := False
    focusables := []
    handleEvent (KeyEvent keyEventType) modifiers = request
        newFocus := Nothing
        
        if ((<- currentFocus.getState) == Destroyed) then
            currentFocus := rootContainer
            
        consumed := isJust (<- currentFocus.handleEvent (KeyEvent keyEventType) modifiers)
        
        if (consumed == False) then
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
                    setFocus (head focusables)

        -- TODO: Resolve menu key event capture. No listener if consumed.    
        result (boolToMaybe Nothing (<- dynamicHandleEvent keyEventType keyListener))
        
    handleEvent (WindowEvent a) modifiers = request
        case a of
            WindowClosed -> rootContainer.setState Inactive
            _ ->
        result (boolToMaybe Nothing (<- dynamicHandleEvent a windowListener))
        
    handleEvent (MouseEvent me) modifiers = request
        env.stdout.write "HELLO\n"
        cmps <- rootContainer.getAllComponents
        forall c <- cmps do
            env.stdout.write ((<-c.getName) ++ "\n")
        
        env.stdout.write "------\n"
        scanList cmps (findMouseFocus me modifiers)
        env.stdout.write "GOODBYE\n"
        result Nothing
        
    scanList [] _ = do 
        env.stdout.write "end of list.\n"
        result False 
        
    scanList x func = do
        if (<- func (head x)) then
            result True
        else
            env.stdout.write "not it. trying next node.\n"
            result (<- (scanList (tail x) func))
            
    foundFocus := False
    findKeyFocus cmp = do
        if (foundFocus) then
            currentFocus := cmp
            setFocus cmp
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

        {-env.stdout.write ("child name: " ++ (<-cmp.getName) ++ "\n")
        if (isJust parent) then
            env.stdout.write ("parent name: " ++ (<-(fromJust parent).getName) ++ "\n") -}

        p <- if (isJust parent) then ((fromJust parent).getPosition) else (do result {x=0;y=0})    
        pos2 = ({x=pos.x-p.x;y=pos.y-p.y})
        
        env.stdout.write ("")

        -- "create" new event to the containers coordsystem
        eventInNewCoordsystem = ((getType event) pos)
        cmpPos <- cmp.getPosition
        cmpSize <- cmp.getSize               

        env.stdout.write "herp\n"
        if (inInterval pos2.x cmpPos.x cmpSize.width && inInterval pos2.y cmpPos.y cmpSize.height) then
            consumer <- cmp.handleEvent (MouseEvent eventInNewCoordsystem) modifiers
            consume := isJust consumer

            if (consume) then
                env.stdout.write ("Sending event to " ++ (<- (fromJust consumer).getName) ++ "\n")
                focusable <- (fromJust consumer).getIsFocusable
                if (focusable) then
                    setFocus (fromJust consumer)
        result consume 
                 
{-        cmp <- rootContainer.handleEvent (MouseEvent a) modifiers
        if (isJust cmp) then
            jcmp = fromJust cmp
            if (<-jcmp.getIsFocusable) then
                env.stdout.write ("Mouse Click set focus to: " ++ (<- jcmp.getName) ++ "\n")
                setFocus jcmp
        result cmp-}
 
    setFocus cmp = action
        currentFocus := cmp
        if (state == Active) then
            windowSetFocus windowId cmp.id
            
        env.stdout.write ("FOCUS SET TO: " ++ (<- currentFocus.getName) ++ "\n")
            
       
 {-   handleEvent a modifiers = request
        cmp <- rootContainer.handleEvent a modifiers
        case a of
            MouseEvent m -> 
                if (isJust cmp) then
                    if (<-(fromJust cmp).getIsFocusable) then
                        setFocus (fromJust cmp)
            _ ->
        result cmp -} 

    installWindowListener wl = request
        windowListener := Just wl
        
    installKeyListener kl = request
        keyListener := Just kl
        
    installMouseListener = rootContainer.installMouseListener
         
{-    handleKeyEvent e = do
        consumed = False
        
        if (isJust keyListener) then
            consumed <- (fromJust keyListener) e
        
    --  if (consumed == False) then
        --  consumed <- focusTarget.handleEvent e 
        result consumed
-}    
 
                            
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