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
    keyEventResponder := Nothing
    mouseEventResponder := Nothing
    
    id = new mkCocoaID
    base = new basicComponent True Nothing "TEXT_AREA"
    addResponder = base.addResponder
    setResponders = base.setResponders
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
    handleEvent = base.handleEvent

    scrollable := (False, True)
    getScrollable = request
        result scrollable
    
    setScrollable s = action
        scrollable := s
        case (<- base.getState) of  
            Active -> 
                      (hoz,vert) = s
                      textAreaSetHorizontalScroll id hoz
                      textAreaSetVerticalScroll id vert
            _ -> 

    appendText s = action
        text := text ++ s
        
    setText s = action
        text := s
        setName s
        case (<- base.getState) of
            Active -> textAreaSetText id s
            _ ->
   
    getText = request
        result text
    
    -- setPosition
    setPosition p = action
        case (<- base.getState) of
            Active -> textAreaSetPosition id p
            _ -> 
        position := p       
    
    -- getPosition  
    getPosition = request
        result position

    setSize s = action
        size := s

    getSize = request
        result size
        
    destroy = request
        base.setState Destroyed

    -- undocumented feature in Timber, init must be placed above 'this' else we have some nice raise(2); :-)
    init app = request
            base.setState Active
            initTextArea this app
            
            inithelper
    
    inithelper = do
        textAreaSetText id text
        textAreaSetPosition id position
        textAreaSetSize id size

        (hoz,vert) = scrollable
        textAreaSetHorizontalScroll id hoz
        textAreaSetVerticalScroll id vert
        
        dts = new defaultTextScrollResponder this env
        addResponder dts
            
    this = TextArea{..}

    result this

defaultTextScrollResponder textArea env = class
    scrolledState := (1.0, 1.0)
    
    scrollTo deltaX deltaY = do
        env.stdout.write ("deltaY: " ++ (show deltaY) ++ ", deltaX: " ++ (show deltaX))
        scrolledState := (deltaX, deltaY)
        textAreaScrollTo textArea.id deltaX deltaY
    
    handleEvent (MouseEvent t) modifiers = request
        case t of
            MouseMoved pos ->
            MouseWheelScroll pos deltaX deltaY -> 
                env.stdout.write ("pos: " ++ (show deltaX) ++ "," ++ (show deltaY) ++ "\n")
                scrollTo deltaX deltaY
            _ ->                    
            
        result True
    
    handleEvent _ modifiers = request
        result False
    
    result RespondsToInputEvents {..}
--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--textArea      
extern initTextArea :: TextArea -> App -> Request ()
extern textAreaSetText :: CocoaID -> String -> Action
extern textAreaSetPosition :: CocoaID -> Position -> Action
extern textAreaSetSize :: CocoaID -> Size -> Action
extern textAreaSetHorizontalScroll :: CocoaID -> Bool -> Request ()
extern textAreaSetVerticalScroll :: CocoaID -> Bool -> Request ()
extern textAreaScrollTo :: CocoaID -> Float -> Float -> Action
