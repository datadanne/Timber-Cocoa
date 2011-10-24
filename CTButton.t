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

    base = new basicComponent True Nothing "BUTTON"
    addResponder = base.addResponder
    setResponders = base.setResponders
    getResponders = base.getResponders
    setParent = base.setParent
    getParent = base.getParent
    setIsFocusable = base.setIsFocusable
    getIsFocusable = base.getIsFocusable
    setName = base.setName
    getName = base.getName
    getState = base.getState
    setState = base.setState
    getAllComponents = base.getAllComponents
    respondToInputEvent = base.respondToInputEvent
    
    -- setTitle
    setTitle s = request
        title := s
        setName s
        case (<- base.getState) of
            Active -> _ = buttonSetTitle cocoaRef s
            _ ->
   
    -- getTitle
    getTitle = request
        result title   
    
    -- setPosition
    setPosition p = request
        case (<- base.getState) of
            Active -> _= buttonSetPosition cocoaRef p
            _ -> 
        position := p       
    
    -- getPosition  
    getPosition = request
        result position

    setSize s = request
        case (<- base.getState) of
            Active -> size := buttonSetSize cocoaRef s
            _ -> size := s

    getSize = request
        result size
        
    destroy = request
        base.setState Destroyed

    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
        base.setState Active
        cocoaRef := initButton title
        size := buttonSetSize cocoaRef size
        _ = buttonSetPosition cocoaRef position

    cocoaRef := defaultCocoaRef   
    getCocoaRef = request
        result cocoaRef 
        
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