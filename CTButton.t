module CTButton where

import COCOA   
import POSIX

struct Button < Component where
    setTitle :: String -> Request ()
    getTitle :: Request String

--------------------------------------------------------------------------------------------------
------          ** BUTTON **            ----------------------------------------------------------

mkCocoaButton env = class
    title := "Click me!"
    defaultSize= {width=108; height=21}
    
    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl..} = new basicComponent True Nothing "BUTTON"

    -- setTitle
    setTitle s = request
        title := s
        setName s
        case (<- getState) of
            Active ref -> _ = buttonSetTitle ref s
            _ ->
   
    -- getTitle
    getTitle = request
        result title   
    
    -- setPosition
    setPosition p = request
        case (<- getState) of
            Active ref -> _= buttonSetPosition ref p
            _ -> 
        setPositionImpl p

    setSize s = request
        setSizeImpl = case (<- getState) of
            Active ref -> (buttonSetSize ref s)
            _ -> s

    destroyComp = request
        setState Destroyed

    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    initComp app = request
        ref = initButton title
        setState (Active ref)
        setSizeImpl (buttonSetSize ref (<- getSize))
        _ = buttonSetPosition ref (<- getPosition)
        result ref


    this = Button{id = self;..}

    result this

private 
extern initButton :: String -> CocoaRef
extern buttonSetTitle :: CocoaRef -> String -> ()
extern buttonSetPosition :: CocoaRef -> Position -> ()
extern buttonSetSize :: CocoaRef -> Size -> Size