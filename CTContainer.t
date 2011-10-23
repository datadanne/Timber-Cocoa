module CTContainer where

import CTCommon

struct Container < Component, ContainsComponents, HasBackgroundColor

--------------------------------------------------------------------------------------------------
------          ** CONTAINER **         ----------------------------------------------------------
mkCocoaContainer env = class
    myComponents := []        
    color := {r=255; g=255; b=255}
    appRef := Nothing
    
    id = new mkCocoaID
    base = new basicComponent False Nothing "Container"
    addResponder = base.addResponder
    setResponders = base.setResponders
    getResponders = base.getResponders
    setParent = base.setParent
    getParent = base.getParent
    setIsFocusable = base.setIsFocusable
    getIsFocusable = base.getIsFocusable
    setName s = base.setName s
    getName = base.getName
    getState = base.getState
    setState = base.setState
    respondToInputEvent = base.respondToInputEvent

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
    
    
    addComponent c = request        
        myComponents := c : myComponents
        c.setParent (Just this)

        state <- base.getState
        if (state == Active && isJust appRef) then
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

    getComponents = request
        result myComponents

    children := []
    getAllComponents = request
        children := []
        forall c <- myComponents do
            children := (children ++ (<- c.getAllComponents) ++ [c])
        result children
        
    destroy = request
        if ((<- base.getState) == Active) then
            internalRemoveAllComponents
            destroyContainer id
            base.setState Destroyed
        
    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
            appRef := Just app
            base.setState Active
            initContainer id app
            inithelper

            forall cmp <- myComponents do
                cmp.init app
                containerAddComponent id cmp.id
    inithelper = do
       containerSetSize id (<- base.getSize)
       containerSetBackgroundColor id color
       containerSetPosition id (<- base.getPosition)
       
    this := Container{..}  

    result this
        
    

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--container

extern initContainer :: CocoaID -> App -> Request ()
extern destroyContainer :: CocoaID -> Action
extern containerSetBackgroundColor :: CocoaID -> Color -> Action
extern containerSetSize :: CocoaID -> Size -> Action
extern containerSetPosition :: CocoaID -> Position -> Action
extern containerAddComponent :: CocoaID -> CocoaID -> Action                    -- external method for doing the actual cocoa add-call!
extern containerRemoveComponent :: CocoaID -> CocoaID -> Action