module CTTextArea where

import COCOA

struct TextArea < Component, HasText, IsScrollable

mkCocoaTextArea = class
    text := ""
    
    state := Inactive
    getState = request
        result state
        
    dts = new defaultTextScrollResponder this
    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl;setResponders=setRespondersImpl..} = new basicComponent True Nothing "TextArea"

    setResponders :: [RespondsToInputEvents] -> Request ()
    setResponders rs = request
        setRespondersImpl (dts:rs)

    scrollable := (False, True)
    getScrollable = request
        result scrollable
    
    setScrollable s = request
        scrollable := s
        if isActive state then
            Active ref = state
            (hoz,vert) = s
            _ = textAreaSetHorizontalScroll ref hoz
            _ = textAreaSetVerticalScroll ref vert

    appendText s = request
        text := text ++ s
        
    setText s = request
        text := s
        if isActive state then
            Active ref = state
            _= textAreaSetText ref s
   
    getText = request
        result text
    
    -- setPosition
    setPosition p = request
        if isActive state then
            Active ref = state
            _ = textAreaSetPosition ref p 
        setPositionImpl p

    setSize s = request
        if isActive state then
            Active ref = state
            _ = textAreaSetSize ref s
        setSizeImpl s

    destroyComp = request
        state := Destroyed

    -- undocumented feature in Timber, init must be placed above 'this' else we have some nice raise(2); :-)
    initComp app = request
        ref = initTextArea ()
        state := Active ref
        
        _= textAreaSetText ref text
        _= textAreaSetPosition ref (<- getPosition)
        _= textAreaSetSize ref (<- getSize)

        (hoz,vert) = scrollable
        _= textAreaSetHorizontalScroll ref hoz
        _= textAreaSetVerticalScroll ref vert
       
        addResponder dts
        result ref
        
    this = TextArea{id=self;..}

    result this

defaultTextScrollResponder textArea = class
    scrolledState := (1.0, 1.0)
    
    scrollTo deltaX deltaY = do
        scrolledState := (deltaX, deltaY)
        case (<-textArea.getState) of
            (Active ref) -> _= textAreaScrollTo ref deltaX deltaY
            _ ->
    
    respondToInputEvent (MouseEvent t) modifiers = request
        case t of
            MouseMoved pos ->
            MouseWheelScroll pos deltaX deltaY -> 
                scrollTo deltaX deltaY
            _ ->                    
            
        result True
    
    respondToInputEvent _ modifiers = request
        result False
    
    result RespondsToInputEvents {..}
--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--textArea      
extern initTextArea :: () -> CocoaRef
extern textAreaSetText :: CocoaRef -> String -> ()
extern textAreaSetPosition :: CocoaRef -> Position -> ()
extern textAreaSetSize :: CocoaRef -> Size -> ()
extern textAreaSetHorizontalScroll :: CocoaRef -> Bool -> ()
extern textAreaSetVerticalScroll :: CocoaRef -> Bool -> ()
extern textAreaScrollTo :: CocoaRef -> Float -> Float -> ()
