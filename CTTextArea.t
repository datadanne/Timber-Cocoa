module CTTextArea where

import CTCommon   
import POSIX

struct TextArea < Component, HasText, IsScrollable
    

--------------------------------------------------------------------------------------------------
------          ** TextArea **            ----------------------------------------------------------
mkCocoaTextArea env = class
    size := {width=200; height=17}
    text := ""
    position := {x=0; y=0}
    
    dts = new defaultTextScrollResponder this env
    base = new basicComponent True Nothing "TEXT_AREA"
    addResponder = base.addResponder
    setResponders :: [RespondsToInputEvents] -> Request ()
    setResponders rs = request
        base.setResponders (dts:rs)
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
    respondToInputEvent = base.respondToInputEvent

    scrollable := (False, True)
    getScrollable = request
        result scrollable
    
    setScrollable s = request
        scrollable := s
        case (<- base.getState) of  
            Active -> 
                      (hoz,vert) = s
                      _= textAreaSetHorizontalScroll cocoaRef hoz
                      _= textAreaSetVerticalScroll cocoaRef vert
            _ -> 

    appendText s = request
        text := text ++ s
        
    setText s = request
        text := s
        setName s
        case (<- base.getState) of
            Active -> _= textAreaSetText cocoaRef s
            _ ->
   
    getText = request
        result text
    
    -- setPosition
    setPosition p = request
        case (<- base.getState) of
            Active -> _= textAreaSetPosition cocoaRef p
            _ -> 
        position := p       
    
    -- getPosition  
    getPosition = request
        result position

    setSize s = request
        case (<- base.getState) of
            Active -> _= textAreaSetSize cocoaRef s
            _ -> 
        
        size := s

    getSize = request
        result size
        
    destroy = request
        base.setState Destroyed

    -- undocumented feature in Timber, init must be placed above 'this' else we have some nice raise(2); :-)
    init app = request
            base.setState Active
            cocoaRef := initTextArea ()
            
            inithelper
    
    inithelper = do
        _= textAreaSetText cocoaRef text
        _= textAreaSetPosition cocoaRef position
        _= textAreaSetSize cocoaRef size

        (hoz,vert) = scrollable
        _= textAreaSetHorizontalScroll cocoaRef hoz
        _= textAreaSetVerticalScroll cocoaRef vert
       
        addResponder dts
        
    cocoaRef := defaultCocoaRef   
    getCocoaRef = request
        result cocoaRef 
        
    this = TextArea{id_temp=self;..}

    result this

defaultTextScrollResponder textArea env = class
    scrolledState := (1.0, 1.0)
    
    scrollTo deltaX deltaY = do
        env.stdout.write ("deltaY: " ++ (show deltaY) ++ ", deltaX: " ++ (show deltaX))
        scrolledState := (deltaX, deltaY)
        _= textAreaScrollTo (<-textArea.getCocoaRef) deltaX deltaY
    
    respondToInputEvent (MouseEvent t) modifiers = request
        case t of
            MouseMoved pos ->
            MouseWheelScroll pos deltaX deltaY -> 
                env.stdout.write ("pos: " ++ (show deltaX) ++ "," ++ (show deltaY) ++ "\n")
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
