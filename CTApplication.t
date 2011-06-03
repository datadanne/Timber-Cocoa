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

    eventDispatcher (KeyEvent k) windowId = action
      --  (fromJust env).stdout.write "SENT KEYPRESS\n"
        (KeyPressed name) = k

        case (name) of
            Tab -> 
              --  (fromJust env).stdout.write "TAB\n"
                updateList name
            Shift ->   updateList name
            Control -> updateList name
            Command -> updateList name
            _ ->
            
        sendToWindow (KeyEvent k) windowId
        
    eventDispatcher recv windowId = action
     --   (fromJust env).stdout.write "KEYPRESSED IGNORED\n"
        sendToWindow recv windowId
              
    updateList key = do
        if (elem key modifiers) then
            modifiers := [d | d <- modifiers, d /= key]
        else 
            modifiers := key : modifiers

        --if (isJust env) then 
         --   (fromJust env).stdout.write ("Modifiers: " ++ (show (length modifiers)) ++ "\n")
        
    sendToWindow recvEvent windowId = action
       -- (fromJust env).stdout.write "hello\n"
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                window.handleEvent recvEvent modifiers

    getApplicationState = request
        result Running

    this = App {..}

    result this