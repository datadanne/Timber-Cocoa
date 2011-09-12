module CTTextField where

import CTCommon   
import POSIX

struct TextField < Component, HasText, HandlesMouseEvents, HandlesKeyEvents where
    appendText :: String -> Action
    

--------------------------------------------------------------------------------------------------
------          ** TextField **            ----------------------------------------------------------
mkCocoaTextField env = class
    size := {width=200; height=17}
    text := ""
    position := {x=0; y=0}
    keyEventHandler := Nothing
    mouseEventHandler := Nothing
    
    id = new mkCocoaID
    base = new basicComponent True Nothing "TEXT_AREA"
    setParent = base.setParent
    getParent = base.getParent
    setIsFocusable = base.setIsFocusable
    getIsFocusable = base.getIsFocusable
    setName = base.setName
    getName = base.getName
    getState = base.getState
    setState = base.setState
    getAllComponents = base.getAllComponents


    appendText s = action
        text := text ++ s
        
    setText s = request
        text := s
        setName s
        case (<- base.getState) of
            Active -> textFieldSetText id s
            _ ->
   
    getText = request
        result text
    
    -- setPosition
    setPosition p = request
        case (<- base.getState) of
            Active -> textFieldSetPosition id p
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
        
    installKeyListener kl = request
        keyEventHandler := Just kl

    installMouseListener ml = request
        mouseEventHandler := Just ml

    handleEvent (KeyEvent t) modifiers = request
        result (boolToMaybe (Just this) (<- dynamicHandleEvent t keyEventHandler))

    handleEvent (MouseEvent t) modifiers = request
        result (boolToMaybe (Just this) (<- dynamicHandleEvent t mouseEventHandler))
    
    handleEvent _ modifiers = request
        result Nothing

    -- undocumented feature in Timber, init must be placed above 'this' else we have some nice raise(2); :-)
    init app = request
            base.setState Active
            initTextField this app
            
            inithelper
    
    inithelper = do
        textFieldSetText id text
        textFieldSetPosition id position
            
    this = TextField{..}

    result this

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--textField      
extern initTextField :: TextField -> App -> Request ()
extern textFieldSetText :: CocoaID -> String -> Action
extern textFieldSetPosition :: CocoaID -> Position -> Action
