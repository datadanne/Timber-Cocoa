module Tutorial5ComponentCreation where

import POSIX

import Tutorial4ColorPicker 
import Tutorial5CallbackLabel
import CTButton
import CTLabel
import CTTextArea

root w = class
    env = new posix w
    osx = new cocoa w
    
    w1 = new mkCocoaWindow
    colorWindow = new mkCocoaWindow
    
    start app = action
        w1.setSize ({width=400;height=400}) 
        w1.setBackgroundColor ({r=200;g=200;b=200})

        createComponentHierarchy
        addColorPicker
        
        app.addWindow w1
        app.addWindow colorWindow

        addButtonResponder
        addWindowResponder
        setUpCallbacks

    label = new mkCocoaCallbackLabel            -- note! this labels have been updated to
    tabCountLabel = new mkCocoaCallbackLabel    -- be callback-labels
    button = new mkCocoaButton
    leftContainer = new mkCocoaContainer 
    rightContainer = new mkCocoaContainer 
    callbackLabel = new mkCocoaLabel
    
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
        button.addResponder handler

    ta = new mkCocoaTextArea

    addWindowResponder = do
        ta.setSize ({width=300; height=80})
        ta.setPosition ({x=50; y=250})  
        ta.setScrollable (True,True)

        w1.addComponent ta

        windowResponderObj = new windowResponder ta env
        w1.setWindowResponder windowResponderObj False
        replaceTabResponder

   -- Tutorial 3 : Consume tab event in text area.
    replaceTabResponder = do
        tabResponder = new myTabResponder tabCountLabel
        ta.setResponders [tabResponder]

    -- Tutorial 4 : Add a color picker window
    rgbLabel = new mkCocoaLabel

    setColor color = request
        rgbLabel.setText ("R:" ++ (show (color.r)) ++ " G: " ++ (show (color.g)) ++ " B: " ++ (show (color.b)) ++ "\n") 
        leftContainer.setBackgroundColor color

    addColorPicker = do
        rgbLabel.setText "R: 0; G=0; B=0"
        rgbLabel.setSize ({width=150; height=36})
        rgbLabel.setPosition ({x=40; y=40})
        rightContainer.addComponent rgbLabel
        
        colorButton = new mkCocoaButton   
        colorButton.setTitle "Open ColorPicker"
        colorButton.setSize ({width=150;height=21})
        colorButton.setPosition ({x=40; y=75})
        colorButton.addResponder (new colorPickerToggle colorButton colorWindow env)
        leftContainer.addComponent colorButton
        
        colorWindow.setSize ({width=215;height=215})
        colorWindow.setPosition ({x=445;y=300})
        colorWindow.setVisible False
        colorWindow.setResizable False
        colorWindow.setWindowResponder (new class
            onWindowResize s = request
            onWindowCloseRequest = request
                result False
            result RespondsToWindowEvents{..}) True
        
        initColorGrid = new colorPickerGrid colorWindow setColor env
        initColorGrid
        
    -- Tutorial 5 : Adding a new label and set up callbacks
    setUpCallbacks = do                       
        callbackLabel.setSize ({width=150; height=36})
        callbackLabel.setPosition ({x=40; y=10})    
        callbackLabel.setText "Callback label"
        rightContainer.addComponent callbackLabel
        
        label.installOnTextChangeCallback textChangeCallback
        tabCountLabel.installOnTextChangeCallback textChangeCallback
        
    textChangeCallback newText = action
        callbackLabel.setText ("CB: " ++ newText)

    result action
        osx.startApplication start  

-- Tutorial 2 : Responder for button click
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
        result True

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
        result True

    respondToInputEvent _ modifiers = request
        result False

    result RespondsToInputEvents {..}

-- Tutorial4 : Responder to toggle visibility the color picker window 
colorPickerToggle this window env = class
    toggle := True
    respondToInputEvent (MouseEvent event) modifiers = request
        _ <- window.setVisible toggle
        send action this.setTitle ((if (toggle) then "Open" else "Close") ++ " ColorPicker")
        
        toggle := not toggle
        result False
        
    respondToInputEvent _ _ = request
        result False
        
    result RespondsToInputEvents {..}
        
