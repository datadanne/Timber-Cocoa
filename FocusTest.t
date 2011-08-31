module FocusTest where

import POSIX
import COCOA

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkWindow env
    c2 = new mkContainer env
    button = new mkCocoaButton env
    button2 = new mkCocoaButton env
    
    tabClick app wid event = request
        env.stdout.write ("Sending KeyPressed \"Tab\" to window with ID: " ++ (show wid) ++ "\n")
        foo = KeyEvent (KeyPressed UpArrow)
        superTest = KeyEvent (KeyPressed Tab)
        app.eventDispatcher superTest wid
        result True
    
    block := False
    tabStop event = request
        after (millisec 100) send action 
            button.setTitle ("Consume: " ++ (show (not block)))
        block := not block
        env.stdout.write (if (block) then
                                "Tab shall not pass!\n"
                            else
                                "It's ok. Tab may continue.\n")
        result block
    
    doNothing event = request
        env.stdout.write "MOUSE CLICK"
        result True
        
  {-  redclicked app wid event = request
        env.stdout.write ("red clicked!!!: " ++ (show wid) ++ "\n")
        superTest = KeyEvent (KeyPressed "ShiftTab")
        app.eventDispatcher superTest wid
        result True  -}
        
    applicationDidFinishLaunching app = action                         
        app.showWindow w1
        app.setEnv env
        tabButton = new mkCocoaButton env
        tabButton.setTitle "Tab (nofocus)"
        tabButton.setPosition ({x=20;y=200})
        tabButton.installMouseListener doNothing --(tabClick app (<- w1.getId))
        tabButton.setIsFocusable False
        button.installMouseListener doNothing
        button2.installMouseListener doNothing
        
        w1.addComponent tabButton

        button.setTitle "First"     
        button.setPosition ({x=20;y=20}) 
        button2.setPosition ({x=0;y=55})
        button2.setTitle "Second" 
        
        after (sec 7) send action
            button3 = new mkCocoaButton env
            button3.setTitle "Three?"
            button3.installMouseListener doNothing
            c3 = new mkContainer env
            c3.addComponent button3
            c3.setSize ({width=180;height=50})
            c3.setName "Container:C3"
            c3.setPosition ({x=0;y=100})
            c3.setBackgroundColor({r=240;g=66;b=33})
            --c3.installMouseListener (redclicked app (<-w1.getId))
            w1.addComponent c3 
    
    result action
        button.setSize ({width=108;height=17}) 
        button2.setName "Second"
        button.setName "First"
        button.installKeyListener tabStop
        c2.setName "greenContainer"
        
        c2.setSize ({width=180;height=140})
        c2.setPosition ({x=0;y=0})
        c2.setBackgroundColor({r=0;g=255;b=0}) 
        c2.addComponent button
        c2.addComponent button2
        w1.addComponent c2
        osx.startApplication applicationDidFinishLaunching