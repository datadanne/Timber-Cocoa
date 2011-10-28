module CTDropDown where

import COCOA

struct DropDown < Component, RespondsToSelectionEvents, HasSelectionResponder where
    addOption :: String -> Request ()
    setOptions :: [String] -> Action
    getOptions :: Request [String]
    getCurrentOption :: Request String

--------------------------------------------------------------------------------------------------
------          ** CTDropDown **        ----------------------------------------------------------

mkCocoaDropDown :: Class DropDown
mkCocoaDropDown = class

    state        := Inactive
    size         := {width=108; height=17}
--  extendedSize := {width=108; height=17}
--  sizeState    := Small
    title        := "DropDown"    

    BaseComponent {setPosition=setPositionImpl;setSize=dummy1;getSize=dummy2;..} = 
        new basicComponent True Nothing "DropDown"
    
    setPosition p = request
        if isActive state then
            Active ref = state
            _ = dropDownSetPosition ref p
        setPositionImpl p
    
    setSize s = request
        if isActive state then
            Active ref = state
            _ = dropDownSetSize ref s
        size := s
    
    getSize = request
        result size

    dsh := new defaultSelectionResponder
    selectionChanged str = action
        dsh.selectionChanged str
    setSelectionResponder resp = request
        dsh := resp
    
    options := []
    addOption o = request
        _ <- insertOption o
    setOptions opts = action
        options := []
        forall o <- (reverse opts) do
            _ <- insertOption o
    insertOption o = do
        options := o : options
        if isActive state then
            Active ref = state
            _ = dropDownAddOption ref o  
            currentOption := dropDownGetSelectedOption ref
    getOptions = request
        result options
    
    currentOption := ""
    refreshMyOptionAndPerformCallback = action
        if isActive state then
            Active ref = state
            currentOption := dropDownGetSelectedOption ref
            send selectionChanged currentOption
    getCurrentOption = request
        result currentOption     
        
    destroyComp = request
        state := Destroyed
    
    getState = request
        result state
        
    initComp app = request
            ref = initDropDown ()
            state := Active ref
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

defaultSelectionResponder = class
    selectionChanged str = action
    setSelectionResponder _ = request
    result RespondsToSelectionEvents {..}

data SizeState = Small | Expanded
 
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

private

extern initDropDown              :: () -> Int
extern dropDownAddOption         :: CocoaRef -> String -> ()
extern dropDownSetPosition       :: CocoaRef -> Position -> ()
extern dropDownSetSize           :: CocoaRef -> Size -> ()
extern dropDownGetSelectedOption :: CocoaRef -> String