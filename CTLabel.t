module CTLabel where
            
import COCOA

struct Label < Component, HasText where
    setTextColor :: Color -> Request ()
    getTextColor :: Request Color

mkCocoaLabel = class
    textColor := {r=0;g=0;b=0}
    text := "Default Label"

    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl..} = new basicComponent False Nothing "Label"

    setText s = request
        text := s
        case (<- getState) of
            Active ref -> _= labelSetText ref s
            _ ->

    getText = request
        result text     

    appendText s = request
        text := text ++ s
    
    setTextColor c = request
        case (<- getState) of
            Active ref -> _= labelSetTextColor ref c
            _ ->
        textColor := c
    
    getTextColor = request
        result textColor
    
    setPosition p = request  
        case (<- getState) of
            Active ref-> _= labelSetPosition ref p
            _ ->
        setPositionImpl p  

    setSize s = request
        case (<- getState) of
            Active ref -> _= labelSetSize ref s
            _ ->
        setSizeImpl s
        
    destroyComp = request
        setState Destroyed
                            
    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    initComp app = request
            ref = initLabel ()
            setState (Active ref)
            _= labelSetText ref text
            _= labelSetPosition ref (<- getPosition)
            _= labelSetSize ref (<- getSize)
            _= labelSetTextColor ref textColor
            result ref

        
    this = Label{id=self;..}

    result this  

-- extern stuff --
private
extern initLabel :: () -> CocoaRef
extern labelSetText :: CocoaRef -> String -> ()
extern labelSetPosition :: CocoaRef -> Position -> ()    
extern labelSetSize :: CocoaRef -> Size -> ()       
extern labelSetTextColor :: CocoaRef -> Color -> ()