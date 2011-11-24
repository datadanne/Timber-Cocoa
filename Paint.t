{-

Hold Shift to draw, Ctrl to erase.
    
-}

module Paint where

import POSIX
import COCOA
    
struct PaintResponder < RespondsToInputEvents where
    setColor :: Color -> Action

paintHandler :: Container -> Class Container -> (String -> Request Int) -> Class PaintResponder
paintHandler w1 mkContainer write = class
    pixelList := []
    color := red

    setColor c = action
        color := c

    respondToInputEvent (MouseEvent (MouseMoved pos)) modifiers = request
        if (elem Shift modifiers) then
            blackBox = new mkContainer
            blackBox.setSize ({width=7;height=7})
            blackBox.setBackgroundColor color
            blackBox.setPosition pos
            pixelList := (Just blackBox) : pixelList
            w1.addComponent blackBox
        elsif (elem Control modifiers) then
            newList <- forall pixel <- [ p | p <- pixelList, isJust p] do
                pixelPos <- (fromJust pixel).getPosition
                xDiff = abs (pixelPos.x - pos.x)
                yDiff = abs (pixelPos.y - pos.y)
                if ((xDiff < 10) && yDiff < 10) then
                    w1.removeComponent (fromJust pixel)
                    result Nothing
                else
                    result pixel
            pixelList := newList
        result NotConsumed
        
    respondToInputEvent _ _ = request
        result NotConsumed
        
    result PaintResponder {..}

root w = class
    env = new posix w
    osx = new cocoa w
    w1 = new mkCocoaWindow w :: CocoaWindow
    currentBrushColor = new mkCocoaContainer w :: Container
    bg = new class
        Container{getAllChildren=temp;..} = new mkCocoaContainer w
        getAllChildren = request result []
        result Container{..}

    painter = new paintHandler bg (mkCocoaContainer w) (env.stdout.write)
    
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
        initWindowImpl app
    
    initGrid = do
        tileSize = 12
        forall x <- [1..16] do
            forall y <- [1..16] do
                tile = new mkCocoaContainer w
                tile.setSize ({width=tileSize;height=tileSize})
                tile.setPosition ({x=tileSize*x;y=tileSize*y})
                tileColor = ({r=128;g=16*x;b=16*y})
                tile.setBackgroundColor tileColor
                tile.addResponder ({respondToInputEvent=invokeCallback tileColor})
                addComponent tile
    
    invokeCallback color (MouseEvent (MouseClicked _)) _  = request
        send callback color
        result Consumed
    invokeCallback color (MouseEvent (MouseMoved _)) modifiers = request
        if elem Shift modifiers then send callback color
        result Consumed
    invokeCallback _ _ _ = request 
        result Consumed
    
    result CocoaWindow{..}