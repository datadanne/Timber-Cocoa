module CTDropDown where

import COCOA -- remove and it breaks even with CTCommon imported below?
import CTCommon
import POSIX

struct DropDown < Component, RespondsToSelectionEvents where
    addOption :: String -> Request ()
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
    getAllChildren = base.getAllChildren
    respondToInputEvent = base.respondToInputEvent
    
    options := ["hello", "world"]
    
    addOption o = request
        _ <- insertOption o
        
    setOptions opts = action
        forall o <- opts do
            _ <- insertOption o
            
    insertOption o = do
        options := o : options
        case (<- base.getState) of
            Active ->
                    _ = dropDownAddOption cocoaRef o  
                    currentOption := dropDownGetSelectedOption cocoaRef
            _ ->

    getOptions = request
        result options
    
    currentOption := ""
    refreshMyOptionAndPerformCallback = action 
        currentOption := dropDownGetSelectedOption cocoaRef
        send selectionChanged currentOption
        
    getCurrentOption = request
        --opt <- cocoaGetCurrentOption cocoaRef     TODO: do we ever need this? no should be the answer ...
        result currentOption

    setPosition p = request
        case (<- base.getState) of
            Active -> _= dropDownSetPosition cocoaRef p
            _ -> 
        position := p       

    getPosition = request
        result position

    setSize s = request
        case (<- base.getState) of
            Active -> _= dropDownSetSize cocoaRef s
            _ ->
        size := s

    getSize = request
        result size
        
    destroy = request
        base.setState Destroyed
        
    init app = request
            base.setState Active
            cocoaRef := initDropDown ()
            inithelper
    
    inithelper = do
        forall o <- options do
            _ = dropDownAddOption cocoaRef o
            
        _= dropDownSetPosition cocoaRef position
        currentOption := dropDownGetSelectedOption cocoaRef

        sh = new defaultHandler refreshMyOptionAndPerformCallback
        base.addResponder sh

    cocoaRef := defaultCocoaRef
    getCocoaRef = request
        result cocoaRef 
        
    this = DropDown{id_temp=self;..}

    result this

defaultSelectionResponder env = class
    selectionChanged str = action
    setSelectionResponder _ = request
    result RespondsToSelectionEvents {..}


data SizeState = Small | Expanded
deriving instance eqSizeState :: Eq SizeState
 
defaultHandler dropdownUpdateMethod = class 
    sizeState := Small
    
    respondToInputEvent (KeyEvent t) modifiers = request
        result False 

    respondToInputEvent (MouseEvent t) modifiers = request
        case t of
            MouseClicked pos ->
                if (sizeState == Small) then
                    sizeState := Expanded
                else
                    sizeState := Small
                    dropdownUpdateMethod
            _ ->    
        result True 

    respondToInputEvent _ modifiers = request
        result False 
        
    result RespondsToInputEvents {..}
    
--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--dropDown  
private
--extern optionWasSelected :: DropDown -> String -> ()      
extern initDropDown :: () -> Int
extern dropDownAddOption :: CocoaRef -> String -> ()
extern dropDownSetPosition :: CocoaRef -> Position -> ()
extern dropDownSetSize :: CocoaRef -> Size -> ()
--extern dropDownSetLastClickPosition :: CocoaRef -> Position -> Action
extern dropDownGetSelectedOption :: CocoaRef -> String