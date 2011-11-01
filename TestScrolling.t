module TestScrolling where

import POSIX
import COCOA
import CTTextArea
import CTTextField

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkCocoaWindow w
    textA = new mkCocoaTextArea w
    textB = new mkCocoaTextField w
    
    start app = action                         
        app.addWindow w1        
    
    result action
        w1.setSize ({width=700;height=500})
        w1.setPosition ({x=0;y=0})                                         
               
        textA.setSize ({width=300;height=300})
        textA.setPosition ({x=100;y=100})
        textA.setText "Moaoahaha\nLine1\nLine2\nLine3\nLine4\nScrolling?\nLine5\nLine6\nLine7\nLine8\nLine9\netc...\nLine10\nAre u scrolling?\nLine11\nLine13\nLine14\nLine15\nLine16\nLine99\nEOF\nMoaoahaha\nLine1\nLine2\nLine3\nLine4\nScrolling?\nLine5\nLine6\nLine7\nLine8\nLine9\netc...\nLine10\nAre u scrolling?\nLine11\nLine13\nLine14\nLine15\nLine16\nLine99\nEOF\n\\r\\n"

        textB.setSize ({width=100;height=50})
        textB.setPosition ({x=100;y=50})
        textB.setText "Some text"
        
        w1.addComponent textA
        w1.addComponent textB        
        w1.setBackgroundColor ({r=100;b=0;g=130})
        osx.startApplication start
