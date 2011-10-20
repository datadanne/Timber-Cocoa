module CTDropDown where

import CTCommon   
import POSIX

struct DropDown < Component, RespondsToSelectionEvents where
    addOption :: String -> Action
    setOptions :: [String] -> Action
    getOptions :: Request [String]
    getCurrentOption :: Request String

--------------------------------------------------------------------------------------------------
------          ** CTDropDown **            ----------------------------------------------------------
mkCocoaDropDown env = class
    size := {width=108; height=17}
    extendedSize := {width=108; height=17}
    sizeState := Small
    
    title := ""
    position := {x=0; y=0}
    
    id = new mkCocoaID
    base = new basicComponent True Nothing "DropDown"
    addResponder = base.addResponder
    setResponders = base.setResponders
    getResponders = base.getResponders

    dsh := new defaultSelectionResponder env
    selectionChanged str = action
        dsh.selectionChanged str
        
    setSelectionResponder resp = request
        dsh := resp
        
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
        _ <- insertOption o
    
    insertOption o = do
        options := o : options
        
        -- env.stdout.write ("adding option " ++ (show o))
        case (<- base.getState) of
            Active ->   dropDownAddOption id o  
                        currentOption := <- dropDownGetSelectedOption id
            _ ->
        
    setOptions os = action
        forall o <- os do
            _ <- insertOption o
        
    getOptions = request
        result options
    
    currentOption := ""
    
    refreshMyOptionAndPerformCallback = action 
        currentOption := <- dropDownGetSelectedOption id
        send selectionChanged currentOption
        
    getCurrentOption = request
        --opt <- cocoaGetCurrentOption id     TODO: do we ever need this? no should be the answer ...
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
        case (<- base.getState) of
            Active -> dropDownSetSize id s
            _ ->
        size := s

    getSize = request
        result size
        
    destroy = request
        base.setState Destroyed
        
    init app = request
            base.setState Active
            initDropDown this app
            
            inithelper
    
    inithelper = do
        forall o <- options do
            dropDownAddOption id o
            
        dropDownSetPosition id position
        currentOption := <- dropDownGetSelectedOption id   

        sh = new defaultHandler refreshMyOptionAndPerformCallback
        base.addResponder sh

            
    this = DropDown{..}

    result this

defaultSelectionResponder env = class
    selectionChanged str = action
    setSelectionResponder _ = request
    result RespondsToSelectionEvents {..}


data SizeState = Small | Expanded
deriving instance eqSizeState :: Eq SizeState
 
defaultHandler dropdownUpdateMethod = class 
    sizeState := Small
    
    handleEvent (KeyEvent t) modifiers = request
        result False 

    handleEvent (MouseEvent t) modifiers = request
        case t of
            MouseClicked pos ->
                if (sizeState == Small) then
                    sizeState := Expanded
                else
                    sizeState := Small
                    dropdownUpdateMethod
            _ ->    
        result True 

    handleEvent _ modifiers = request
        result False 
        
    result RespondsToInputEvents {..}
    
--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--dropDown  
private
extern optionWasSelected :: DropDown -> String -> Action      
extern initDropDown :: DropDown -> App -> Request ()
extern dropDownAddOption :: CocoaID -> String -> Action
extern dropDownSetPosition :: CocoaID -> Position -> Action
extern dropDownSetSize :: CocoaID -> Size -> Action
--extern dropDownSetLastClickPosition :: CocoaID -> Position -> Action
extern dropDownGetSelectedOption :: CocoaID -> Request String