module ScrollTest where

import POSIX
import COCOA

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkWindow env
    textA = new mkCocoaTextArea env
    
    applicationDidFinishLaunching app = action                         
        app.showWindow w1
        app.setEnv env
        
    
    result action
        w1.setSize ({width=700;height=500})
        w1.setPosition ({x=0;y=0})                                         
        
        --test = MouseEvent (MouseWheelScroll ({x=100;y=200}) 0.1 1.0)
       
        textA.setSize ({width=300;height=300})
        textA.setPosition ({x=100;y=100})
        textA.setText "Moaoahaha\nLine1\nLine2\nLine3\nLine4\nScrolling?\nLine5\nLine6\nLine7\nLine8\nLine9\netc...\nLine10\nAre u scrolling?\nLine11\nLine13\nLine14\nLine15\nLine16\nLine99\nEOF\nMoaoahaha\nLine1\nLine2\nLine3\nLine4\nScrolling?\nLine5\nLine6\nLine7\nLine8\nLine9\netc...\nLine10\nAre u scrolling?\nLine11\nLine13\nLine14\nLine15\nLine16\nLine99\nEOF\n\\r\\n"
        
        w1.addComponent textA
        w1.setBackgroundColor ({r=100;b=0;g=130})
        osx.startApplication applicationDidFinishLaunching