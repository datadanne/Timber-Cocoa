module NewTest where

import POSIX
import COCOA
import CTLabel

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkWindow env
    w2 = new mkWindow env

    c1 = new mkContainer env
    c2 = new mkContainer env
    button = new mkCocoaButton env
     
    teest = new mkCocoaLabel

    moveUp cmp event = request
        q <- cmp.getPosition
        cmp.setPosition ({x=q.x;y=q.y+5})
        result True
    
    count := 0
    
    react wnd event = request
        result True                  
    
    reactor wnd event = request
        result True
        
    moveUp2 cmp event = request
        count := count + 1
        q <- cmp.getPosition
        cmp.setPosition ({x=q.x+5;y=q.y+5})
        button.setTitle ("Move (" ++ (show count) ++ ")")
        result True
    
    greenclicked app wid event = request
        env.stdout.write ("green clicked!!!: " ++ (show wid) ++ "\n")
        superTest = KeyEvent (KeyPressed Tab)
        app.eventDispatcher superTest wid
            
        result True
        
    applicationDidFinishLaunching app = action
        app.setEnv env
        app.showWindow w2                          
        app.showWindow w1
        c2.installMouseListener (greenclicked app (<- w1.getId))
        c1.setBackgroundColor ({r=255;g=0;b=255}) 
        after (sec 4) send action 
            env.stdout.write "---- IN AFTER 4 SEC!!! ----\n"
            c1.setBackgroundColor ({r=0;g=0;b=255})
            c1.setSize ({width=50;height=50})
            c1.setPosition ({x=0;y=100})
            button.setTitle "Move"
            button.setPosition ({x=20;y=20}) 
                                       
            after (sec 3) send action
                w2.hide
                teest.setPosition ({x=20;y=150})
                
            after (sec 4) send action
                w2.setVisible
                teest.setPosition ({x=30;y=150})
                teest.setSize ({width=200;height=200}) 
                teest.setTextColor ({r=255;g=0;b=0})
                
            after (sec 7) send action
                button.installMouseListener (moveUp2 c1)
                w2.destroyWindow
                newbutton = new mkCocoaButton env
                newbutton.setPosition ({x=0;y=55})
                newbutton.setTitle "sec7add"
                w1.addComponent newbutton 
                teest.setPosition ({x=40;y=150})
                w1.setFocus button
                --w1.destroyWindow

    loopIt cmp = action
        q <- cmp.getPosition
        cmp.setPosition ({x=q.x+1;y=q.y+1})
        after (millisec 200) send loopIt cmp
    
    result action
        loopIt c2
        button.setSize ({width=108;height=17})
        button.installMouseListener (moveUp c1) 
        button.setTitle "prehandlZZZZ"   
        teest.setSize ({width=100;height=50})
        teest.setPosition ({x=0;y=150})
        teest.setText "TEZT"
        c1.setSize ({width=100;height=100}) 
        c2.setSize ({width=180;height=140})
        c2.setPosition ({x=0;y=0})
        c2.setBackgroundColor({r=0;g=255;b=0}) 
        
        w1.addComponent teest
        
        w1.addComponent c1
        w1.addComponent c2
        w1.installWindowListener (react w1)
        w2.installWindowListener (reactor w2)
        c2.addComponent button
        osx.startApplication applicationDidFinishLaunching