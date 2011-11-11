module Tutorial4ColorPicker where

import CTWindow

colorPickerTile colorPickerX colorPickerY w = class
    color := ({r=128;g=16*colorPickerX;b=16*colorPickerY})
    
    initTile parent callback = request
        size = 12
        responder = new tileResponder color callback
    
        container = new mkCocoaContainer w
        container.setSize ({width=size;height=size})
        container.setPosition ({x=size*colorPickerX;y=size*colorPickerY})
        container.setBackgroundColor color
        container.addResponder responder
        
        parent.addComponent container
        
    tileResponder tileColor setColor = class
        respondToInputEvent (MouseEvent (MouseClicked _)) modifiers = request
            setColor tileColor
            result False

        respondToInputEvent (MouseEvent (MouseMoved _)) modifiers = request
            if elem Shift modifiers then
                setColor tileColor
            result False

        respondToInputEvent _ modifiers = request
            result False

        result RespondsToInputEvents {..}
        
    result initTile
{-
c cb = class
    changeColor color (MouseEvent (MouseClicked _)) modifiers = request
        ...
    changeColor color (MouseEvent (MouseMoved _)) modifiers = request
        ...
    result changeColor

i grid-klassen:
    changeColor = new c
    forall tiles do
        ... changeColor

i tile-klassen:
    container.addResponder ({respondToInputEvent = changeColor color})
-}

colorPickerGrid container cb env = class
    callback := cb
    
    initGrid = request
        forall row <- [1..16] do
            forall col <- [1..16] do    
               initTile = new colorPickerTile col row env
               initTile container callback
               
    result initGrid
