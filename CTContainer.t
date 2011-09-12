module CTContainer where

import POSIX
import CTCommon

struct Container < Component, ContainsComponents, HandlesMouseEvents, HandlesKeyEvents, HasBackgroundColor

--------------------------------------------------------------------------------------------------
------          ** CONTAINER **         ----------------------------------------------------------
mkCocoaContainer env = class
    myComponents := []        
    color := {r=255; g=255; b=255}

    appRef := Nothing
    mouseEventHandler := Nothing
    keyEventHandler := Nothing

    currentEventHasBeenConsumedBy := Nothing
    
    nextFocusTarget := Nothing
    previousFocusTarget := Nothing

    id = new mkCocoaID
    base = new basicComponent False Nothing "ContainerWHAT"
    setParent = base.setParent
    getParent = base.getParent
    setIsFocusable = base.setIsFocusable
    getIsFocusable = base.getIsFocusable
    setName s = base.setName s
    getName = base.getName
    getState = base.getState
    setState = base.setState

    setPosition p = request
        case (<- base.getState) of
            Active -> containerSetPosition id p
            _ ->
        base.setPosition p

    getPosition = base.getPosition

    setSize s = request
        case (<- base.getState) of
            Active -> containerSetSize id s
            _ ->
        base.setSize s

    getSize = base.getSize

    setBackgroundColor c = request
        case (<- base.getState) of
            Active -> containerSetBackgroundColor id c
            _ ->
        color := c

    getBackgroundColor = request
        result color
        
    empty [] = True
    empty _ = False
    
    children := []
    getAllComponents = request
        children := []

        forall c <- myComponents do
            children := (children ++ (<- c.getAllComponents) ++ [c])
            
        result children
    
    addComponent c = request
        myComponents := c : myComponents
        c.setParent (Just this)
        if ((<- base.getState) == Active && isJust appRef) then
            c.init (fromJust appRef)
            containerAddComponent id c.id    
            
    removeComponent c = request
        myComponents := [x | x <- myComponents, not (x == c)]
        containerRemoveComponent id c.id
        c.destroy
    
    internalRemoveAllComponents = do
        forall c <- myComponents do
            containerRemoveComponent id c.id
            c.destroy
        myComponents := []
            
    removeAllComponents = request
        internalRemoveAllComponents

    destroy = request
        if ((<- base.getState) == Active) then
            internalRemoveAllComponents
            destroyContainer id
            base.setState Destroyed
        
    getComponents = request
        result myComponents


    installMouseListener ml = request
        mouseEventHandler := Just ml
    
    installKeyListener kl = request
        keyEventHandler := Just kl

    handleEvent (MouseEvent t) modifiers = request
        result (boolToMaybe (Just this) (<- dynamicHandleEvent t mouseEventHandler))
        --result <- mouseEventDispatcher t modifiers
    
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
            appRef := Just app
            base.setState Active
            initContainer this app
            inithelper

            forall cmp <- myComponents do
                cmp.init app
                containerAddComponent id cmp.id

    this = Container{..}  

    inithelper = do
        containerSetSize id (<- base.getSize)
        containerSetBackgroundColor id color
        containerSetPosition id (<- base.getPosition)


    result this

inInterval x startPos width = (x >= startPos && x <= (startPos+width))

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--container
extern initContainer :: Container -> App -> Request ()
extern destroyContainer :: CocoaID -> Action
extern containerSetBackgroundColor :: CocoaID -> Color -> Action
extern containerSetSize :: CocoaID -> Size -> Action
extern containerSetPosition :: CocoaID -> Position -> Action
extern containerAddComponent :: CocoaID -> CocoaID -> Action                    -- external method for doing the actual cocoa add-call!
extern containerRemoveComponent :: CocoaID -> CocoaID -> Action