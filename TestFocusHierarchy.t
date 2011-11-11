module TestFocusHierarchy where

import POSIX
import COCOA
import CTButton

positions = [(200, 100), (140, 140), (80, 180), (80, 220), (140, 260), 
    (200, 300), (260, 260), (320, 220), (320, 180), (260, 140)]

root :: RootType
root w = class
    osx = new cocoa w
    w1 = new mkCocoaWindow w
    c2 = new mkCocoaContainer w

    start app = action  
        w1.setPosition ({x=100;y=100})   
        w1.setSize ({width=500;height=500})
        w1.setTitle "TestFocusHierarchy"    
        w1.setBackgroundColor ({r=100;b=0;g=130}) 
        
        forall ((xcord,ycord),i) <- zip positions [1 .. length positions] do
            button = new mkCocoaButton w
            button.setName ("Button" ++ (show i))
            button.setTitle ("Button" ++ (show i))
            button.setPosition ({x=xcord;y=ycord})
            w1.addComponent button         

        app.addWindow w1 
       
    result action
        osx.startApplication start