module CTTextField where

import COCOA   

struct TextField < Component, HasText    

mkCocoaTextField :: World -> Class TextField
mkCocoaTextField w = class
    text := ""

    state := Inactive
    getState = request
        result state

    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl..} = new basicComponent True Nothing "TextField"
    setPosition p = request
        if isActive state then
            Active ref = state
            textFieldSetPosition ref p
        setPositionImpl p    

    appendText s = request
        text := text ++ s
        
    setText s = request
        text := s
        if isActive state then
            Active ref = state
            textFieldSetText ref s
   
    getText = request
        result text

    setSize s = request
        if isActive state then
            Active ref = state
            setSizeImpl (<- textFieldSetSize ref s)
        else
            setSizeImpl s
        
    destroyComp = request
        state := destroyState state

    initComp app = request
        ref <- initTextField w
        state := Active ref
        textFieldSetText ref text
        textFieldSetPosition ref (<- getPosition)
        setSizeImpl (<- textFieldSetSize ref (<- getSize))
        result ref
                
    this = TextField{id=self;..}

    result this

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

private
extern initTextField        :: World -> Request CocoaRef
extern textFieldSetText     :: CocoaRef -> String -> Request ()
extern textFieldSetPosition :: CocoaRef -> Position -> Request ()
extern textFieldSetSize     :: CocoaRef -> Size -> Request Size