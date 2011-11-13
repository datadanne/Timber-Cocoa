module TestScrolling where

import POSIX
import COCOA
import CTTextArea
import CTTextField

root w = class
    env = new posix w
    osx = new cocoa w
    w1  = new mkCocoaWindow w
    textField = new mkCocoaTextField w
    textArea  = new mkCocoaTextArea w

    start app = action  
        w1.setPosition ({x=100;y=100})   
        w1.setSize ({width=400;height=400})
        w1.setBackgroundColor web_gray
        w1.setTitle "TestScrolling"   

        textField.setPosition ({x=100;y=50})
        textField.setSize ({width=100;height=50})
        textField.setText "Text field"
        w1.addComponent textField   

        textArea.setPosition ({x=100;y=100})               
        textArea.setSize ({width=200;height=200})
        textArea.setDocumentSize ({width=300;height=300})
        textArea.setText "Text area"
        w1.addComponent textArea   
        
        app.addWindow w1        
    
    result action
        osx.startApplication start
