module Tutorial1CompHierarchy where

import POSIX
import COCOA
import CTButton
import CTLabel

root w = class
    env = new posix w
    osx = new cocoa w
    label = new mkCocoaLabel w
    button = new mkCocoaButton w
    w1 = new mkCocoaWindow w
    
    start app = action                         
        w1.setPosition({x=100;y=100})
        w1.setSize ({width=400; height=400})    
        w1.setBackgroundColor ({r=200;g=200;b=200})
    	w1.setTitle "Tutorial"
        createComponentHierarchy
        app.addWindow w1
    
    createComponentHierarchy = do
        leftContainer = new mkCocoaContainer w
        leftContainer.setSize ({width=200; height=200})
        leftContainer.setBackgroundColor ({r=100; b=0; g=0})
        leftContainer.setPosition ({x=0;y=0})

        rightContainer = new mkCocoaContainer w
        rightContainer.setSize ({width=200; height=200})
        rightContainer.setBackgroundColor ({r=0; b=100; g=0})
        rightContainer.setPosition ({x=200; y=0})    

        button.setTitle "Click me!"
        button.setSize ({width=110;height=21})
        button.setPosition ({x=40; y=100})
        button.addResponder (new eventHandler isMouseClicked label.setText "Button clicked ")

        label.setText "This is a label"
        label.setSize ({width=100; height=36})
        label.setPosition ({x=40; y=100})
        label.setTextColor ({r=80; b=140; g=90})
        -- label.setBackground ({}) red
        label.addResponder (new eventHandler isMouseMoved env.stdout.write "Mouse moved ")

        leftContainer.addComponent button
        rightContainer.addComponent label

        w1.addComponent leftContainer
        w1.addComponent rightContainer

    result action
        osx.startApplication start      

isMouseClicked (MouseEvent (MouseClicked _)) = True
isMouseClicked _ = False

isMouseMoved (MouseEvent (MouseMoved _)) = True
isMouseMoved _ = False

eventHandler test write s = class
    clickCount := 0
    respondToInputEvent e _ = request
        if (test e) then
            clickCount := clickCount + 1
            write (s ++ show clickCount ++ "\n")
            result Consumed   
        else
            result NotConsumed
    result RespondsToInputEvents {..}  