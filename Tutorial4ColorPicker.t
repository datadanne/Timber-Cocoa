module Tutorial4ColorPicker where

import CTWindow

colorPickerGrid parent callback w = class
    initGrid = request
        tileSize = 12
        forall x <- [1..16] do
            forall y <- [1..16] do
                tile = new mkCocoaContainer w
                tile.setSize ({width=tileSize;height=tileSize})
                tile.setPosition ({x=tileSize*x;y=tileSize*y})
                tileColor = ({r=128;g=16*x;b=16*y})
                tile.setBackgroundColor tileColor
                tile.addResponder ({respondToInputEvent=invokeCallback tileColor})
                parent.addComponent tile
    
    invokeCallback color event modifiers  = request
        case event of
            (MouseEvent (MouseClicked _)) ->
                callback color
            (MouseEvent (MouseMoved _)) ->
                if elem Shift modifiers then
                    callback color
            _ -> 
        result Consumed
    result initGrid
