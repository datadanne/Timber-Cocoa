module TestDropDown where

import CTWindow
import CTDropDown

root w = class
    env = new posix w
    osx = new cocoa w
    
    w1 = new mkCocoaWindow env
    dropD = new mkCocoaDropDown env

    applicationDidFinishLaunching app = action                         
        app.addWindow w1
        
    f := []
    result action
        w1.setSize ({width=700;height=500})
        w1.setPosition ({x=0;y=0})                                         
        
        dropD.setSize ({width=300;height=300})
        dropD.setPosition ({x=100;y=100})  
        dropD.setOptions ["Test", "ing", "DropDown"]
        
        dropD.setSelectionResponder (new defaultSelectionResponder env)
        
        w1.addComponent dropD
        w1.setBackgroundColor ({r=100;b=0;g=130})

        osx.startApplication applicationDidFinishLaunching

defaultSelectionResponder env = class
    selectionChanged str = action
        env.stdout.write ("selection changed to: " ++ str ++ "\n")
        
    setSelectionResponder _ = request -- not used
    
    result RespondsToSelectionEvents {..}
                  
