module TestFocusHierarchy where

import POSIX
import COCOA
import CTButton

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkCocoaWindow env
    c2 = new mkCocoaContainer env
    
    
    button := new mkCocoaButton env 
    i := 0
    positions = [(200, 100), (170, 120), (140, 140), (110, 160), (80, 180), (50, 200), (80, 220), (110, 240), (140, 260), (170, 280), (200, 300), (230, 280), (260, 260), (290, 240), (320, 220), (350, 200), (320, 180), (290, 160), (260, 140), (230, 120)]    
    
    generateButtons = do
        i := 1
        forall (xcord, ycord) <- positions do
            button := new mkCocoaButton env

            button.setName ("Button" ++ (show i))
            button.setTitle ("Button" ++ (show i))
            button.setPosition ({x=xcord;y=ycord})
            w1.addComponent button                
            i := i + 1
            
    
    applicationDidFinishLaunching app = action                         
        app.addWindow w1
        app.setEnv env  
        _ <- generateButtons
        
    result action
        w1.setSize ({width=500;height=500})  
        osx.startApplication applicationDidFinishLaunching