module DropTest where

import COCOA

root w = class
    env = new posix w
    osx = new cocoa w
    
    w1 = new mkWindow env
    dropD = new mkCocoaDropDown env
    
    applicationDidFinishLaunching app = action            

        --zuperEvent = (SelectionEvent (SelectedItem "thisISmadness"))
                 
        app.showWindow w1
        app.setEnv env
        
    doNothing event = request
        env.stdout.write "MOUSE CLICK"
        result True
    
    dropDownHandler str = request
        env.stdout.write ("dropdown selected " ++ str)
        result True

    result action
        w1.setSize ({width=700;height=500})
        w1.setPosition ({x=0;y=0})                                         
        
        --test = MouseEvent (MouseWheelScroll ({x=100;y=200}) 0.1 1.0)
       
        dropD.setSize ({width=300;height=300})
        dropD.setPosition ({x=100;y=100})  
        
        dropD.setOptions ["Test", "ing", "DropDown"]  
        
--        dropD.installSelectionListener dropDownHandler 
--        dropD.installMouseListener doNothing
        
        w1.addComponent dropD
        w1.setBackgroundColor ({r=100;b=0;g=130})
        osx.startApplication applicationDidFinishLaunching          