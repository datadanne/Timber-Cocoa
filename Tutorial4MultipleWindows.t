module Tutorial4MultipleWindows where

import POSIX

import Tutorial4ColorPicker 
    
root w = class
    env = new posix w
    osx = new cocoa w    

    window = new mkCocoaWindow env
    labelWindow = new mkCocoaWindow env
    label = new mkCocoaLabel
    box = new mkCocoaContainer env

    applicationDidFinishLaunching app = action
        app.addWindow window
        app.addWindow labelWindow
        app.setEnv env
        
    btnResponder window env = class
        toggle := True
        respondToInputEvent (MouseEvent event) modifiers = request
            _ <- window.setVisible toggle
            toggle := not toggle
            result False
            
        result RespondsToInputEvents {..}
        
    setColor color = action
        label.setTextColor color
        box.setBackgroundColor color
        
    result action
        osx.startApplication applicationDidFinishLaunching

        label.setSize ({width=205;height=20})
        label.setPosition ({x=20;y=60})
        label.setText "Currently selected color"
        
        labelWindow.addComponent label
        labelWindow.setSize ({width=200;height=200})
        labelWindow.setPosition ({x=200;y=150})
        env.stdout.write "hello\n"
        
        button = new mkCocoaButton env   
        button.setTitle "Colorpicker"
        button.setPosition ({x=20;y=20})
        button.addResponder (new btnResponder window env)
        labelWindow.addComponent button
        
        window.setSize ({width=205;height=205})
        window.setPosition ({x=430;y=300})
        window.setVisible False
        
        box.setSize ({width=64;height=64})
        box.setPosition ({x=80;y=100})
        box.setBackgroundColor ({r=100;g=50;b=255})
        labelWindow.addComponent box
        
        colorGrid = new colorPickerGrid window setColor env
        colorGrid.initGrid
        
