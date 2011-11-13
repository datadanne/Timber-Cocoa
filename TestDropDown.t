module TestDropDown where

import POSIX
import COCOA
import CTDropDown

root :: RootType
root w = class
    env = new posix w
    osx = new cocoa w
    w1  = new mkCocoaWindow w
    dropD = new mkCocoaDropDown w

    start app = action
        w1.setPosition ({x=100;y=100})
        w1.setSize ({width=400;height=400}) 
        w1.setBackgroundColor web_gray
        w1.setTitle "TestDropDown"
                                              
        dropD.setOptions ["first", "second", "third"]
        dropD.setPosition ({x=100;y=100})
        dropD.setSelectionResponder 
            (new defaultSelectionResponder env.stdout.write)
        w1.addComponent dropD
        
        app.addWindow w1
    
    result action
        osx.startApplication start

defaultSelectionResponder writer = class
    selectionChanged str = action
        writer (str ++ " item selected\n")
    result RespondsToSelectionEvents {..}