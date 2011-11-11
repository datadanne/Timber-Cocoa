module TestDropDown where

import POSIX
import COCOA
import CTDropDown

root :: RootType
root w = class
    osx = new cocoa w
    w1 = new mkCocoaWindow w
    dropD = new mkCocoaDropDown w

    start app = action                         
        w1.setPosition ({x=100;y=100})
        w1.setSize ({width=400;height=300})
        w1.setTitle "TestDropDown"
        w1.setBackgroundColor green
                                              
        dropD.setOptions ["first", "second", "third"]
        dropD.setPosition ({x=100;y=100})
        dropD.setSelectionResponder (new defaultSelectionResponder)
        w1.addComponent dropD
        
        app.addWindow w1
    
    result action
        osx.startApplication start

defaultSelectionResponder = class
    selectionChanged str = action
    result RespondsToSelectionEvents {..}