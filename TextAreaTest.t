module TextAreaTest where

import DummyPOSIX
import COCOA
import CTLabel

root w = class
    env = new dummyPosix w
    osx = new cocoa w

    w1 = new mkWindow env
    c2 = new mkCocoaContainer env
    label = new mkCocoaLabel
    tarea = new mkCocoaTextArea env
    
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
        
        toSize = {width=167;height=133}
        foo = ResultSize toSize
        
        after (sec 5) send action
            w1.setSize ({width=500;height=500})
            tarea.setSize ({width=300;height=5}) -- DOESNT WORK. Anchors to right edge?
            tarea.setPosition ({x=100;y=100})
            tarea.setScrollable (True, False)
            
    
    result action
        tarea.setSize ({width=200;height=100})
        tarea.setPosition ({x=0;y=50})
        tarea.setText "Here be text and scrolling\n\n\nLine breaks work too.\n\n\nEND OF TEXT"
        tarea.setScrollable (False, True)
        w1.addComponent tarea
        w1.addComponent label
        w1.setBackgroundColor ({r=100;g=200;b=100})
        w1.installMouseListener (drawPixel c2)
        w1.setPosition ({x=200;y=200})
        w1.setSize ({width=300;height=200})
        label.setSize ({width=300;height=20})
        label.setPosition ({x=0;y=0})
        osx.startApplication applicationDidFinishLaunching