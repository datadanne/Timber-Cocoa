module NewTest where

import COCOA
import EventHandler

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkCocoaWindow env
    c2 = new mkCocoaContainer env
    label = new mkCocoaLabel
    label2 = new mkCocoaLabel
    
    posget (MousePressed p) = p
    posget (MouseReleased p) = p
    posget (MouseClicked p) = p
    
    drawPixel app cid event = request
        pos = (posget event)
        
        after (millisec 50) send action
            w1.removeComponent label2
            s = new mkCocoaLabel
            label.setText ("Position: " ++ (show pos.x) ++ "," ++ (show pos.y))

            s.setSize ({width=300;height=50})
            s.setPosition ({x=pos.x;y=pos.y-20})
            s.setText ("X")
            --s.init app
            --containerAddComponent cid s.id
            --w1.addComponent s
        result True
     
    applicationDidFinishLaunching app = action
        app.addWindow w1


    result action
        label.setSize ({width=300;height=50})
        label.setPosition ({x=100;y=100})
        label.setText "Click to update position"

        w1.addComponent label
        w1.setPosition ({x=200;y=200})
        w1.setSize ({width=300;height=200})
        osx.startApplication applicationDidFinishLaunching