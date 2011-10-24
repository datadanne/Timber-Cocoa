module CTTextField where

import CTCommon   
import POSIX

struct TextField < Component, HasText, IsScrollable    

--------------------------------------------------------------------------------------------------
------          ** TextField **            ----------------------------------------------------------
mkCocoaTextField env = class
    size := {width=200; height=17}
    text := ""
    position := {x=0; y=0}

    base = new basicComponent True Nothing "TEXT_AREA"
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
        case (<- base.getState) of
            Active -> _= textFieldSetText cocoaRef s
            _ ->
   
    getText = request
        result text
    
    -- setPosition
    setPosition p = request
        case (<- base.getState) of
            Active -> _= textFieldSetPosition cocoaRef p
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

    -- undocumented feature in Timber, init must be placed above 'this' else we have some nice raise(2); :-)
    init app = request
            base.setState Active
            cocoaRef := initTextField ()
            inithelper
    
    inithelper = do
        _= textFieldSetText cocoaRef text
        _= textFieldSetPosition cocoaRef position
    
    cocoaRef := defaultCocoaRef   
    getCocoaRef = request
        result cocoaRef
                
    this = TextField{id_temp=self;..}

    result this

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--textField      
private
extern initTextField :: () -> CocoaRef
extern textFieldSetText :: CocoaRef -> String -> ()
extern textFieldSetPosition :: CocoaRef -> Position -> ()
