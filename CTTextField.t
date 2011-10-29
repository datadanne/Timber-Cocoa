module CTTextField where

import COCOA   

struct TextField < Component, HasText, IsScrollable    

mkCocoaTextField = class
    text := ""

    state := Inactive
    getState = request
        result state

    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl..} = new basicComponent True Nothing "TextField"

    scrollable := (True, False)
    getScrollable = request
        result scrollable
    
    setScrollable s = request
        scrollable := s


    appendText s = request
        text := text ++ s
        
    setText s = request
        text := s
        setName s
        if isActive state then
            Active ref = state
            _ = textFieldSetText ref s
   
    getText = request
        result text

    setPosition p = request
        if isActive state then
            Active ref = state
            _ = textFieldSetPosition ref p
        setPositionImpl p

    setSize s = request
        setSizeImpl s
        
    destroyComp = request
        state := Destroyed

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

--textField      
private
extern initTextField :: () -> CocoaRef
extern textFieldSetText :: CocoaRef -> String -> ()
extern textFieldSetPosition :: CocoaRef -> Position -> ()
