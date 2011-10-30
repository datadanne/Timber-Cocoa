module EventTest where

import DummyPOSIX
import COCOA
import CTLabel

root w = class
    env = new dummyPosix w
    osx = new cocoa w

    w1 = new mkCocoaWindow
    c2 = new mkCocoaContainer
    label = new mkCocoaLabel
    
    posget (MousePressed p) = p
    posget (MouseReleased p) = p
    posget (MouseClicked p) = p
    
    drawPixel c2 event = request
        pos = (posget event)
        label.setText ("Position: " ++ (show pos.x) ++ "," ++ (show pos.y))
        result True
     
    applicationDidFinishLaunching app = action
        app.setEnv env
        app.addWindow w1
    
    result action
        label.setSize ({width=300;height=50})
        label.setPosition ({x=100;y=100})
        label.setText "Click to update position"

        c2.addComponent label
        w1.addComponent c2
        w1.installMouseListener (drawPixel c2)
        w1.setPosition ({x=200;y=200})
        w1.setSize ({width=300;height=200})
        osx.startApplication applicationDidFinishLaunching