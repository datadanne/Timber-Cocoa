module Tutorial4ColorPicker where

import COCOA

struct ColorPickerTile where
    initTile :: CocoaWindow -> (Color -> Request ()) -> Request ()
    
struct ColorGrid where
    initGrid :: Request ()

colorPickerTile colorPickerX colorPickerY env = class
    color := ({r=128;g=16*colorPickerX;b=16*colorPickerY})
    
    initTile parent callback = request
        responder = new tileResponder color callback env
    
        container = new mkCocoaContainer env
        container.setSize ({width=12;height=12})
        container.setPosition ({x=12*colorPickerX;y=12*colorPickerY})
        container.setBackgroundColor color
        container.addResponder responder
        
        parent.addComponent container
        
    tileResponder tileColor setColor env = class
        handleEvent (MouseEvent event) modifiers = request
            setColor tileColor
            result False

        handleEvent _ modifiers = request
            result False

        result RespondsToInputEvents {..}
        
    result ColorPickerTile {..}  

colorPickerGrid container cb env = class
    colorPickers := []
    callback := cb
    
    initGrid = request
        forall row <- [1..15] do
            forall col <- [1..15] do    
               tile = new colorPickerTile col row env
               tile.initTile container callback
               colorPickers := (row,col,tile) : colorPickers

    result ColorGrid {..}
