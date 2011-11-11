module Tutorial5CompCreation where

import POSIX

import Tutorial4ColorPicker 
import CTButton
import CTLabel
import CTTextArea

root w = class
    env = new posix w
    osx = new cocoa w
    
    w1 = new mkCocoaWindow w
    
    start app = action
        w1.setPosition ({x=100;y=100})
        w1.setSize ({width=400;height=400}) 
        w1.setBackgroundColor cyan
        w1.setTitle "Tutorial"

        createComponentHierarchy
        addColorPicker app
        
        app.addWindow w1

        addButtonResponder
        addWindowResponder
        setUpCallbacks
    
    -- these two labels have been updated to callback-labels
    label = new mkCocoaCallbackLabel (mkCocoaLabel w) textChangeCallback 
    tabCountLabel = new mkCocoaCallbackLabel (mkCocoaLabel w) textChangeCallback
    
    button = new mkCocoaButton w
    leftContainer = new mkCocoaContainer w
    rightContainer = new mkCocoaContainer w
    callbackLabel = new mkCocoaLabel w
    
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

        label.setText "Click counter"
        label.setSize ({width=150; height=36})
        label.setPosition ({x=40; y=100})
        
        tabCountLabel.setText "TextArea Tab counter"
        tabCountLabel.setSize ({width=150; height=36})
        tabCountLabel.setPosition ({x=40; y=70})

        leftContainer.addComponent button
        rightContainer.addComponent label
        rightContainer.addComponent tabCountLabel

        w1.addComponent leftContainer
        w1.addComponent rightContainer

    -- Tutorial 2 : Respond to button clicks. Add a text area
    addButtonResponder = do
        handler = new buttonHandler label
        button.setClickResponder handler

    ta = new mkCocoaTextArea w

    addWindowResponder = do
        ta.setSize ({width=300; height=80})
        ta.setPosition ({x=50; y=250})  
        ta.setDocumentSize ({width=400;height=800})
        w1.addComponent ta

        windowResponderObj = new windowResponder ta env
        w1.setWindowResponder windowResponderObj False
        replaceTabResponder

   -- Tutorial 3 : Consume tab event in text area.
    replaceTabResponder = do
        tabResponder = new myTabResponder tabCountLabel
        ta.setResponders [tabResponder]

    -- Tutorial 4 : Add a color picker window
    rgbLabel    = new mkCocoaLabel w
    colorButton = new mkCocoaButton w 
    colorWindow = new mkColorPicker w setColor

    setColor color = action
        rgbLabel.setText (show color) 
        leftContainer.setBackgroundColor color

    addColorPicker app = do        
        rgbLabel.setText "R: 100; G=100; B=200"
        rgbLabel.setSize ({width=150; height=36})
        rgbLabel.setPosition ({x=40; y=40})
        rightContainer.addComponent rgbLabel
         
        colorButton.setTitle "Open ColorPicker"
        colorButton.setSize ({width=150;height=21})
        colorButton.setPosition ({x=40; y=75})
        colorButton.setClickResponder (new mkColorToggle colorWindow colorButton)
        leftContainer.addComponent colorButton

        colorWindow.setPosition ({x=500;y=0})
        app.addWindow colorWindow
                        
    -- Tutorial 5 : Adding a new label and setting up callbacks
    setUpCallbacks = do                       
        callbackLabel.setSize ({width=150; height=36})
        callbackLabel.setPosition ({x=40; y=10})    
        callbackLabel.setText "Callback label"
        rightContainer.addComponent callbackLabel
                
    textChangeCallback newText = action
        callbackLabel.setText ("CB: " ++ newText)

    result action
        osx.startApplication start 

-- Tutorial 4
mkColorToggle colorWindow colorButton = class 
    toggle := True
    result action
        colorWindow.setVisible toggle
        colorButton.setTitle 
            (if toggle then "Open ColorPicker" else "Close ColorPicker")
        toggle := not toggle

instance showColor :: Show Color where
    show c =  "R: " ++ (show c.r) ++ 
             " G: " ++ (show c.g) ++ 
             " B: " ++ (show c.b) ++ "\n"

-- Tutorial 2 : Responder for button click
buttonHandler label = class
    clickCount := 0
    result action
        clickCount := clickCount + 1
        label.setText ("Click #" ++ show clickCount)
                      
-- Tutorial 2 : Responder to resize a component on window resize 
windowResponder :: TextArea -> POSIX.Env -> Class RespondsToWindowEvents
windowResponder textarea env = class
    onWindowResize size = request

        newWidth = floor ((fromInt size.width) * 0.8)
        newTaSize = {width=newWidth; height=80}
        
        newX = floor ((fromInt size.width) * 0.1)
        newTaPosition = {x=newX; y=250}

        textarea.setSize newTaSize
        textarea.setPosition newTaPosition
        result ()
    
    onWindowCloseRequest = request

    result RespondsToWindowEvents {..}
    
-- Tutorial 3 : Responder to overload TAB key
myTabResponder label = class
    tabCount := 0
    
    getKey (KeyPressed  key) = key
    getKey (KeyReleased key) = key
    getKey _ = raise 9

    respondToInputEvent (KeyEvent (KeyPressed key)) modifiers = request	
        if (key == Tab) then
            tabCount := tabCount + 1
            label.setText ("Tabs blocked #" ++ (show tabCount))
        result Consumed

    respondToInputEvent _ modifiers = request
        result NotConsumed

    result RespondsToInputEvents {..}
    
-- Tutorial 5: Customized label
mkCocoaCallbackLabel :: (Class Label) -> (String->Action) -> Class Label
mkCocoaCallbackLabel mkLabel cb = class
    Label {setText=setTextImpl;appendText=appendTextImpl;id=idImpl;..} = new mkLabel
    setText s = request
        setTextImpl s
        send cb s
    appendText s = request
        appendTextImpl s
        send cb (<- getText)
    result Label{id=self;..}
        
