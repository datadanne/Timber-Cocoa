module CTTextField where

import COCOA   

struct TextField < Component, HasText    

mkCocoaTextField = class
    text := ""

    state := Inactive
    getState = request
        result state

    BaseComponent {setPosition=setPositionImpl;..} = new basicComponent True Nothing "TextField"
    setPosition p = request
        if isActive state then
            Active ref = state
            _ = textFieldSetPosition ref p
        setPositionImpl p    

    appendText s = request
        text := text ++ s
        
    setText s = request
        text := s
        if isActive state then
            Active ref = state
            _ = textFieldSetText ref s
   
    getText = request
        result text
        
    destroyComp = request
        state := destroyState state

    initComp app = request
        ref = initTextField ()
        state := Active ref
        _ = textFieldSetText ref text
        _ = textFieldSetPosition ref (<- getPosition)
        result ref
                
    this = TextField{id=self;..}

    result this

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

private
extern initTextField        :: () -> CocoaRef
extern textFieldSetText     :: CocoaRef -> String -> ()
extern textFieldSetPosition :: CocoaRef -> Position -> ()
