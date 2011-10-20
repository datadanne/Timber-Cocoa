module TestDropDown where

import POSIX
import COCOA

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkWindow env
    c2 = new mkCocoaContainer env
    dropdown = new mkCocoaDropDown env
    dropdown2 = new mkCocoaDropDown env
    
    applicationDidFinishLaunching app = action                         
        app.addWindow w1
        app.setEnv env
        
    result action
        w1.setSize ({width=500;height=500})
        dropdown.setName "dropdown1"
        dropdown.setOptions ["ABC", "123"]
        dropdown.setPosition ({x=100;y=100})
        w1.addComponent dropdown
        
        dropdown2.setName "dropdown2"
        dropdown2.setOptions ["HELLO", "WORLD"]
        dropdown2.setPosition ({x=100;y=130})
        w1.addComponent dropdown2
        
        osx.startApplication applicationDidFinishLaunching