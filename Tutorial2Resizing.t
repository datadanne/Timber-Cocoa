module Tutorial2Resizing where

import COCOA
import POSIX

import CTWindow 
root w = class
    env = new posix w
    osx = new cocoa w

    applicationDidFinishLaunching app = action                         
        w1 = new mkCocoaWindow env
        w1.setSize ({width=400; height=400})
      	
        leftContainer = new mkCocoaContainer env 
        leftContainer.setSize ({width=200; height=200})
        leftContainer.setBackgroundColor ({r=100; b=0; g=0})
        leftContainer.setPosition ({x=0;y=0})

        rightContainer = new mkCocoaContainer env
        rightContainer.setSize ({width=200; height=200})
        rightContainer.setBackgroundColor ({r=0; b=100; g=0})
        rightContainer.setPosition ({x=200; y=0})    
    
        button = new mkCocoaButton env
        button.setTitle "Click me!"
        button.setSize ({width=110;height=21})
        button.setPosition ({x=40; y=100})
    
        label = new mkCocoaLabel
        label.setText "This is a label"
        label.setSize ({width=100; height=36})
        label.setPosition ({x=40; y=100})
        label.setTextColor ({r=80; b=140; g=90})
    
        leftContainer.addComponent button
        rightContainer.addComponent label
       
        w1.addComponent leftContainer
        w1.addComponent rightContainer

        app.showWindow w1  
        
        handler = new buttonHandler label
        button.addResponder handler     
        
        ta = new mkCocoaTextArea env
        ta.setSize ({width=300; height=80})
        ta.setPosition ({x=50; y=250})  
       
        w1.addComponent ta
        
        windowResponderObj = new windowResponder ta env
        w1.setWindowResponder windowResponderObj     

    result action
        osx.startApplication applicationDidFinishLaunching  
                       
windowResponder :: TextArea -> POSIX.Env -> Class RespondsToWindowEvents
windowResponder textarea env = class
    onWindowResize size modifiers = request

        newWidth = floor ((fromInt size.width) * 0.8)
        newTaSize = {width=newWidth; height=80}
        
        newX = floor ((fromInt size.width) * 0.1)
        newTaPosition = {x=newX; y=250}

        textarea.setSize newTaSize
        textarea.setPosition newTaPosition
        result ()
    
    onWindowCloseRequest _ = request
        result True

    setWindowResponder responder = request 
    
    result RespondsToWindowEvents {..}
                
buttonHandler label = class
    clickCount := 0

    handleEvent (MouseEvent event) modifiers = request
        -- here we will place the code for handling mouse events
        case event of
            MouseClicked pos ->
                clickCount := clickCount + 1
                label.setText ("Click #" ++ show clickCount)
                result True
            _ ->
                result False     
        
    handleEvent _ modifiers = request
        result False
    
    result RespondsToInputEvents {..}        