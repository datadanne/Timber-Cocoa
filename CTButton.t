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
        ref <- initButton w title
        state := Active ref
        setSizeImpl (<- buttonSetSize ref (<- getSize))
        buttonSetPosition ref (<- getPosition)
        result ref
    
    getState = request
        result state

    this = Button {id = self;..}

    result this

private 
 
extern initButton        :: World -> String -> Request CocoaRef
extern buttonSetTitle    :: CocoaRef -> String -> Request ()
extern buttonSetPosition :: CocoaRef -> Position -> Request ()
extern buttonSetSize     :: CocoaRef -> Size -> Request Size
