module CTLabel where
            
import COCOA

struct Label < Component, HasText where
    setTextColor :: Color -> Request ()
    getTextColor :: Request Color

mkCocoaLabel :: World -> Class Label
mkCocoaLabel w = class
    state := Inactive
    textColor := {r=0;g=0;b=0}
    text := "Default Label"

    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl..} = new basicComponent False Nothing "Label"

    setPosition p = request  
        if isActive state then
            Active ref = state
            labelSetPosition ref p
        setPositionImpl p

    setSize s = request
        if isActive state then
            Active ref = state
            labelSetSize ref s
        setSizeImpl s

    setText s = request
        text := s
        if isActive state then
            Active ref = state
            labelSetText ref s

    getText = request
        result text     

    appendText s = request
        text := text ++ s
    
    setTextColor c = request
        if isActive state then
            Active ref = state
            labelSetTextColor ref c
        textColor := c
    
    getTextColor = request
        result textColor
        
    destroyComp = request
        state := destroyState state
    
    getState = request
        result state
                            
    initComp app = request
            ref <- initLabel w
            state := Active ref
            labelSetText ref text
            labelSetPosition ref (<- getPosition)
            labelSetSize ref (<- getSize)
            labelSetTextColor ref textColor
            result ref
        
    this = Label{id=self;..}

    result this  

private

extern initLabel         :: World -> Request CocoaRef
extern labelSetText      :: CocoaRef -> String -> Request ()
extern labelSetPosition  :: CocoaRef -> Position -> Request ()    
extern labelSetSize      :: CocoaRef -> Size -> Request ()       
extern labelSetTextColor :: CocoaRef -> Color -> Request ()