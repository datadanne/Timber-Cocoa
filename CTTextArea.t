module CTTextArea where

import COCOA

struct TextArea < Component, HasText, IsScrollable

mkCocoaTextArea :: World -> Class TextArea
mkCocoaTextArea w = class   
    state := Inactive
    getState = request
        result state
        
    dts = new defaultTextScrollResponder this
    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl;setResponders=setRespondersImpl..} = 
        new basicComponent True Nothing "TextArea"

    setPosition p = request
        if isActive state then
            Active ref = state
            textAreaSetPosition ref p 
        setPositionImpl p

    setSize s = request
        if isActive state then
            Active ref = state
            textAreaSetSize ref s
        setSizeImpl s

    setResponders rs = request
        setRespondersImpl (dts:rs)

    documentSize := {width=1; height=1}
    getDocumentSize = request
        result documentSize
    
    setDocumentSize s = request
        documentSize := s
        if isActive state then
            Active ref = state
            textAreaSetDocumentSize ref s

    text := ""
    getText = request
        result text      
        
    appendText s = request
        text := text ++ s
        if isActive state then
            Active ref = state
            textAreaSetText ref text
        
    setText s = request
        text := s
        if isActive state then
            Active ref = state
            textAreaSetText ref s
    
    destroyComp = request
        state := destroyState state

    initComp app = request
        ref <- initTextArea w
        state := Active ref
        
        textAreaSetText ref text
        textAreaSetPosition ref (<- getPosition)
        textAreaSetSize ref (<- getSize)
        textAreaSetDocumentSize ref documentSize
       
        addResponder dts
        result ref
        
    this = TextArea{id=self;..}

    result this

defaultTextScrollResponder textArea = class
    scrolledState := (1.0, 1.0)
    
    scrollTo deltaX deltaY = do
        scrolledState := (deltaX, deltaY)
        state <- textArea.getState
        if isActive state then
            Active ref = state
            textAreaScrollTo ref deltaX deltaY
    
    respondToInputEvent (MouseEvent t) _ = request
        case t of
            MouseMoved pos ->
            MouseWheelScroll pos deltaX deltaY -> 
                scrollTo deltaX deltaY
            _ ->                    
        result True
    
    respondToInputEvent _ _ = request
        result False
    
    result RespondsToInputEvents {..}
    
--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

extern initTextArea                :: World -> Request CocoaRef
extern textAreaSetText             :: CocoaRef -> String -> Request ()
extern textAreaSetPosition         :: CocoaRef -> Position -> Request ()
extern textAreaSetSize             :: CocoaRef -> Size -> Request ()
extern textAreaSetDocumentSize     :: CocoaRef -> Size -> Request ()
extern textAreaScrollTo            :: CocoaRef -> Float -> Float -> Request ()
