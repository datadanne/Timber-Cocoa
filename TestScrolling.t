module TestScrolling where

import POSIX
import COCOA
import CTTextArea
import CTTextField

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkCocoaWindow w
    textArea = new mkCocoaTextArea w
    textField = new mkCocoaTextField w
    
    start app = action  
        w1.setPosition ({x=100;y=100})   
        w1.setSize ({width=400;height=400})
        w1.setTitle "TestScrolling"    
        w1.setBackgroundColor ({r=100;b=0;g=130})                                  

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
