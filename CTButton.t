module CTButton where

import CTCommon   
import POSIX

struct Button < Component where
    setTitle :: String -> Request ()
    getTitle :: Request String

--------------------------------------------------------------------------------------------------
------          ** BUTTON **            ----------------------------------------------------------

mkCocoaButton env = class
    size := {width=108; height=21}
    title := "Click me!"
    position := {x=0; y=0}

    BaseComponent {..} = new basicComponent True Nothing "BUTTON"
    
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
        position := p       
    
    -- getPosition  
    getPosition = request
        result position

    setSize s = request
        case (<- getState) of
            Active ref -> size := buttonSetSize ref s
            _ -> size := s

    getSize = request
        result size
        
    destroy = request
        setState Destroyed

    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
        ref = initButton title
        setState (Active ref)
        size := buttonSetSize ref size
        _ = buttonSetPosition ref position

    getCocoaRef = request
        case (<-getState) of
            Active ref -> result Just ref
            _ -> result Nothing
        
    this = Button{id_temp=self;..}

    result this

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--button     
private 
extern initButton :: String -> CocoaRef
extern buttonSetTitle :: CocoaRef -> String -> ()
extern buttonSetPosition :: CocoaRef -> Position -> ()
extern buttonSetSize :: CocoaRef -> Size -> Size