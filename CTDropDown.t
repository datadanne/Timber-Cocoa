module CTDropDown where

import CTCommon   
import POSIX

struct DropDown < Component, HandlesMouseEvents, HandlesKeyEvents where
    addOption :: String -> Action
    setOptions :: [String] -> Action
    getOptions :: Request [String]
    getCurrentOption :: Request String

--------------------------------------------------------------------------------------------------
------          ** BUTTON **            ----------------------------------------------------------
mkCocoaDropDown env = class
    size := {width=108; height=17}
    title := ""
    position := {x=0; y=0}
    keyEventHandler := Nothing
    mouseEventHandler := Nothing
    
    id = new mkCocoaID
    base = new basicComponent True Nothing "DropDown"
    setParent = base.setParent
    getParent = base.getParent
    setIsFocusable = base.setIsFocusable
    getIsFocusable = base.getIsFocusable
    setName = base.setName
    getName = base.getName
    getState = base.getState
    setState = base.setState
    getAllComponents = base.getAllComponents
    
    options := []
    
    addOption o = action
        --options := o : options
        case (<- base.getState) of
            Active ->  dropDownAddOption id o
            _ ->
        
    setOptions os = action
        options := os
        forall o <- os do
            addOption o
        
    getOptions = request
        result options
    
    currentOption := ""
    getCurrentOption = request
        currentOption := "hello"
        --opt <- cocoaGetCurrentOption id
        result currentOption

    -- setPosition
    setPosition p = request
        case (<- base.getState) of
            Active -> dropDownSetPosition id p
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

    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
            base.setState Active
            initDropDown this app
            
            inithelper
    
    inithelper = do
        setOptions options
        dropDownSetPosition id position
            
    this = DropDown{..}

    result this

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--dropDown      
extern initDropDown :: DropDown -> App -> Request ()
extern dropDownAddOption :: CocoaID -> String -> Action
extern dropDownSetPosition :: CocoaID -> Position -> Action
