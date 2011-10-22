module Tutorial1ComponentsAndHierarchies where

import COCOA
import POSIX
import CTButton
import CTLabel

root w = class
    env = new posix w
    osx = new cocoa w
    
    w1 = new mkCocoaWindow env
    
    applicationDidFinishLaunching app = action                         
        w1.setSize ({width=400; height=400})    
        w1.setBackgroundColor ({r=200;g=200;b=200})
    
        createComponentHierarchy
        
        app.addWindow w1
        
        addButtonResponder
           
    label = new mkCocoaLabel
    button = new mkCocoaButton env
    
    createComponentHierarchy = do
        leftContainer = new mkCocoaContainer env 
        leftContainer.setSize ({width=200; height=200})
        leftContainer.setBackgroundColor ({r=100; b=0; g=0})
        leftContainer.setPosition ({x=0;y=0})

        rightContainer = new mkCocoaContainer env
        rightContainer.setSize ({width=200; height=200})
        rightContainer.setBackgroundColor ({r=0; b=100; g=0})
        rightContainer.setPosition ({x=200; y=0})    

        button.setTitle "Click me!"
        button.setSize ({width=110;height=21})
        button.setPosition ({x=40; y=100})

        label.setText "This is a label"
        label.setSize ({width=100; height=36})
        label.setPosition ({x=40; y=100})
        label.setTextColor ({r=80; b=140; g=90})

        leftContainer.addComponent button
        rightContainer.addComponent label

        w1.addComponent leftContainer
        w1.addComponent rightContainer

    addButtonResponder = do
        handler = new buttonHandler label
        button.addResponder handler

    result action
        osx.startApplication applicationDidFinishLaunching  
        
buttonHandler label = class
    clickCount := 0

    respondToInputEvent (MouseEvent event) modifiers = request
        -- here we will place the code for handling mouse events
        case event of
            MouseClicked pos ->
                clickCount := clickCount + 1
                label.setText ("Click #" ++ show clickCount)
                result True
            _ ->
                result False     
        
    respondToInputEvent _ modifiers = request
        result False

    
    result RespondsToInputEvents {..}        