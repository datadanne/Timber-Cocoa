module CTButton where

import COCOA   

struct Button < Component, HasTitle
--------------------------------------------------------------------------------------------------
------          ** BUTTON **            ----------------------------------------------------------

mkCocoaButton = class

    state := Inactive
    title := "Click me!"
    defaultSize= {width=108; height=21}
    
    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl..} = new basicComponent True Nothing "BUTTON"

    setPosition p = request
        if isActive state then
            Active ref = state
            _ = buttonSetPosition ref p
        setPositionImpl p

    setSize s = request
        if isActive state then
            Active ref = state
            setSizeImpl (buttonSetSize ref s)
        else
            setSizeImpl s

    setTitle s = request
        if isActive state then
            Active ref = state
            _ = buttonSetTitle ref s
        title := s
        setName s
   
    getTitle = request
        result title

    destroyComp = request
        state := destroyState state

    initComp app = request
        ref = initButton title
        state := Active ref
        setSizeImpl (buttonSetSize ref (<- getSize))
        _ = buttonSetPosition ref (<- getPosition)
        result ref
    
    getState = request
        result state

    this = Button {id = self;..}

    result this

private 
 
extern initButton        :: String -> CocoaRef
extern buttonSetTitle    :: CocoaRef -> String -> ()
extern buttonSetPosition :: CocoaRef -> Position -> ()
extern buttonSetSize     :: CocoaRef -> Size -> Size
