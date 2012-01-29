module TestFocusHierarchy where

import COCOA
import CTButton

positions = [(200, 40), (160, 70), (120, 100), (80, 130), (40, 160), 
    (0, 190), (40, 220), (80, 250), (120, 280), (160, 310), (200, 340), 
    (240, 310), (280, 280), (310, 250), (360, 220), (400, 190), (360, 160), 
    (310, 130), (280, 100), (240, 70)]

root w = class
    osx = new cocoa w
    w1  = new mkCocoaWindow w
    c2  = new mkCocoaContainer w

    start app = action
        w1.setPosition ({x=100,y=100})
        w1.setSize ({width=490,height=460}) 
        w1.setBackgroundColor web_gray
        w1.setTitle "TestFocusHierarchy"   
        forall ((xcord,ycord),i) <- zip positions [1.. length positions] do
            button = new mkCocoaButton w
            button.setName ("Button" ++ (show i))
            button.setTitle ("Button" ++ (show i))
            button.setPosition ({x=xcord,y=ycord})
            w1.addComponent button   
        app.addWindow w1       

    result action
        osx.startApplication start