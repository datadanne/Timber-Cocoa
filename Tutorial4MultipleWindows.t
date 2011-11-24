module Tutorial4MultipleWindows where

import COCOA
import CTButton
import CTLabel
import CTTextArea
import Tutorial4ColorPicker 

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
        addColorPicker app       -- Tutorial 4
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

    -- Tutorial 4: Color grid
    rgbLabel    = new mkCocoaLabel w
    colorButton = new mkCocoaButton w
    colorWindow = new mkColorPicker w setColor

    setColor color = action
        rgbLabel.setText (show color ++ "\n") 
        leftContainer.setBackgroundColor color

    addColorPicker app = do        
        rgbLabel.setText "R=100; G=100; B=200"
        rgbLabel.setSize ({width=150; height=36})
        rgbLabel.setPosition ({x=40; y=40})
        rightContainer.addComponent rgbLabel
         
        colorButton.setTitle "Open ColorPicker"
        colorButton.setSize ({width=150;height=21})
        colorButton.setPosition ({x=40; y=75})
        colorButton.setClickResponder 
            (new mkColorToggle colorWindow colorButton)
        leftContainer.addComponent colorButton

        colorWindow.setPosition ({x=500;y=100})
        app.addWindow colorWindow

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
    
-- Tutorial 4: Opening/closing a window when a button is clicked
mkColorToggle :: CocoaWindow -> Button -> Class Action
mkColorToggle window button = class 
    toggle := True
    result action
        window.setVisible toggle
        button.setTitle 
            (if toggle then "Open ColorPicker" else "Close ColorPicker")
        toggle := not toggle