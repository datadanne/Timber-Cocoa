module CTDropDown where

import COCOA

struct DropDown < Component, RespondsToSelectionEvents, HasSelectionResponder where
    addOption :: String -> Request ()
    setOptions :: [String] -> Action
    getOptions :: Request [String]
    getCurrentOption :: Request String

--------------------------------------------------------------------------------------------------
------          ** CTDropDown **        ----------------------------------------------------------

mkCocoaDropDown :: World -> Class DropDown
mkCocoaDropDown w = class

    state        := Inactive
    size         := {width=108; height=17}
    title        := "DropDown"    

    BaseComponent {setPosition=setPositionImpl;setSize=dummy1;getSize=dummy2;..} = 
        new basicComponent True Nothing "DropDown"
    
    setPosition p = request
        if isActive state then
            Active ref = state
            dropDownSetPosition ref p
        setPositionImpl p
    
    setSize s = request
        if isActive state then
            Active ref = state
            size := (<- dropDownSetSize ref s)
        else 
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
        insertOption o
    setOptions opts = action
        options := []
        forall o <- (reverse opts) do
            insertOption o
    insertOption o = do
        options := o : options
        if isActive state then
            Active ref = state
            dropDownAddOption ref o  
            currentOption := (<- dropDownGetSelectedOption ref)
    getOptions = request
        result options
    
    currentOption := ""
    refreshMyOptionAndPerformCallback = action
        if isActive state then
            Active ref = state
            currentOption := (<- dropDownGetSelectedOption ref)
            send selectionChanged currentOption
    getCurrentOption = request
        result currentOption     
        
    destroyComp = request
        state := destroyState state
    
    getState = request
        result state
        
    initComp app = request
            ref <- initDropDown w
            state := Active ref
            forall o <- options do
                dropDownAddOption ref o
            dropDownSetPosition ref (<- getPosition)
            size := (<- dropDownSetSize ref size)
            currentOption := (<- dropDownGetSelectedOption ref)
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
        result NotConsumed 
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
        result Consumed 
    respondToInputEvent _ modifiers = request
        result NotConsumed 
    result RespondsToInputEvents {..}
    
--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

private

extern initDropDown              :: World -> Request CocoaRef
extern dropDownAddOption         :: CocoaRef -> String -> Request ()
extern dropDownSetPosition       :: CocoaRef -> Position -> Request ()
extern dropDownSetSize           :: CocoaRef -> Size -> Request Size
extern dropDownGetSelectedOption :: CocoaRef -> Request String