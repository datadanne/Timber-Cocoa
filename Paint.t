module Paint where

import CTWindow     -- <- this includes CTContainer
import CTLabel
import CTContainer  -- but still, removing this causes compiler panic

mkPaintBackdrop env = class

    Container {getAllChildren=getAllChildrenImpl..} = new mkCocoaContainer
    
    getAllChildren = request
        result []
       
    result Container{..}  

paintHandler w1 label env = class
    pixelCount := 0
    
    posget (MousePressed p) = p
    posget (MouseReleased p) = p
    posget (MouseClicked p) = p
    posget (MouseWheelScroll p _ _) = p   

    respondToInputEvent (MouseEvent event) modifiers = request
        pos = (posget event)
    
        label.setText ("Pixel Count: " ++ show pixelCount)
        --label.setText ("Position: " ++ (show pos.x) ++ "," ++ (show pos.y))
    
        blackBox = new mkCocoaContainer
        blackBox.setSize ({width=7;height=7})
        blackBox.setBackgroundColor({r=pos.x `mod` 255;g=pos.y `mod` 255;b=2*(pos.y-pos.x) `mod` 255})
        blackBox.setName ("Container" ++ (show pixelCount))
        blackBox.setPosition pos
        w1.addComponent blackBox
        
        pixelCount := 1 + pixelCount
        result False
        
    respondToInputEvent _ modifiers = request
        result False
        
    result RespondsToInputEvents {..}

root w = class
    env = new posix w
    osx = new cocoa w

    w1 = new mkCocoaWindow
    bg = new mkPaintBackdrop env
    label = new mkCocoaLabel

    painter = new paintHandler bg label env

    applicationDidFinishLaunching app = action
        app.addWindow w1
        w1.addComponent label
        bg.addResponder painter
    
    result action
        label.setSize ({width=300;height=50})
        label.setPosition ({x=50;y=200})
        label.setText "PainT_Timber"
        bg.setSize ({width=300;height=300})
        w1.setBackgroundColor ({r=150;g=150;b=150})
        w1.addComponent bg
        w1.addComponent label
        w1.setSize ({width=500;height=500})

        osx.startApplication applicationDidFinishLaunching