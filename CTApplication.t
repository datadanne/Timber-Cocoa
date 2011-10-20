module CTApplication where

import CTCommon

-- TODO: Add way to set window focus.

-- do not create an object of this class!                       
cocoaApplication = class
    activeWindows := []
    blockDefaultCocoaBehavior := False

    addWindow w = request
        w.initWindow this
        activeWindows := w:activeWindows

    modifiers := []
    
    env := Nothing
    
    setEnv e = request
        env:= Just e

    sendInputEvent (KeyEvent k) windowId = request
        (KeyPressed name) = k

        case (name) of
            Tab -> updateList name
            Shift -> updateList name
            Control -> updateList name
            Command -> updateList name
            _ ->
            
        sendInputToWindow (KeyEvent k) windowId
        -- Block key events from Cocoa, since we want to deal with these in Timber.
        result True

    --crashEverythingForNoReason _ = True
    
    sendInputEvent (MouseEvent m) windowId = request
        sendInputToWindow (MouseEvent m) windowId
        
        case m of
            (MouseWheelScroll _ _ _) -> result True -- Block scroll since we control it in Timber instead.
            _ -> result blockDefaultCocoaBehavior
  
    sendInputEvent _ _ = request
        result blockDefaultCocoaBehavior
        
    sendInputToWindow recvEvent windowId = do
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                _ <- window.respondToInputEvent recvEvent modifiers
    
    sendWindowResize toSize windowId = request
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                window.onWindowResize toSize modifiers

    shouldClose := True
    sendWindowCloseRequest windowId = request
        shouldClose := True
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                shouldClose := (<- window.onWindowCloseRequest modifiers)
        result shouldClose
    
    updateList key = do
        if (elem key modifiers) then
            modifiers := [d | d <- modifiers, not (d == key) ]
        else 
            modifiers := key : modifiers

        if (isJust env) then 
            (fromJust env).stdout.write ("Modifiers: ")
            if (elem Shift modifiers) then
                (fromJust env).stdout.write "SHIFT"
            if (elem Control modifiers) then
                (fromJust env).stdout.write " CONTROL "
            if (elem Command modifiers) then
                (fromJust env).stdout.write " COMMAND"
            (fromJust env).stdout.write "\n"


    getApplicationState = request
        result Running

    this = App {..}

    result this