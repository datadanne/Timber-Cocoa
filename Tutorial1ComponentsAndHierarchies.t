module Tutorial1ComponentsAndHierarchies where

import POSIX
import COCOA
import CTButton
import CTLabel

root :: RootType
root w = class
    env = new posix w
    osx = new cocoa w
    w1 = new mkCocoaWindow w
    label = new mkCocoaLabel w
    button = new mkCocoaButton w
    
    start app = action                         
        w1.setSize ({width=400; height=400})    
        w1.setBackgroundColor ({r=200;g=200;b=200})
        createComponentHierarchy
        app.addWindow w1
        addButtonResponder
    
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

        label.setText "This is a label"
        label.setSize ({width=100; height=36})
        label.setPosition ({x=40; y=100})
        label.setTextColor ({r=80; b=140; g=90})

        leftContainer.addComponent button
        rightContainer.addComponent label

        w1.addComponent leftContainer
        w1.addComponent rightContainer

    addButtonResponder = do
        handler = new buttonHandler label env
        button.addResponder handler

    result action
        osx.startApplication start  
        
buttonHandler label env = class
    clickCount := 0

    respondToInputEvent (MouseEvent event) modifiers = request
        -- here we will place the code for handling mouse events
        case event of
            MouseClicked pos ->
                clickCount := clickCount + 1
                label.setText ("Click #" ++ show clickCount)
                result True
            MousePressed pos ->
                env.stdout.write "Mouse PressEvent Received\n"
                result True
            MouseReleased pos -> 
                env.stdout.write "REALESED\n"
                result True

            MouseMoved pos ->
                env.stdout.write "mousemoved\n"
                result True
            MouseWheelScroll pos x y -> 
                env.stdout.write "hello\n"
                result True
            _ ->
                env.stdout.write "Mouse Event Received\n"
                result False     

    respondToInputEvent _ modifiers = request
        result False

    result RespondsToInputEvents {..}        