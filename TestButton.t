module TestButton where

import POSIX
import COCOA
import CTButton

root :: RootType
root w = class
    osx = new cocoa w
    w1 = new mkCocoaWindow w
    c2 = new mkCocoaContainer w
    button1 = new mkCocoaButton w
    button2 = new mkCocoaButton w
    
    start app = action                         
        app.addWindow w1
        
    result action
        w1.setSize ({width=500;height=500})

        button1.setName "button1"
        button1.setTitle "I am button 1"
        button1.setPosition ({x=100;y=100})
        button1.addResponder (new buttonClickHandler button2)
        w1.addComponent button1
        
        button2.setName "button2"
        button2.setTitle "I am button 2"
        button2.setPosition ({x=100;y=130})
        w1.addComponent button2
        
        osx.startApplication start
        
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