module Paint where

import DummyPOSIX
import COCOA
import CTLabel

paintHandler w1 label env = class
    pixelCount := 0
    
    posget (MousePressed p) = p
    posget (MouseReleased p) = p
    posget (MouseClicked p) = p

    handleEvent (MouseEvent event) modifiers = request
        pos = (posget event)
    
        env.stdout.write "Painting box\n"
        label.setText ("Pixel Count: " ++ show pixelCount)
        --label.setText ("Position: " ++ (show pos.x) ++ "," ++ (show pos.y))
        
        blackBox = new mkCocoaContainer env
        blackBox.setSize ({width=7;height=27})
        blackBox.setBackgroundColor({r=pos.x `mod` 255;g=pos.y `mod` 255;b=2*(pos.y-pos.x) `mod` 255}) 
        blackBox.setPosition pos
        w1.addComponent blackBox

        pixelCount := 1 + pixelCount
        result False
        
    handleEvent _ modifiers = request
        result False
        
    result RespondsToInputEvents {..}

root w = class
    env = new dummyPosix w
    osx = new cocoa w

    w1 = new mkWindow env
    c2 = new mkCocoaContainer env
    label = new mkCocoaLabel

    painter = new paintHandler w1 label env

    applicationDidFinishLaunching app = action
        app.setEnv env
        app.showWindow w1
        c2.addComponent label
    
    result action
        label.setSize ({width=300;height=50})
        label.setPosition ({x=50;y=200})
        label.setText "PainT_Timber"
        c2.setSize ({width=500;height=500})
        c2.setBackgroundColor ({r=100;g=150;b=150})
        --c2.addComponent label
       -- w1.addComponent c2
        w1.addComponent label
        w1.addHandler painter
        w1.setSize ({width=500;height=500})

        osx.startApplication applicationDidFinishLaunching