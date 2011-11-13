module Tutorial3TabResponder where

import COCOA
import CTButton
import CTLabel
import CTTextArea

root w = class
    osx = new cocoa w
    w1 = new mkCocoaWindow w
    
    start app = action
        w1.setPosition ({x=100;y=100})
        w1.setSize ({width=400;height=400}) 
        w1.setBackgroundColor web_gray
        w1.setTitle "Tutorial"        
        createComponentHierarchy -- Tutorial 1
        addTextArea              -- Tutorial 2
        replaceTabResponder      -- Tutorial 3
        app.addWindow w1

    -- Tutorial 1: Building a component hierarchy
    button = new mkCocoaButton w
    label = new mkCocoaLabel w
    leftContainer = new mkCocoaContainer w
    rightContainer = new mkCocoaContainer w
 
    createComponentHierarchy = do
        leftContainer.setSize ({width=200; height=200})
        leftContainer.setBackgroundColor ({r=100;g=100;b=200})
        leftContainer.setPosition ({x=0;y=0})

        rightContainer.setSize ({width=200; height=200})
        rightContainer.setBackgroundColor ({r=100;g=200;b=100})
        rightContainer.setPosition ({x=200; y=0})    

        button.setTitle "Click me!"
        button.setSize ({width=110;height=21})
        button.setPosition ({x=40; y=100})
        button.setClickResponder (new buttonHandler label)
        leftContainer.addComponent button

        label.setText "Click counter"
        label.setSize ({width=150; height=36})
        label.setPosition ({x=40; y=100})
        rightContainer.addComponent label

        w1.addComponent leftContainer
        w1.addComponent rightContainer

    -- Tutorial 2: Adding a text area that resizes when the window is resized
    ta = new mkCocoaTextArea w

    addTextArea = do
        ta.setSize ({width=300; height=80})
        ta.setPosition ({x=50; y=250})  
        ta.setDocumentSize ({width=400;height=800})
        w1.setWindowResponder (new windowResponder ta) False
        w1.addComponent ta

    -- Tutorial 3: Blocking TAB keys from changing focus away from the TextArea
    tabCountLabel = new mkCocoaLabel w

    replaceTabResponder = do
        tabCountLabel.setText "Tab counter"
        tabCountLabel.setSize ({width=150; height=36})
        tabCountLabel.setPosition ({x=40; y=70})
        ta.addResponder (new myTabResponder tabCountLabel)
        rightContainer.addComponent tabCountLabel

    result action
        osx.startApplication start 

-- Tutorial 1: Updating a label with a button click count
buttonHandler :: Label -> Class Action
buttonHandler label = class
    clickCount := 0
    result action
        clickCount := clickCount + 1
        label.setText ("Click #" ++ show clickCount)
                      
-- Tutorial 2: Resizing the TextArea when the window is resized
windowResponder :: TextArea -> Class RespondsToWindowEvents
windowResponder textarea = class
    onWindowResize size = request
        newWidth = floor ((fromInt size.width) * 0.8)
        newTaSize = {width=newWidth; height=80}        
        newX = floor ((fromInt size.width) * 0.1)
        newTaPosition = {x=newX; y=250}
        textarea.setSize newTaSize
        textarea.setPosition newTaPosition    
    onWindowCloseRequest = request
    result RespondsToWindowEvents {..}
    
-- Tutorial 3: Blocking TAB keys from changing focus away from the TextArea
myTabResponder :: Label -> Class RespondsToInputEvents
myTabResponder label = class
    tabCount := 0
    respondToInputEvent (KeyEvent (KeyPressed Tab)) _ = request	
        tabCount := tabCount + 1
        label.setText ("Tabs blocked #" ++ (show tabCount))
        result Consumed
    respondToInputEvent _ _ = request
        result NotConsumed
    result RespondsToInputEvents {..}