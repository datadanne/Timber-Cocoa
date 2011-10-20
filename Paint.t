module Paint where

import POSIX
import COCOA
import CTContainer 

mkPaintBackdrop env = class
    base = new mkCocoaContainer env
    id = base.id
        
    addResponder = base.addResponder
    setResponders = base.setResponders
    getResponders = base.getResponders
    setParent = base.setParent
    getParent = base.getParent
    setIsFocusable = base.setIsFocusable
    getIsFocusable = base.getIsFocusable
    setName s = base.setName s
    getName = base.getName
    getState = base.getState
    setState = base.setState
    respondToInputEvent = base.respondToInputEvent

    setPosition = base.setPosition
    getPosition = base.getPosition

    setSize = base.setSize
    getSize = base.getSize

    setBackgroundColor = base.setBackgroundColor
    getBackgroundColor = base.getBackgroundColor
    
    
    addComponent = base.addComponent
    removeComponent = base.removeComponent
    removeAllComponents = base.removeAllComponents

    getComponents = base.getComponents
    getAllComponents = request
        result []
        
    destroy = base.destroy
        
    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init = base.init
       
    result Container{..}  

paintHandler w1 label env = class
    pixelCount := 0
    
    posget (MousePressed p) = p
    posget (MouseReleased p) = p
    posget (MouseClicked p) = p
    posget (MouseWheelScroll p _ _) = p   

    respondToInputEvent (MouseEvent event) modifiers = request
        pos = (posget event)
    
        env.stdout.write "Painting box\n"
        label.setText ("Pixel Count: " ++ show pixelCount)
        --label.setText ("Position: " ++ (show pos.x) ++ "," ++ (show pos.y))
    
        blackBox = new mkCocoaContainer env
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

    w1 = new mkWindow env
    bg = new mkPaintBackdrop env
    label = new mkCocoaLabel

    painter = new paintHandler bg label env

    applicationDidFinishLaunching app = action
        app.setEnv env
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