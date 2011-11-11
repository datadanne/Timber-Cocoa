module COCOA where

import CTWindow
  
extern cocoa :: World -> Class CocoaEnv

private

cocoaApplication :: Class App
cocoaApplication = class
    activeWindows := []
    modifiers := []
        
    addWindow w = request
        w.initWindow this
        activeWindows := w:activeWindows

    sendInputEvent (KeyEvent k) windowId = request
        name = case k of 
            (KeyPressed  n) -> n
            (KeyReleased n) -> n
        case name of 
            Tab -> updateList name
            Shift -> updateList name
            Control -> updateList name
            Command -> updateList name
            _ -> 
        sendInputToWindow (KeyEvent k) windowId
        {- Let key events pass through so that they appear in text fields etc. -}
        result NotConsumed
    
    sendInputEvent (MouseEvent m) windowId = request
        sendInputToWindow (MouseEvent m) windowId
        case m of
            {- Block scrolling events since we control them in Timber instead -}
            (MouseWheelScroll _ _ _) -> result Consumed 
            _ -> result NotConsumed 
  
    sendInputEvent _ _ = request
        result NotConsumed
        
    sendInputToWindow recvEvent windowId = do
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                _ <- window.respondToInputEvent recvEvent modifiers
    
    sendWindowResize toSize windowId = request
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                window.windowResizing toSize

    shouldClose := True

    sendWindowCloseRequest windowId = request
        shouldClose := True
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                shouldClose := (<- window.windowClosing)
        result shouldClose
    
    updateList key = do
        if (elem key modifiers) then
            modifiers := [d | d <- modifiers, not (d == key) ]
        else 
            modifiers := key : modifiers

    this = App {..}

    result this