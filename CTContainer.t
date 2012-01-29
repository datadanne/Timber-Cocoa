module CTContainer where

import CocoaDef

--------------------------------------------------------------------------------------------------
------          ** CONTAINER **         ----------------------------------------------------------

mkCocoaContainer :: World -> Class Container
mkCocoaContainer w = class
    myComponents := []    
    color        := {r=255, g=255, b=255}
    alpha        := 1.0
    appRef       := Nothing
    state        := Inactive

    BaseComponent {getAllChildren=dummy, setPosition = setPositionImpl, setSize = setSizeImpl,..} = 
        new basicComponent False Nothing "Container"

    setPosition p = request
        if isActive state then
            Active ref = state
            containerSetPosition ref p
        setPositionImpl p

    setSize s = request
        if isActive state then
            Active ref = state
            containerSetSize ref s
        setSizeImpl s
    
    getAllChildren = request
        cs <- forall c <- myComponents do
            list <- c.getAllChildren
            result list ++ [c] -- order is important here for reactions to mouse events
        result concat cs

    setBackgroundColor c = setBackgroundColorWithAlpha c 1.0
    setBackgroundColorWithAlpha c a = request
        if isActive state then
            Active ref = state
            containerSetBackgroundColor ref c a
        color := c
        alpha := a

    getBackgroundColor = request
        result color
    
    addComponent c = request        
        myComponents := c : myComponents
        c.setParent this
        if isActive state then
            Active ref = state
            s <- c.initComp (fromJust appRef)
            if isActive s then
                Active c_ref = s
                containerAddComponent ref c_ref
            
    removeComponent c = request
        myComponents := [x | x <- myComponents, not (x == c)]
        if isActive state then
            Active ref = state
            cmpState <- c.getState
            if isActive cmpState then
                Active cmpRef = cmpState
                containerRemoveComponent ref cmpRef
            c.destroyComp
            
    removeAllComponents = request
        removeAllComponentsImpl

    removeAllComponentsImpl = do
        if isActive state then
            Active ref = state
            forall c <- myComponents do
                s <- c.getState
                if isActive s then
                    Active c_ref = s
                    containerRemoveComponent ref c_ref
                c.destroyComp
        myComponents := []

    getComponents = request
        result myComponents
    
    destroyComp = request
        if (isActive state) then
            removeAllComponentsImpl
            Active ref = state
            destroyContainer ref
        state := destroyState state
        
    initComp app = request
        if isInactive state then
            appRef := Just app
            ref <- initContainer w
            state := Active ref
            containerSetSize ref (<-getSize)
            containerSetBackgroundColor ref color alpha
            containerSetPosition ref (<-getPosition)
            forall c <- myComponents do
                s <- c.initComp app
                if isActive s then
                     Active c_ref = s
                     containerAddComponent ref c_ref
        result state
    
    getState = request
        result state

    this = Container {id = self,..}  

    result this

basicHasResponders :: Class DefaultEventResponder
basicHasResponders = class
    responders := []
    addResponder a = request
        responders := responders ++ [a]
    setResponders aa = request
        responders := aa
    getResponders = request
        result responders
    -- return true (block cocoa) if any of the installed responders say so
    returnVal := NotConsumed    
    respondToInputEvent inputEvent modifiers = request
        returnVal := NotConsumed
        forall h <- responders do
            if returnVal == NotConsumed then
                returnVal := <- h.respondToInputEvent inputEvent modifiers
        result returnVal
    result DefaultEventResponder {..}

basicComponent :: Bool -> (Maybe Component) -> String -> Class BaseComponent
basicComponent f p n = class
    DefaultEventResponder {..}     = new basicHasResponders
    (getName,setName)               = new wrapper n
    (getParent,setParentImpl)       = new wrapper p
    setParent p = request setParentImpl (Just p)
    (getIsFocusable,setIsFocusable) = new wrapper f
    (getPosition,setPosition)       = new wrapper ({x=0, y=0})
    (getSize,setSize)               = new wrapper ({width=100, height=100})    
    getAllChildren                  = request result []
    result BaseComponent {..}

private
    
wrapper :: a -> Class (Request a, a -> Request ())    
wrapper s = class
    a := s
    set b = request a := b
    get = request result a
    result (get,set)

extern initContainer                :: World -> Request CocoaRef
extern destroyContainer             :: CocoaRef -> Request ()
extern containerSetBackgroundColor  :: CocoaRef -> Color -> Float -> Request ()
extern containerSetSize             :: CocoaRef -> Size -> Request ()
extern containerSetPosition         :: CocoaRef -> Position -> Request ()
extern containerAddComponent        :: CocoaRef -> CocoaRef -> Request ()
extern containerRemoveComponent     :: CocoaRef -> CocoaRef -> Request ()