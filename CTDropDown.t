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

    der = new defaultDropdownInputResponder refreshMyOptionAndPerformCallback        
    derAdded := False
    
    BaseComponent {setPosition=setPositionImpl;setSize=dummy1;getSize=dummy2;setResponders=setRespondersImpl;
        addResponder=addResponderImpl;..} = 
        new basicComponent True Nothing "DropDown"
    
    setPosition p = request
        if isActive state then
            Active ref = state
            dropDownSetPosition ref p
        setPositionImpl p

    getSize = request
        result size     
    setSize s = request
        if isActive state then
            Active ref = state
            size := (<- dropDownSetSize ref s)
        else 
            size := s

    addResponder r = request
        if not derAdded then
            addResponderImpl der
            derAdded := True
        addResponderImpl r
            
    setResponders rs = request
        setRespondersImpl (der:rs)        

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
        if isActive state then
            Active ref = state
            dropDownRemoveOptions ref
        forall o <- opts do
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
        if isInactive state then
            ref <- initDropDown w
            state := Active ref
            forall o <- (reverse options) do
                dropDownAddOption ref o
            dropDownSetPosition ref (<- getPosition)
            size := (<- dropDownSetSize ref size)
            currentOption := (<- dropDownGetSelectedOption ref)
            if not derAdded then
                addResponderImpl der
                derAdded := True
        result state

    this = DropDown{id=self;..}

    result this

defaultSelectionResponder = class
    selectionChanged str = action
    result RespondsToSelectionEvents {..}

data SizeState = Small | Expanded
 
defaultDropdownInputResponder dropdownUpdateMethod = class 
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
extern dropDownRemoveOptions     :: CocoaRef -> Request ()
extern dropDownSetPosition       :: CocoaRef -> Position -> Request ()
extern dropDownSetSize           :: CocoaRef -> Size -> Request Size
extern dropDownGetSelectedOption :: CocoaRef -> Request String