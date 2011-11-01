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
        app.addWindow w1
    
    result action
        w1.setSize ({width=700;height=500})
        w1.setPosition ({x=0;y=0})                                         
        dropD.setSize ({width=300;height=300})
        dropD.setPosition ({x=100;y=100})  
        dropD.setOptions ["first", "second", "third"]
        dropD.setSelectionResponder (new defaultSelectionResponder)
        w1.addComponent dropD
        w1.setBackgroundColor ({r=100;b=0;g=130})
        osx.startApplication start

defaultSelectionResponder = class
    selectionChanged str = action
    result RespondsToSelectionEvents {..}