module CTLabel where
            
import COCOA

struct Label < Component, HasText where
    setTextColor :: Color -> Request ()
    getTextColor :: Request Color

mkCocoaLabel = class
    state := Inactive
    textColor := {r=0;g=0;b=0}
    text := "Default Label"

    BaseComponent {setPosition=setPositionImpl;setSize=setSizeImpl..} = new basicComponent False Nothing "Label"

    setPosition p = request  
        if isActive state then
            Active ref = state
            _ = labelSetPosition ref p
        setPositionImpl p

    setSize s = request
        if isActive state then
            Active ref = state
            _ = labelSetSize ref s
        setSizeImpl s

    setText s = request
        text := s
        if isActive state then
            Active ref = state
            _ = labelSetText ref s

    getText = request
        result text     

    appendText s = request
        text := text ++ s
    
    setTextColor c = request
        if isActive state then
            Active ref = state
            _ = labelSetTextColor ref c
        textColor := c
    
    getTextColor = request
        result textColor
        
    destroyComp = request
        state := Destroyed
    
    getState = request
        result state
                            
    initComp app = request
            ref = initLabel ()
            state := Active ref
            _= labelSetText ref text
            _= labelSetPosition ref (<- getPosition)
            _= labelSetSize ref (<- getSize)
            _= labelSetTextColor ref textColor
            result ref
        
    this = Label{id=self;..}

    result this  

private

extern initLabel         :: () -> CocoaRef
extern labelSetText      :: CocoaRef -> String -> ()
extern labelSetPosition  :: CocoaRef -> Position -> ()    
extern labelSetSize      :: CocoaRef -> Size -> ()       
extern labelSetTextColor :: CocoaRef -> Color -> ()