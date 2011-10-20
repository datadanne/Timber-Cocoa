module Tutorial4MultipleWindows where

import POSIX

import Tutorial4ColorPicker 
    
root w = class
    env = new posix w
    osx = new cocoa w    

    setColor color = request
        label.setTextColor color

    window = new mkWindow env
    labelWindow = new mkWindow env
    label = new mkCocoaLabel

    applicationDidFinishLaunching app = action
        app.showWindow window
        app.showWindow labelWindow
        app.setEnv env
        
        
    btnResponder window env = class
        toggle := True
        handleEvent (MouseEvent event) modifiers = request
            _ <- window.setVisible toggle
            toggle := not toggle
            result False
            
        result RespondsToInputEvents {..}
        
    result action
        osx.startApplication applicationDidFinishLaunching

        label.setSize ({width=205;height=20})
        label.setPosition ({x=20;y=40})
        label.setText "Currently selected color"
        
        labelWindow.addComponent label
        labelWindow.setSize ({width=200;height=200})
        env.stdout.write "hello\n"
        
        button = new mkCocoaButton env   
        button.setTitle "Open Colorpicker"
        button.addResponder (new btnResponder window env)
        labelWindow.addComponent button
        
        window.setSize ({width=205;height=205})
        window.setPosition ({x=100;y=100})
        window.setVisible False
        
        colorGrid = new colorPickerGrid window setColor env
        colorGrid.initGrid
        
