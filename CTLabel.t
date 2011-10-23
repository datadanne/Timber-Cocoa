module CTLabel where
            
import CTCommon

struct Label < Component, HasText where
    setTextColor :: Color -> Request ()
    getTextColor :: Request Color

mkCocoaLabel = class
    size := {width=0; height=0}
    mouseEventResponder := Nothing          
    textColor := {r=0;g=0;b=0}
    text := "Default Label"
    cocoaRef := defaultCocoaRef   
    getCocoaRef = request
        result cocoaRef

    id = new mkCocoaID
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
            Active -> labelSetText id s
            _ ->

    getText = request
        result text     

    appendText s = request
        text := text ++ s
    
    setTextColor c = request
        case (<- base.getState) of
            Active -> labelSetTextColor id c
            _ ->
        textColor := c
    
    getTextColor = request
        result textColor
    
    setPosition p = request  
        case (<- base.getState) of
            Active -> labelSetPosition id p
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
            initLabel this app
            
            inithelper
    
    inithelper = do
        labelSetText id text
        labelSetPosition id (<- base.getPosition)
        labelSetSize id size  
        labelSetTextColor id textColor
            
    this = Label{id_temp=self;..}

    result this  

-- extern stuff --
private
extern initLabel :: Label -> App -> Request ()
extern labelSetText :: CocoaID -> String -> Action
extern labelSetPosition :: CocoaID -> Position -> Action    
extern labelSetSize :: CocoaID -> Size -> Action           
extern labelSetTextColor :: CocoaID -> Color -> Action