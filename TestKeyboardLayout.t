module TestKeyboardLayout where

import COCOA
import POSIX

root w = class
    osx = new cocoa w
    w1 = new mkCocoaWindow w
    env = new posix w
    
    start app = action
        w1.setPosition ({x=100,y=100})
        w1.setSize ({width=400,height=400}) 
        w1.setBackgroundColor web_gray
        w1.setTitle "TestKeyboardLayout"
        w1.addResponder (new class
            respondToInputEvent (KeyEvent (KeyPressed key)) ms = request
                env.stdout.write (show key ++ " + " ++ (show ms) ++ "\n")
                result Consumed
            respondToInputEvent _ _ = request
                result NotConsumed
            result RespondsToInputEvents{..})
            
        app.addWindow w1

    result action
        osx.startApplication start 