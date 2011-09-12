module CTApplication where

import CTCommon

-- TODO: Add way to set window focus.

-- do not create an object of this class!                       
cocoaApplication = class
    activeWindows := []

    showWindow w = request
        w.initWindow this
        activeWindows := w:activeWindows

    modifiers := []
    
    env := Nothing
    
    setEnv e = request
        env:= Just e

    eventDispatcher (KeyEvent k) windowId = request
      --  (fromJust env).stdout.write "SENT KEYPRESS\n"
        (KeyPressed name) = k

        case (name) of
            Tab -> 
              --  (fromJust env).stdout.write "TAB\n"
                       updateList name
            Shift ->
                    if (isJust env) then 
                        (fromJust env).stdout.write ("shift " ++ (if (elem Shift modifiers) then "down" else "up") ++ "\n")
                    updateList name
            Control -> updateList name
            Command -> updateList name
            _ ->
            
        sendToWindow (KeyEvent k) windowId
        result False

    eventDispatcher (MouseEvent m) windowId = request
        if (isJust env) then
            (fromJust env).stdout.write ("got a new mouse event to window" ++ (show windowId) ++ "!\n")
        
        sendToWindow (MouseEvent m) windowId
        result False
        
    eventDispatcher recv windowId = request
        sendToWindow recv windowId
        result False

    
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
        
    sendToWindow recvEvent windowId = do
       -- (fromJust env).stdout.write "hello\n"
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                window.handleEvent recvEvent modifiers

    getApplicationState = request
        result Running

    this = App {..}

    result this