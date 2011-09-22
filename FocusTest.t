module FocusTest where

import POSIX
import COCOA

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkWindow env
    c2 = new mkCocoaContainer env
    button = new mkCocoaButton env
    buttonOverlay = new mkCocoaContainer env
    button2 = new mkCocoaButton env
    inputField = new mkCocoaTextField env
    dropDown = new mkCocoaDropDown env
    
    tabKeyResponder app wid = class
        handleEvent event modifiers = request
            env.stdout.write ("Sending KeyPressed \"Tab\" to window which has ID: " ++ (show wid) ++ "\n")
            result True
        result RespondsToInputEvents {..}
    
    tabStopResponder = class
        block := False
        handleEvent event modifiers = request
            button.setTitle ("Consume: " ++ (show (not block)))
            block := not block
            env.stdout.write (if (block) then
                "Tab shall not pass!\n"
            else
                "It's ok. Tab may continue.\n")
            result block
        result RespondsToInputEvents {..}
        
    applicationDidFinishLaunching app = action                         
        app.showWindow w1
        app.setEnv env
        tabButton = new mkCocoaButton env
        tabButton.setTitle "Tab (nofocus)"
        tabButton.setPosition ({x=0;y=250})
        tabButton.setIsFocusable False
        dropDown.addOption "hey"
        
        w1.addComponent tabButton

        button.setTitle "First"     
        button.setPosition ({x=200;y=20}) 
        button2.setPosition ({x=0;y=55})
        button2.setTitle "Second"
        c2.removeComponent tabButton
        
        after (sec 1) send action
            button3 = new mkCocoaButton env
            button3.setTitle "Three?"
            c3 = new mkCocoaContainer env
            c3.addComponent button3
            c3.setSize ({width=180;height=50})
            c3.setName "Container:C3"
            c3.setPosition ({x=0;y=100})
            c3.setBackgroundColor({r=240;g=66;b=33})
            w1.addComponent c3 
            w1.removeComponent c2
            w1.setPosition ({x=0;y=0})
            w1.setSize ({width=400;height=200})
            
            after (sec 5) send action
                w1.removeAllComponents
                w1.addComponent buttonOverlay
                w1.setSize ({width=300;height=400})
                w1.setPosition ({x=150;y=300})
    
    result action
        w1.setSize ({width=700;height=500})
        w1.setPosition ({x=0;y=0})

        buttonOverlay.setSize ({width=108;height=20})
        buttonOverlay.setBackgroundColor ({r=255;g=255;b=0})
        buttonOverlay.setPosition ({x=200;y=20}) 

        button2.setName "Second"
        button.setName "First"
        tsh = new tabStopResponder
        button.addResponder tsh
        c2.setName "greenContainer"
        
        c2.setSize ({width=180;height=140})
        c2.setPosition ({x=0;y=0})
        c2.setBackgroundColor({r=0;g=255;b=0}) 
        w1.addComponent button
        c2.addComponent button2
        c2.addComponent inputField
        
        inputField.setSize ({width=180;height=17})
        inputField.setPosition ({x=0;y=20})
        w1.addComponent c2
        
        dropDown.setOptions ["this", "is","DROPDOWN"]
        dropDown.setPosition({x=200;y=100})
        w1.addComponent dropDown
        
        osx.startApplication applicationDidFinishLaunching