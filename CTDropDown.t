module CTDropDown where

import CTCommon   
import POSIX

struct DropDown < Component where
    addOption :: String -> Action
    setOptions :: [String] -> Action
    getOptions :: Request [String]
    getCurrentOption :: Request String

--------------------------------------------------------------------------------------------------
------          ** BUTTON **            ----------------------------------------------------------
mkCocoaDropDown env = class
    title := ""

    id = new mkCocoaID
    base = new basicComponent True Nothing "DropDown"
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
    handleEvent = base.handleEvent
    
    options := []
    
    addOption o = action
        options := o : options
        case (<- base.getState) of
            Active ->  dropDownAddOption id o
            _ ->
        
    setOptions os = action
        options := os
        forall o <- os do
            send addOption o
        
    getOptions = request
        result options
    
    currentOption := ""
    getCurrentOption = request
        currentOption := "hello"
        --opt <- cocoaGetCurrentOption id
        result currentOption

    -- setPosition
    setPosition p = action
        case (<- base.getState) of
            Active -> dropDownSetPosition id p
            _ -> 
        base.setPosition p    
    
    -- getPosition  
    getPosition = base.getPosition

    setSize = base.setSize
    getSize = base.getSize
        
    destroy = request
        base.setState Destroyed

    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
            base.setState Active
            base.setSize ({width=108; height=17})
            initDropDown this app
            
            inithelper
    
    inithelper = do
        send setOptions options
        send dropDownSetPosition id (<- base.getPosition)
            
    this = DropDown{..}

    result this

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--dropDown      
extern initDropDown :: DropDown -> App -> Request ()
extern dropDownAddOption :: CocoaID -> String -> Action
extern dropDownSetPosition :: CocoaID -> Position -> Action
