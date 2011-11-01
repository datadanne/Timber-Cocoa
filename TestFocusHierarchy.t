module TestFocusHierarchy where

import POSIX
import COCOA
import CTWindow
import CTButton

positions = [(200, 100), (170, 120), (140, 140), (110, 160), (80, 180), 
    (50, 200), (80, 220), (110, 240), (140, 260), (170, 280), (200, 300), 
    (230, 280), (260, 260), (290, 240), (320, 220), (350, 200), (320, 180), 
    (290, 160), (260, 140), (230, 120)]

root :: RootType
root w = class
    osx = new cocoa w
    w1 = new mkCocoaWindow w
    c2 = new mkCocoaContainer w

    start app = action                         
        app.addWindow w1
        forall ((xcord,ycord),i) <- zip positions [1 .. length positions] do
            button = new mkCocoaButton w
            button.setName ("Button" ++ (show i))
            button.setTitle ("Button" ++ (show i))
            button.setPosition ({x=xcord;y=ycord})
            w1.addComponent button                

    result action
        w1.setSize ({width=500;height=500})  
        osx.startApplication start