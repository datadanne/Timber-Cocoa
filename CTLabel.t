module CTLabel where
            
import CTCommon

struct Label < Component, HandlesMouseEvents where
    setText :: String -> Action
    getText :: Request String  
    setTextColor :: Color -> Action
    getTextColor :: Request Color

mkCocoaLabel = class
    myState := Inactive
    position := {x=0; y=0}
    size := {width=0; height=0}
    mouseEventHandler := Nothing          
    textColor := {r=0;g=0;b=0}
    text := "Default Label"
    
    id = new mkCocoaID

    focus = new focusWrapper this False
    setNextFocusTarget = focus.setNextFocusTarget
    getNextFocusTarget = focus.getNextFocusTarget
    setPreviousFocusTarget = focus.setPreviousFocusTarget
    getPreviousFocusTarget = focus.getPreviousFocusTarget
    setIsFocusable =  focus.setIsFocusable
    getIsFocusable = focus.getIsFocusable
    
    name := "label"
    setName s = request
        name := s
    getName = request
        result name   
            
    setText s = action
        text := s
        case (myState) of
            Active -> labelSetText id s
            _ ->

    getText = request
        result text     

    
    setTextColor c = action
        case (myState) of
            Active -> labelSetTextColor id c
            _ ->
            
        textColor := c
    
    getTextColor = request
        result textColor
    
    setPosition p = action  
        case (myState) of
            Active -> labelSetPosition id p
            _ -> 
            
        position := p       
    
    getPosition = request
        result position

    setSize s = action
        size := s

    getSize = request
        result size
        
    destroy = request
        myState := Destroyed
                            
    -- handles mouse events
    installMouseListener ml = request
        mouseEventHandler := Just ml
                             
    handleEvent (MouseEvent t) modifiers = request
        result (boolToMaybe (Just this) (<- dynamicHandleEvent t mouseEventHandler))
    
    handleEvent _ modifiers = request
        result Nothing

    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
            myState := Active
            initLabel this app
            
            inithelper
    
    inithelper = do
        labelSetText id text
        labelSetPosition id position
        labelSetSize id size  
        labelSetTextColor id textColor
            
    this = Label{..}

    result this  

-- extern stuff --
extern initLabel :: Label -> App -> Request ()
extern labelSetText :: CocoaID -> String -> Action
extern labelSetPosition :: CocoaID -> Position -> Action    
extern labelSetSize :: CocoaID -> Size -> Action           
extern labelSetTextColor :: CocoaID -> Color -> Action