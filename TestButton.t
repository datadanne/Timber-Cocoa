module TestButton where

import COCOA
import CTButton

root w = class
    osx = new cocoa w
    w1  = new mkCocoaWindow w
    button1 = new mkCocoaButton w
    button2 = new mkCocoaButton w

    start app = action
        w1.setPosition ({x=100;y=100})
        w1.setSize ({width=400;height=400}) 
        w1.setBackgroundColor web_gray
        w1.setTitle "TestButton"

        button1.setTitle "I am button 1"
        button1.setPosition ({x=100;y=100})
        button1.setClickResponder (new buttonClickHandler button2)
        w1.addComponent button1

        button2.setTitle "I am button 2"
        button2.setPosition ({x=100;y=130})
        w1.addComponent button2     
                         
        app.addWindow w1
        
    result action
        osx.startApplication start
        
buttonClickHandler otherButton = class
    result action otherButton.setSize ({width=200;height=150})
