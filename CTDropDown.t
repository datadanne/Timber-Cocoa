module CTDropDown where

import COCOA -- remove and it breaks even with CTCommon imported below?
import POSIX

struct DropDown < Component, RespondsToSelectionEvents, HasSelectionResponder where
    addOption :: String -> Request ()
    setOptions :: [String] -> Action
    getOptions :: Request [String]
    getCurrentOption :: Request String

--------------------------------------------------------------------------------------------------
------          ** CTDropDown **            ----------------------------------------------------------
mkCocoaDropDown :: Env -> Class DropDown
mkCocoaDropDown env = class
    size := {width=108; height=17}
    extendedSize := {width=108; height=17}
    sizeState := Small
    title := ""    

    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl;getSize=getSizeImpl..} = new basicComponent True Nothing "DropDown"

    dsh := new defaultSelectionResponder env
    selectionChanged str = action
        dsh.selectionChanged str
        
    setSelectionResponder resp = request
        dsh := resp
    
    options := ["hello", "world"]
    
    addOption o = request
        _ <- insertOption o
        
    setOptions opts = action
        forall o <- opts do
            _ <- insertOption o
            
    insertOption o = do
        options := o : options
        case (<- getState) of
            Active ref ->
                    _ = dropDownAddOption ref o  
                    currentOption := dropDownGetSelectedOption ref
            _ ->

    getOptions = request
        result options
    
    currentOption := ""
    refreshMyOptionAndPerformCallback = action
        case (<- getState) of
            Active ref ->
                currentOption := dropDownGetSelectedOption ref
                send selectionChanged currentOption
            _ ->
        
    getCurrentOption = request
        --opt <- cocoaGetCurrentOption ref     TODO: do we ever need this? no should be the answer ...
        result currentOption

    setPosition p = request
        case (<- getState) of
            Active ref -> _= dropDownSetPosition ref p
            _ -> 
        setPositionImpl p       

    setSize s = request
        case (<- getState) of
            Active ref -> _= dropDownSetSize ref s
            _ ->
        size := s

    getSize = request
        result size
        
    destroyComp = request
        setState Destroyed
        
    initComp app = request
            ref = initDropDown ()
            setState (Active ref)
            forall o <- options do
                _ = dropDownAddOption ref o
            
            _= dropDownSetPosition ref (<- getPosition)
            _= dropDownSetSize ref size
            currentOption := dropDownGetSelectedOption ref

            sh = new defaultHandler refreshMyOptionAndPerformCallback
            addResponder sh
            
            result ref

    this = DropDown{id=self;..}

    result this

defaultSelectionResponder env = class
    selectionChanged str = action
    setSelectionResponder _ = request
    result RespondsToSelectionEvents {..}


data SizeState = Small | Expanded
-- deriving instance eqSizeState :: Eq SizeState  ... broken for some reason(?)
 
defaultHandler dropdownUpdateMethod = class 
    sizeState := Small
    
    respondToInputEvent (KeyEvent t) modifiers = request
        result False 

    respondToInputEvent (MouseEvent t) modifiers = request
        case t of
            MouseClicked pos ->
                case sizeState of
                    Small ->
                        sizeState := Expanded
                    _ ->
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