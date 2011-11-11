module CTButton where

import COCOA   

struct HasClickResponder where
    setClickResponder    :: RespondsToClickEvents -> Request ()

struct RespondsToClickEvents where
    clickPerformed       :: Action

struct Button < Component, HasTitle, RespondsToClickEvents, HasClickResponder

--------------------------------------------------------------------------------------------------
------          ** BUTTON **            ----------------------------------------------------------

mkCocoaButton :: World -> Class Button
mkCocoaButton w = class

    state := Inactive
    sizeHasBeenSet := False

    der = new defaultButtonInputResponder this
    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl;setResponders=setRespondersImpl..} =
        new basicComponent True Nothing "BUTTON"

    setPosition p = request
        if isActive state then
            Active ref = state
            buttonSetPosition ref p
        setPositionImpl p

    setSize s = request
        sizeHasBeenSet := True
        if isActive state then
            Active ref = state
            setSizeImpl (<- buttonSetSize ref s)
        else
            setSizeImpl s         
    
    respondersToAddAtInit := [der]
    addRespondersSuggestionImpl rs = request
        if isActive state then
            addResponder rs -- should be addResponderImpl then
        else
            respondersToAddAtInit := (respondersToAddAtInit ++ [rs])
        
        -- and then at init do addResponder respondersToAddAtInit
            
    setResponders rs = request
        setRespondersImpl (der:rs)

    title := "Click me!"            
    getTitle = request
        result title   
    setTitle s = request
        if isActive state then
            Active ref = state
            buttonSetTitle ref s
            setSizeImpl (<- buttonSetSize ref (<-getSize))
        title := s
        setName s

    dcr := new defaultClickResponder
    clickPerformed = action
        dcr.clickPerformed
    setClickResponder resp = request
        dcr := resp
    
    destroyComp = request
        state := destroyState state

    initComp app = request
        ref <- initButton w
        state := Active ref
        
        newSize <- buttonSetTitle ref title
        if sizeHasBeenSet then
            setSizeImpl (<-buttonSetSize ref (<- getSize))
        else
            setSizeImpl newSize
        buttonSetPosition ref (<- getPosition)
        
        addResponder der
        result ref
    
    getState = request
        result state

    this = Button {id = self;..}

    result this

private 
 
extern initButton        :: World -> Request CocoaRef
extern buttonSetTitle    :: CocoaRef -> String -> Request Size
extern buttonSetPosition :: CocoaRef -> Position -> Request ()
extern buttonSetSize     :: CocoaRef -> Size -> Request Size

-- from CTWindow.t, should be changed to import CTWindow instead or move the functions
clickInsideBox mousePos boxPos boxSize = 
    (inInterval mousePos.x boxPos.x boxSize.width) && (inInterval mousePos.y boxPos.y boxSize.height)
inInterval x startPos width = 
    (x >= startPos && x <= (startPos+width))

defaultClickResponder = class
    clickPerformed = action
    result RespondsToClickEvents {..}

defaultButtonInputResponder btn = class
    respondToInputEvent (MouseEvent (MouseClicked pos)) _ = request
        btnSize <- btn.getSize
        btnPos  <- btn.getPosition

        -- vertical invisible border: 7 under, 4 above
        -- horizontal invisible border: 7 right, 6 left
        clickSize = {width=btnSize.width-13; height=btnSize.height-11}
        clickPos  = {x=btnPos.x+6; y=btnPos.y+4}
    
        if clickInsideBox pos clickPos clickSize then
            -- the event was inside the clickable area
            send btn.clickPerformed
            result Consumed
        else
            result NotConsumed  
            
    respondToInputEvent _ _ = request 
        result NotConsumed

    result RespondsToInputEvents {..}