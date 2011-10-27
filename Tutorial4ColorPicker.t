module Tutorial4ColorPicker where

import CTWindow

colorPickerTile colorPickerX colorPickerY env = class
    color := ({r=128;g=16*colorPickerX;b=16*colorPickerY})
    
    initTile parent callback = request
        size = 12
        responder = new tileResponder color callback env
    
        container = new mkCocoaContainer
        container.setSize ({width=size;height=size})
        container.setPosition ({x=size*colorPickerX;y=size*colorPickerY})
        container.setBackgroundColor color
        container.addResponder responder
        
        parent.addComponent container
        
    tileResponder tileColor setColor env = class
        respondToInputEvent (MouseEvent event) modifiers = request
            setColor tileColor
            result False

        respondToInputEvent _ modifiers = request
            result False

        result RespondsToInputEvents {..}
        
    result initTile

colorPickerGrid container cb env = class
    callback := cb
    
    initGrid = request
        forall row <- [1..16] do
            forall col <- [1..16] do    
               initTile = new colorPickerTile col row env
               initTile container callback

    result initGrid
