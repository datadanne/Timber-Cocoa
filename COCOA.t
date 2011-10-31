module COCOA where

import CTWindow
  
extern cocoa :: CocoaWorld -> Class CocoaEnv

private

cocoaApplication :: Class App
cocoaApplication = class
    activeWindows := []
    blockDefaultCocoaBehavior := False

    addWindow w = request
        w.initWindow this
        activeWindows := w:activeWindows

    modifiers := []

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
        result False -- Let keys pass through so that they appear in text fields etc.
    
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
                window.onWindowResize toSize

    shouldClose := True

    sendWindowCloseRequest windowId = request
        shouldClose := True
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                shouldClose := (<- window.onWindowCloseRequest)
        result shouldClose
    
    updateList key = do
        if (elem key modifiers) then
            modifiers := [d | d <- modifiers, not (d == key) ]
        else 
            modifiers := key : modifiers

    this = App {..}

    result this