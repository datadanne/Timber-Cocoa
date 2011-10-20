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
    title := ""
    position := {x=0; y=0}
    keyEventResponder := Nothing
    mouseEventResponder := Nothing
    
    id = new mkCocoaID
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
            Active -> buttonSetTitle id s
            _ ->
   
    -- getTitle
    getTitle = request
        result title   
    
    -- setPosition
    setPosition p = request
        case (<- base.getState) of
            Active -> buttonSetPosition id p
            _ -> 
        position := p       
    
    -- getPosition  
    getPosition = request
        result position

    setSize s = request
        size := s

    getSize = request
        result size
        
    destroy = request
        base.setState Destroyed

    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
            base.setState Active
            initButton this app
            inithelper
    
    inithelper = do
        buttonSetTitle id title
        buttonSetPosition id position
            
    this = Button{..}

    result this

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--button     
private 
extern initButton :: Button -> App -> Request ()
extern buttonSetTitle :: CocoaID -> String -> Action
extern buttonSetPosition :: CocoaID -> Position -> Action
extern buttonHighlight:: CocoaID -> Action