module CTLabel where
            
import CTCommon

struct Label < Component, HasText where
    setTextColor :: Color -> Request ()
    getTextColor :: Request Color

mkCocoaLabel = class
    size := {width=0; height=0}
    textColor := {r=0;g=0;b=0}
    text := "Default Label"

    base = new basicComponent False Nothing "Label"
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
    respondToInputEvent = base.respondToInputEvent

    setText s = request
        text := s
        case (<- base.getState) of
            Active -> _= labelSetText cocoaRef s
            _ ->

    getText = request
        result text     

    appendText s = request
        text := text ++ s
    
    setTextColor c = request
        case (<- base.getState) of
            Active -> _= labelSetTextColor cocoaRef c
            _ ->
        textColor := c
    
    getTextColor = request
        result textColor
    
    setPosition p = request  
        case (<- base.getState) of
            Active -> _= labelSetPosition cocoaRef p
            _ ->
        base.setPosition p  
    
    getPosition = base.getPosition

    setSize s = request
        size := s

    getSize = request
        result size
        
    destroy = request
        base.setState Destroyed
                            
    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
            base.setState Active
            cocoaRef := initLabel ()
            inithelper
    
    inithelper = do
        _= labelSetText cocoaRef text
        _= labelSetPosition cocoaRef (<- base.getPosition)
        _= labelSetSize cocoaRef size  
        _= labelSetTextColor cocoaRef textColor

    cocoaRef := defaultCocoaRef   
    getCocoaRef = request
        result cocoaRef 
        
    this = Label{id_temp=self;..}

    result this  

-- extern stuff --
private
extern initLabel :: () -> CocoaRef
extern labelSetText :: CocoaRef -> String -> ()
extern labelSetPosition :: CocoaRef -> Position -> ()    
extern labelSetSize :: CocoaRef -> Size -> ()       
extern labelSetTextColor :: CocoaRef -> Color -> ()