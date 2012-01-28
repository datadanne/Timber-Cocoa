module Tutorial1CompHierarchy where

import COCOA
import CTButton
import CTLabel

root w = class
    osx = new cocoa w
    w1 = new mkCocoaWindow w
    
    start app = action
        w1.setPosition ({x=100,y=100})
        w1.setSize ({width=400,height=400}) 
        w1.setBackgroundColor web_gray
        w1.setTitle "Tutorial"        
        createComponentHierarchy -- Tutorial 1
        app.addWindow w1

    -- Tutorial 1: Building a component hierarchy
    button = new mkCocoaButton w
    label = new mkCocoaLabel w
    leftContainer = new mkCocoaContainer w
    rightContainer = new mkCocoaContainer w
 
    createComponentHierarchy = do
        leftContainer.setSize ({width=200, height=200})
        leftContainer.setBackgroundColor ({r=100,g=100,b=200})
        leftContainer.setPosition ({x=0,y=0})

        rightContainer.setSize ({width=200, height=200})
        rightContainer.setBackgroundColor ({r=100,g=200,b=100})
        rightContainer.setPosition ({x=200, y=0})    

        button.setTitle "Click me!"
        button.setSize ({width=110,height=21})
        button.setPosition ({x=40, y=100})
        button.setClickResponder (new buttonHandler label)
        leftContainer.addComponent button

        label.setText "Click counter"
        label.setSize ({width=150, height=36})
        label.setPosition ({x=40, y=100})
        rightContainer.addComponent label

        w1.addComponent leftContainer
        w1.addComponent rightContainer

    result action
        osx.startApplication start 

-- Tutorial 1: Updating a label with a button click count
buttonHandler :: Label -> Class Action
buttonHandler label = class
    clickCount := 0
    result action
        clickCount := clickCount + 1
        label.setText ("Click #" ++ show clickCount)