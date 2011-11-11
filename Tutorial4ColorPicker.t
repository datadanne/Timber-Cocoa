module Tutorial4ColorPicker where

import COCOA

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