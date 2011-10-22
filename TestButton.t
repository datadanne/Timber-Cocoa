module TestButton where

import POSIX
import COCOA
import CTButton

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkCocoaWindow env
    c2 = new mkCocoaContainer env
    button = new mkCocoaButton env
    button2 = new mkCocoaButton env
    
    applicationDidFinishLaunching app = action                         
        app.addWindow w1
        app.setEnv env
    
        
    result action
        w1.setSize ({width=500;height=500})
        button.setName "button1"
        button.setTitle "I am button 1"
        button.setPosition ({x=100;y=100})
        button.addResponder (new buttonClickHandler button2)
        --button.setSize ({width=200; height=80})
        w1.addComponent button
        
        button2.setName "button2"
        button2.setTitle "I am button 2"
        button2.setPosition ({x=100;y=130})
        w1.addComponent button2
        
        osx.startApplication applicationDidFinishLaunching
        
buttonClickHandler btn = class
    respondToInputEvent (MouseEvent ev) modifiers = request
        case ev of
            MouseClicked pos ->
                btn.setSize ({width=200;height=150})
                result True
            _ ->
                result False
            
    respondToInputEvent _ _ = request 
        result False
    
    result RespondsToInputEvents {..}