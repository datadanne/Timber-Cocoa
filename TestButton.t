module TestButton where

import POSIX
import COCOA
import CTButton

root :: RootType
root w = class
    osx = new cocoa w
    w1 = new mkCocoaWindow w
    button1 = new mkCocoaButton w
    button2 = new mkCocoaButton w
    
    start app = action   
        w1.setPosition ({x=100;y=100})
        w1.setSize ({width=400;height=300})
        w1.setTitle "TestButton"
        w1.setBackgroundColor ({r=100;b=0;g=130})

        button1.setTitle "I am button 1"
        button1.setPosition ({x=100;y=100})
        button1.addResponder (new buttonClickHandler button2)
        w1.addComponent button1
        
        button2.setName "button2"
        button2.setTitle "I am button 2"
        button2.setPosition ({x=100;y=130})
        w1.addComponent button2     
                         
        app.addWindow w1
        
    result action
        osx.startApplication start
        
buttonClickHandler otherButton = class
    respondToInputEvent (MouseEvent (MouseClicked _)) _ = request
        otherButton.setSize ({width=200;height=150})
        result Consumed                    
    respondToInputEvent _ _ = request 
        result NotConsumed
    result RespondsToInputEvents {..}