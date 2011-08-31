module CTContainer where

import POSIX
import CTCommon

struct Container < Component, ContainsComponents, HandlesMouseEvents, HandlesKeyEvents, HasBackgroundColor

--------------------------------------------------------------------------------------------------
------          ** CONTAINER **         ----------------------------------------------------------
mkContainer env = class
    myState := Inactive
    myComponents := []        
    position := {x=0; y=0}
    size := {width=0; height=0}
    color := {r=255; g=255; b=255}
    keyEventHandler := Nothing

    appRef := Nothing
    mouseEventHandler := Nothing
    currentEventHasBeenConsumedBy := Nothing
    
    nextFocusTarget := Nothing
    previousFocusTarget := Nothing

    setPosition p = request
        case (myState) of
            Active -> containerSetPosition id p
            _ ->
        position := p

    getPosition = request
        result position

    setSize s = request
        case (myState) of
            Active -> containerSetSize id s
            _ ->
        size := s

    getSize = request
        result size

    setBackgroundColor c = request
        case (myState) of
            Active -> containerSetBackgroundColor id c
            _ ->
        color := c

    getBackgroundColor = request
        result color
        
    empty [] = True
    empty _ = False

    id = new mkCocoaID
    base = new basicComponent False Nothing "ContainerWHAT"
    setParent = base.setParent
    getParent = base.getParent
    setIsFocusable = base.setIsFocusable
    getIsFocusable = base.getIsFocusable
    setName s = request 
        env.stdout.write "in setName\n"
        base.setName s
    getName = base.getName
    getState = base.getState
    setState = base.setState
    
    children := []
    getAllComponents = request
        children := []
        
        forall c <- myComponents do
            children := (children ++ (<- c.getAllComponents) ++ [c])
        result children
    
    addComponent cmp = request
        myComponents := cmp : myComponents
        cmp.setParent (Just this)
        if (myState == Active && isJust appRef) then
            cmp.init (fromJust appRef)
            containerAddComponent id cmp.id      

    getComponents = request
        result myComponents

    destroy = request
        myState := Destroyed

    installMouseListener ml = request
        mouseEventHandler := Just ml
    
    installKeyListener kl = request
        keyEventHandler := Just kl

    handleEvent (MouseEvent t) modifiers = request
        result (boolToMaybe (Just this) (<- dynamicHandleEvent t mouseEventHandler))
        --result <- mouseEventDispatcher t modifiers
    
    handleEvent _ modifiers = request
        result Nothing
                  
{-    mouseEventDispatcher event modifiers = do
        currentEventHasBeenConsumedBy := Nothing

        pos = posget event
        et = getType event                                
        pos2 = ({x=pos.x-position.x;y=pos.y-position.y})

        -- "create" new event to the containers coordsystem
        eventInNewCoordsystem = ((getType event) pos)

        forall cmp <- myComponents do
            if (isNothing currentEventHasBeenConsumedBy) then
                cmpPos <- cmp.getPosition
                cmpSize <- cmp.getSize               
                if (inInterval pos2.x cmpPos.x cmpSize.width && inInterval pos2.y cmpPos.y cmpSize.height) then
                    currentEventHasBeenConsumedBy := (<- cmp.handleEvent (MouseEvent eventInNewCoordsystem)  modifiers)

        if (isNothing currentEventHasBeenConsumedBy) then
            currentEventHasBeenConsumedBy := (boolToMaybe (Just this) (<- dynamicHandleEvent event mouseEventHandler))
        
        --e.stdout.write ("CONSUMED: " ++ (show (isJust currentEventHasBeenConsumedBy)) ++ "\n")
        
        result currentEventHasBeenConsumedBy -}

    getType (MousePressed _) = MousePressed
    getType (MouseReleased _) = MouseReleased
    getType (MouseClicked _) = MouseClicked

    posget (MousePressed p) = p 
    posget (MouseReleased p) = p 
    posget (MouseClicked p) = p 

    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
            myState := Active
            appRef := Just app
            initContainer this app

            inithelper

            forall cmp <- myComponents do
                cmp.init app
                containerAddComponent id cmp.id

    this = Container{..}  

    inithelper = do
        containerSetSize id size
        containerSetBackgroundColor id color
        containerSetPosition id position


    result this

inInterval x startPos width = (x >= startPos && x <= (startPos+width))

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--container
extern initContainer :: Container -> App -> Request ()
extern containerSetBackgroundColor :: CocoaID -> Color -> Action
extern containerSetSize :: CocoaID -> Size -> Action
extern containerSetPosition :: CocoaID -> Position -> Action
extern containerAddComponent :: CocoaID -> CocoaID -> Action                    -- external method for doing the actual cocoa add-call!
