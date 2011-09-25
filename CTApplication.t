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

    sendInputEvent (KeyEvent k) windowId = request
        (KeyPressed name) = k

        case (name) of
            Tab ->  updateList name
            Shift ->
                    --if (isJust env) then 
                    --    (fromJust env).stdout.write ("shift " ++ (if (elem Shift modifiers) then "down" else "up") ++ "\n")
                    updateList name
            Control -> updateList name
            Command -> updateList name
            _ ->
            
        result (<- sendInputToWindow (KeyEvent k) windowId)

    sendInputEvent (MouseEvent m) windowId = request
        result (<- sendInputToWindow (MouseEvent m) windowId)
  
    sendInputEvent _ _ = request
        result False
    
    sendWindowResize toSize windowId = request
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                window.onWindowResize toSize modifiers

    shouldClose := False
    sendWindowCloseRequest windowId = request
        shouldClose := False
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

    resultState := False
    sendInputToWindow recvEvent windowId = do
        
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                resultState := (<- window.handleEvent recvEvent modifiers)
        
        result resultState

    getApplicationState = request
        result Running

    this = App {..}

    result this