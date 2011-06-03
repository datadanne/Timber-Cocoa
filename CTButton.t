module CTButton where

import CTCommon   
import POSIX

struct Button < Component, HandlesMouseEvents, HandlesKeyEvents where
    setTitle :: String -> Action
    getTitle :: Request String

--------------------------------------------------------------------------------------------------
------          ** BUTTON **            ----------------------------------------------------------
mkCocoaButton env = class
    myState := Inactive
    position := {x=0; y=0}
    size := {width=108; height=17}
    mouseEventHandler := Nothing
    keyEventHandler := Nothing
    
    id = new mkCocoaID
    title := "TestButton"
    
    -- setTitle
    setTitle s = action
        title := s
        case (myState) of
            Active -> buttonSetTitle id s
            _ ->
   
    -- getTitle
    getTitle = request
        result title   
    
    -- setPosition
    setPosition p = action
        case (myState) of
            Active -> buttonSetPosition id p
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
        myState := Destroyed

    focus = new focusWrapper this True
    
    setNextFocusTarget c = request
        if (isJust c) then
            env.stdout.write (name ++ " is changing focus to " ++ (<- showName c))
        else
            env.stdout.write (name ++ " is changing focus to NOTHING\n")
        res <- focus.setNextFocusTarget c
        
    getNextFocusTarget = request
        res <- focus.getNextFocusTarget                                       
        if (isJust res) then
            env.stdout.write (name ++ " is asked for getNextFocusTarget, returning TRUE\n")
        else
            env.stdout.write (name ++ " is asked for getNextFocusTarget, returing FALSE\n")
        result res
        
    setPreviousFocusTarget = focus.setPreviousFocusTarget
    getPreviousFocusTarget = focus.getPreviousFocusTarget
    setIsFocusable =  focus.setIsFocusable
    getIsFocusable = focus.getIsFocusable 

    name := "button"
    setName s = request
        name := s
    getName = request
        result name    
        
    installKeyListener kl = request
        keyEventHandler := Just kl

    installMouseListener ml = request
        mouseEventHandler := Just ml

    handleEvent (KeyEvent t) modifiers = request
        result (boolToMaybe (Just this) (<- dynamicHandleEvent t keyEventHandler))

    handleEvent (MouseEvent t) modifiers = request
        result (boolToMaybe (Just this) (<- dynamicHandleEvent t mouseEventHandler))
    
    handleEvent _ modifiers = request
        result Nothing

    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
            myState := Active
            initButton this app
            
            inithelper
    
    inithelper = do
        buttonSetTitle id title
        buttonSetPosition id position
            
    this = Button{..}

    result this

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--button      
extern initButton :: Button -> App -> Request ()
extern buttonSetTitle :: CocoaID -> String -> Action
extern buttonSetPosition :: CocoaID -> Position -> Action
