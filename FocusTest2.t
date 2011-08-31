module FocusTest2 where

import POSIX
import COCOA

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkWindow env
    c2 = new mkContainer env
    button = new mkCocoaButton env
    button2 = new mkCocoaButton env
    button3 = new mkCocoaButton env
       
    greenclicked app wid event = request
        env.stdout.write ("green clicked!!!: " ++ (show wid) ++ "\n")
        superTest = KeyEvent (KeyPressed S)
        app.eventDispatcher superTest wid
            
        result True
        
    applicationDidFinishLaunching app = action                         
        app.showWindow w1
        w1.installMouseListener (greenclicked app (<- w1.getId))

        env.stdout.write "---- IN AFTER 4 SEC!!! ----\n"
        button.setTitle "Button1 (c2)"
        button.setPosition ({x=20;y=20}) 
        button2.setPosition ({x=0;y=55})
        button2.setTitle "Button2 (c2)"
        button3.setPosition ({x=0;y=80})
        button3.setTitle "wButton3 (w1)"
        
        after (sec 4) send action
            button4 = new mkCocoaButton env
            button4.setTitle "Booooo"
            w1.addComponent button4 
        
    result action
        button.setName "Button1"
        button2.setName "Button2"
        button3.setName "Button3"
        button.setSize ({width=108;height=17})
        c2.setSize ({width=180;height=140})
        c2.setPosition ({x=0;y=0})
        c2.setBackgroundColor({r=0;g=255;b=0}) 
        c2.addComponent button
        c2.addComponent button2
        c2.setName "Container2"
        w1.addComponent button3
        w1.addComponent c2
        osx.startApplication applicationDidFinishLaunching