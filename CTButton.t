module CTButton where

import COCOA   

struct Button < Component, HasTitle

--------------------------------------------------------------------------------------------------
------          ** BUTTON **            ----------------------------------------------------------

mkCocoaButton :: World -> Class Button
mkCocoaButton w = class

    state := Inactive
    title := "Click me!"
    defaultSize= {width=108; height=21}
    
    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl..} = new basicComponent True Nothing "BUTTON"

    setPosition p = request
        if isActive state then
            Active ref = state
            buttonSetPosition ref p
        setPositionImpl p

    setSize s = request
        if isActive state then
            Active ref = state
            setSizeImpl (<- buttonSetSize ref s)
        else
            setSizeImpl s

    setTitle s = request
        if isActive state then
            Active ref = state
            buttonSetTitle ref s
        title := s
        setName s
   
    getTitle = request
        result title

    destroyComp = request
        state := destroyState state

    initComp app = request
        ref <- initButton w
        state := Active ref
        -- this will also set the size to fit the text
        setSizeImpl (<- buttonSetTitle ref title)
        buttonSetPosition ref (<- getPosition)
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
