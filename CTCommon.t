module CTCommon where

import COCOA
    
struct HasText where
    setText :: String -> Request ()
    getText :: Request String
    appendText :: String -> Request ()

struct DefaultEventResponder < HasResponders, RespondsToInputEvents

basicHasResponders = class

    handlers := []
    addResponder a = request
        handlers := a : handlers

    setResponders aa = request
        handlers := aa
    
    getResponders = request
        result handlers
    
    -- Return true (block cocoa) if any of the installed handlers say so.
    returnVal := False    
    --res := False
    respondToInputEvent inputEvent modifiers = request
        returnVal := False
        forall h <- handlers do
            if returnVal == False then
                returnVal := <- h.respondToInputEvent inputEvent modifiers
        result returnVal
    

    result DefaultEventResponder {..}

basicComponent f p n = class

    baseResponder = new basicHasResponders
    addResponder = baseResponder.addResponder
    setResponders = baseResponder.setResponders
    getResponders = baseResponder.getResponders
    respondToInputEvent = baseResponder.respondToInputEvent

    nameWrap = new wrapper n
    getName = nameWrap.get
    setName = nameWrap.set
    
    parentWrap = new wrapper p
    getParent = parentWrap.get
    setParent = parentWrap.set

    focusWrap = new wrapper f
    getIsFocusable = focusWrap.get
    setIsFocusable = focusWrap.set
    
    positionWrap = new wrapper ({x=0; y=0})
    getPosition = positionWrap.get
    setPosition = positionWrap.set
    
    sizeWrap = new wrapper ({width=100; height=100})
    getSize = sizeWrap.get
    setSize = sizeWrap.set
    
    {-state := Inactive 
    getState = request
        result state
        
    setState s = request
        if (state /= Destroyed) then
            state := s -}
    stateWrap = new wrapper Inactive
    getState = stateWrap.get
    setState = stateWrap.set
    
    getAllComponents = request
        result []
    
    result BaseComponent {..}

struct Wrapper a where
    set :: a -> Request ()
    get :: Request a
    
wrapper s = class

    a := s
    set b = request a := b
    get = request result a
        
    result Wrapper {..}

