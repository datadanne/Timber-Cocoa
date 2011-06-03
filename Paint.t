module Paint where

import POSIX
import COCOA
import CTLabel

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkWindow env
    c2 = new mkContainer env
    button = new mkCocoaButton env
    button2 = new mkCocoaButton env
    label = new mkCocoaLabel
    
    posget (MousePressed p) = p
    posget (MouseReleased p) = p
    posget (MouseClicked p) = p
    
    pixelCount := 0
    
    drawPixel c2 event = request
        --env.stdout.write "Painting box\n"
        blackBox = new mkContainer env
        blackBox.setSize ({width=5;height=5})
        label.setText ("Pixel Count: " ++ show pixelCount)
        pos = (posget event)
        blackBox.setBackgroundColor({r=pos.x `mod` 255;g=pos.y `mod` 255;b=2*(pos.y-pos.x) `mod` 255}) 
        blackBox.setPosition pos
        --env.stdout.write ("Position is: " ++ (show pos.x) ++ "," ++ (show pos.y) ++ "\n")
        
        pixelCount := 1 + pixelCount
        
        after (millisec 100) send action
            w1.addComponent blackBox
        result True
     
    applicationDidFinishLaunching app = action
        app.setEnv env
        app.showWindow w1
    
    result action
        label.setSize ({width=300;height=50})
        label.setPosition ({x=50;y=200})
        label.setText "PainTimber. Paint slowly or I will segfault. :("

        w1.addComponent label
        w1.installMouseListener (drawPixel c2)

        osx.startApplication applicationDidFinishLaunching