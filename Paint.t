{-

Hold Shift to draw, Ctrl to erase.
    
-}

module Paint where

import COCOA
    
struct PaintResponder < RespondsToInputEvents where
    setColor :: Color -> Action

paintHandler :: Container -> Class Container -> Class PaintResponder
paintHandler w1 mkContainer = class
    pixelList := []
    backgroundColor := red

    setColor c = action
        backgroundColor := c

    respondToInputEvent (MouseEvent (MouseMoved pos)) modifiers = request
        if (elem Shift modifiers) then
            blackBox = new mkContainer
            blackBox.setSize ({width=7;height=7})
            blackBox.setBackgroundColor backgroundColor
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
    w1 = new mkCocoaWindow w :: CocoaWindow
    currentBrushColor = new mkCocoaContainer w :: Container
    bg = new mkCocoaContainer w :: Container

    painter = new paintHandler bg (mkCocoaContainer w)
    
    setColor c = action
        painter.setColor c
        currentBrushColor.setBackgroundColor c

    colorWindow = new mkColorPicker w setColor :: CocoaWindow
    
    startedApp app = action
        app.addWindow w1
        app.addWindow colorWindow
        colorWindow.setTitle "Colors"
        colorWindow.setPosition ({x=701;y=100})
        colorWindow.setVisible True
        bg.addResponder painter
    
    result action
        currentBrushColor.setSize({width=600;height=30})
        currentBrushColor.setBackgroundColor red
        bg.setSize ({width=600;height=600})
        bg.setPosition ({x=0;y=0})
        w1.setSize ({width=600;height=600})
        w1.setPosition ({x=100;y=100})
        w1.setResizable False
        w1.setTitle "Paint"
        bg.addComponent currentBrushColor
        w1.addComponent bg
        
        osx.startApplication startedApp

mkColorPicker :: World -> (Color -> Action) -> Class CocoaWindow
mkColorPicker w callback = class
    
    red := 128
    tiles := []
    
    CocoaWindow{initWindow=initWindowImpl;..} = new mkCocoaWindow w
    
    initWindow app = request
        setSize ({width=215;height=215})
        setVisible False
        setResizable False
        setWindowResponder (new class
            onWindowResize _ = request
            onWindowCloseRequest = request
            result RespondsToWindowEvents{..}) True 
        initGrid
        addResponder (new class
            respondToInputEvent (KeyEvent (KeyPressed UpArrow)) _ = request
                incRed
                result NotConsumed
            respondToInputEvent (KeyEvent (KeyPressed DownArrow)) _ = request
                decRed
                result NotConsumed
            respondToInputEvent _ _ = request
                result NotConsumed
            result RespondsToInputEvents{..})
        initWindowImpl app
    
    reinitGrid = do
        oldtiles = tiles
        tiles := []
        initGrid
        forall tile <- oldtiles do
            removeComponent tile
    
    initGrid = do
        tileSize = 12
        forall x <- [1..16] do
            forall y <- [1..16] do
                tile = new mkCocoaContainer w
                tile.setSize ({width=tileSize;height=tileSize})
                tile.setPosition ({x=tileSize*x;y=tileSize*y})
                tileColor = ({r=red;g=16*x;b=16*y})
                tile.setBackgroundColor tileColor
                tile.addResponder ({respondToInputEvent=invokeCallback tileColor})
                addComponent tile
                tiles := tile:tiles
    
    invokeCallback color (MouseEvent (MouseClicked _)) _  = request
        send callback color
        result Consumed
    invokeCallback color (MouseEvent (MouseMoved _)) modifiers = request
        if elem Shift modifiers then send callback color
        result Consumed
    invokeCallback _ _ _ = request 
        result Consumed
    
    incRed = action
        if red<256 then red := red+16; reinitGrid
    decRed = action
        if red>0 then red := red-16; reinitGrid
    
    result CocoaWindow{..}