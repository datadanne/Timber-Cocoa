module Paint where

import COCOA
import CTLabel
import Tutorial4ColorPicker

mkPaintBackdrop :: World -> Class Container
mkPaintBackdrop w = class
    Container {getAllChildren=getAllChildrenImpl..} = new mkCocoaContainer w
    getAllChildren = request result []
    result Container{..}
    
struct PaintResponder < RespondsToInputEvents where
    setColor :: Color -> Action

paintHandler :: ContainsComponents -> Label -> World -> Class PaintResponder
paintHandler w1 label w = class
    pixelList := []
    backgroundColor := ({r=0;g=0;b=0})
    setColor c = action
        backgroundColor := c
    
    respondToInputEvent (MouseEvent (MouseMoved pos)) modifiers = request
        if (elem Shift modifiers) then
            pixelCount = length pixelList
            label.setText ("Pixel Count: " ++ show pixelCount)
            blackBox = new mkCocoaContainer w
            blackBox.setSize ({width=7;height=7})
            blackBox.setBackgroundColor backgroundColor
            blackBox.setName ("Container" ++ show pixelCount)
            blackBox.setPosition pos
            pixelList := blackBox : pixelList
            w1.addComponent blackBox
        elsif (elem Control modifiers) then
            forall pixel <- pixelList do
                pixelPos <- pixel.getPosition
                xDiff = abs (pixelPos.x - pos.x)
                yDiff = abs (pixelPos.y - pos.y)
                if ((xDiff < 10) && yDiff < 10) then
                    w1.removeComponent pixel
        result NotConsumed
        
    respondToInputEvent _ _ = request
        result NotConsumed
        
    result PaintResponder {..}

root w = class
    osx = new cocoa w
    w1 = new mkCocoaWindow w
    bg = new mkPaintBackdrop w
    currentBrushColor = new mkCocoaContainer w
    label = new mkCocoaLabel w

    painter = new paintHandler bg label w
    
    setColor c = action
        painter.setColor c
        currentBrushColor.setBackgroundColor c

    colorWindow :: CocoaWindow
    colorWindow = new mkColorPicker w setColor
    
    applicationDidFinishLaunching app = action
        app.addWindow w1
        app.addWindow colorWindow
        colorWindow.setVisible True
        w1.addComponent label
        bg.addResponder painter
    
    result action
        currentBrushColor.setSize({width=100;height=100})
        currentBrushColor.setBackgroundColor ({r=0;g=0;b=0})
        label.setSize ({width=300;height=50})
        label.setPosition ({x=50;y=200})
        label.setText "PainT_Timber"
        bg.setSize ({width=600;height=600})
        bg.setPosition ({x=0;y=0})
        w1.setBackgroundColor ({r=150;g=150;b=150})
        w1.addComponent bg
        w1.addComponent label
        w1.setSize ({width=600;height=600})
        w1.setPosition ({x=100;y=100})
        bg.addComponent currentBrushColor

        osx.startApplication applicationDidFinishLaunching