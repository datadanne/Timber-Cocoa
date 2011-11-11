module Paint where

import CTWindow     -- <- this includes CTContainer
import CTLabel
import CTContainer  -- but still, removing this causes compiler panic

mkPaintBackdrop w = class

    Container {getAllChildren=getAllChildrenImpl..} = new mkCocoaContainer w
    
    getAllChildren = request
        result []
       
    result Container{..}  

paintHandler w1 label w = class
    pixelCount := 0
    
    pixelList := []
    
    respondToInputEvent (MouseEvent event) modifiers = request
        case event of
            MouseMoved pos -> 
                if (elem Shift modifiers) then
                    pixelCount := 1 + pixelCount
                    label.setText ("Pixel Count: " ++ show pixelCount)
    
                    blackBox = new mkCocoaContainer w
                    blackBox.setSize ({width=7;height=7})
                    blackBox.setBackgroundColor({r=pos.x `mod` 255;g=pos.y `mod` 255;b=2*(pos.y-pos.x) `mod` 255})
                    blackBox.setName ("Container" ++ (show pixelCount))
                    blackBox.setPosition pos
                    pixelList := blackBox : pixelList
                    
                    w1.addComponent blackBox
                elsif (elem Control modifiers) then
                    forall pixel <- pixelList do
                        w1.removeComponent pixel
        
            _ ->
        result NotConsumed
        
    respondToInputEvent _ modifiers = request
        result NotConsumed
        
    result RespondsToInputEvents {..}

root w = class
    osx = new cocoa w

    w1 = new mkCocoaWindow w
    bg = new mkPaintBackdrop w
    label = new mkCocoaLabel w

    painter = new paintHandler bg label w

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