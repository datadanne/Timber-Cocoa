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
            Active -> _ = containerSetPosition cocoaRef p
            _ ->
        base.setPosition p

    getPosition = base.getPosition

    setSize s = request
        case (<- base.getState) of
            Active -> _ = containerSetSize cocoaRef s
            _ ->
        base.setSize s

    getSize = base.getSize

    setBackgroundColor c = request
        case (<- base.getState) of
            Active -> _ = containerSetBackgroundColor cocoaRef c
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
--            containerAddComponent id c.id    
            _ = containerAddComponent cocoaRef (<-c.getCocoaRef)
            
    removeComponent c = request
        myComponents := [x | x <- myComponents, not (x == c)]
        _ = containerRemoveComponent cocoaRef (<-c.getCocoaRef)
        c.destroy
    
    internalRemoveAllComponents = do
        forall c <- myComponents do
            _ = containerRemoveComponent cocoaRef (<-c.getCocoaRef)
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
            _ = destroyContainer cocoaRef
            base.setState Destroyed
        
    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
            appRef := Just app
            base.setState Active
            cocoaRef := initContainer ()
            inithelper

            forall cmp <- myComponents do
                cmp.init app
--                containerAddComponent id cmp.id
                _ = containerAddComponent cocoaRef (<-cmp.getCocoaRef)
    inithelper = do
       _ = containerSetSize cocoaRef (<- base.getSize)
       _ = containerSetBackgroundColor cocoaRef color
       _ = containerSetPosition cocoaRef (<- base.getPosition)
    
    cocoaRef := defaultCocoaRef   
    getCocoaRef = request
        result cocoaRef 
       
    this := Container{id_temp = self; ..}  

    result this
        
    

--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--container

extern initContainer :: () -> CocoaRef
extern destroyContainer :: CocoaRef -> ()
extern containerSetBackgroundColor :: CocoaRef -> Color -> ()
extern containerSetSize :: CocoaRef -> Size -> ()
extern containerSetPosition :: CocoaRef -> Position -> ()
extern containerAddComponent :: CocoaRef -> CocoaRef -> ()                    -- external method for doing the actual cocoa add-call!
extern containerRemoveComponent :: CocoaRef -> CocoaRef -> ()