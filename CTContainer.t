module CTContainer where

import POSIX
import CTCommon

struct Container < Component, ContainsComponents, HandlesMouseEvents, HandlesKeyEvents, HasBackgroundColor

--------------------------------------------------------------------------------------------------
------          ** CONTAINER **         ----------------------------------------------------------
mkContainer e = class
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

    id = new mkCocoaID

    setPosition p = action
        case (myState) of
            Active -> containerSetPosition id p
            _ ->
        position := p

    getPosition = request
        result position

    setSize s = action
        case (myState) of
            Active -> containerSetSize id s
            _ ->
        size := s

    getSize = request
        result size

    setBackgroundColor c = action
        case (myState) of
            Active -> containerSetBackgroundColor id c
            _ ->
        color := c

    getBackgroundColor = request
        result color    

    focus = new focusWrapper this False

    setNextFocusTarget nxt = request
        nextFocusTarget := nxt
        if (length myComponents > 0) then
            (head myComponents).setNextFocusTarget nextFocusTarget
            if (isJust nextFocusTarget) then
                (fromJust nextFocusTarget).setPreviousFocusTarget (Just (head myComponents))

    getNextFocusTarget = request
        if (length myComponents > 0) then
             result (Just (last myComponents))
         else
             result nextFocusTarget
             
    setPreviousFocusTarget = focus.setPreviousFocusTarget
    getPreviousFocusTarget = focus.getPreviousFocusTarget
    setIsFocusable =  focus.setIsFocusable
    getIsFocusable = focus.getIsFocusable
    
    name := "Container"
    setName s = request
        name := s
    getName = request
        result name

    addComponent c = request
        if (length myComponents > 0) then
            newestCmp = (head myComponents)
            c.setNextFocusTarget (<- newestCmp.getNextFocusTarget)
            newestCmp.setNextFocusTarget (Just c)
            c.setPreviousFocusTarget (Just newestCmp)
        else
            c.setNextFocusTarget nextFocusTarget
            c.setPreviousFocusTarget (<- focus.getPreviousFocusTarget)
            if (isJust nextFocusTarget) then
                (fromJust nextFocusTarget).setPreviousFocusTarget (Just c)
            nextFocusTarget := (Just c)

        myComponents := c : myComponents
        if (myState == Active && isJust appRef) then
            c.init (fromJust appRef)
            containerAddComponent id c.id

    getComponents = request
        result myComponents

    destroy = request
        myState := Destroyed

    installMouseListener ml = request
        mouseEventHandler := Just ml
    
    installKeyListener kl = request
        keyEventHandler := Just kl

    handleEvent (MouseEvent t) modifiers = request
        result <- mouseEventDispatcher t modifiers
        
    mouseEventDispatcher event modifiers = do
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
        
        result currentEventHasBeenConsumedBy
        
    handleEvent _ modifiers = request
        result Nothing

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
