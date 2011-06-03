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
    
    rootContainer = new mkContainer env
        
    
    addComponent = rootContainer.addComponent
    getComponents = rootContainer.getComponents
    getId = request
        result nr
    
    initWindow app = request
        nr := <- initCocoaWindow this app
        rootContainer.init app
        state := Active
        isVisible := True
        setContentViewForWindow this rootContainer.id
        
    destroyWindow = request
        if (state == Active) then 
            state := Destroyed
            rootContainer.destroy
            destroyCocoaWindow windowId

    setFocus cmp = action 
        currentFocus := Just cmp
        if (state == Active) then
            windowSetFocus windowId cmp.id


    currentFocus := Nothing
    nextFocus := Nothing
    previousFocus := Nothing
    
    
    consumed := False
    handleEvent (KeyEvent a) modifiers = request
    
        (KeyPressed theStr) = a
        
        --env.stdout.write ("------ Key Event received in " ++ (show nr) ++ "-----------\n")
        --env.stdout.write ("Key received: " ++ theStr ++ "\n")
        
        consumed := False
        if (isJust currentFocus) then
            consumed := isJust (<- (fromJust currentFocus).handleEvent (KeyEvent a) modifiers)
        
        if (consumed == False) then
            if (theStr == Tab) then
                --env.stdout.write "Key received: Tab\n"
                if (isNothing currentFocus) then
                    currentFocus := (<- rootContainer.getNextFocusTarget)

                if (isJust currentFocus) then
                    nextFocus := <- (fromJust currentFocus).getNextFocusTarget
        
                if (isNothing nextFocus) then
                    --env.stdout.write "No focus target found. Resetting focus.\n"
                    currentFocus := (<- rootContainer.getNextFocusTarget)

                    if (isJust currentFocus) then
                        nextFocus := <- (fromJust currentFocus).getNextFocusTarget
                
                if (isJust nextFocus) then
                    --env.stdout.write ("Focus target: " ++ (<-showName nextFocus) ++ "\n")
                    next <- (fromJust nextFocus).getNextFocusTarget
                    --env.stdout.write ("Next Focus target: " ++ (<-showName next) ++ "\n")
            
                    currentFocus := nextFocus
                    setFocus (fromJust nextFocus)
                
            elsif (theStr == CapsLock) then    
                if (isNothing currentFocus) then
                    currentFocus := (<- rootContainer.getPreviousFocusTarget)

                if (isJust currentFocus) then
                    previousFocus := <- (fromJust currentFocus).getPreviousFocusTarget
    
                if (isNothing previousFocus) then
                    --env.stdout.write "No focus target found. Resetting focus.\n"
                    currentFocus := (<- rootContainer.getPreviousFocusTarget)

                    if (isJust currentFocus) then
                        previousFocus := <- (fromJust currentFocus).getPreviousFocusTarget
            
                if (isJust previousFocus) then
                    --env.stdout.write ("Focus target: " ++ (<-showName previousFocus) ++ "\n")
                    next <- (fromJust previousFocus).getPreviousFocusTarget
                    --env.stdout.write ("Previous Focus target: " ++ (<-showName next) ++ "\n")
        
                    currentFocus := previousFocus
                    setFocus (fromJust previousFocus)            
            
       --env.stdout.write "=== handleEvent finished\n\n"

        result (boolToMaybe Nothing (<- dynamicHandleEvent a keyListener))
        
    handleEvent (WindowEvent a) modifiers = request
        case a of
            WindowClosed -> do if (state == Active) then state := Inactive
            _ ->
        result (boolToMaybe Nothing (<- dynamicHandleEvent a windowListener))
        
    handleEvent (MouseEvent a) modifiers = request
        cmp <- rootContainer.handleEvent (MouseEvent a) modifiers
        if (isJust cmp) then
            if (<-(fromJust cmp).getIsFocusable) then
                setFocus (fromJust cmp)
        result cmp
        
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

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--window
extern initCocoaWindow :: CocoaWindow -> App -> Request Int
extern destroyCocoaWindow :: CocoaID -> Request ()
extern setContentViewForWindow :: CocoaWindow -> CocoaID -> Request ()      -- external method for changing contentView for a window!
extern windowSetHidden :: CocoaID -> Action
extern windowSetVisible :: CocoaID -> Action
extern windowSetFocus :: CocoaID -> CocoaID -> Request ()