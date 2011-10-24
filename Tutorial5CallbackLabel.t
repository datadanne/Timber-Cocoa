module Tutorial5CallbackLabel where

import CTLabel

struct Tutorial5CallbackLabel < Label where
    installOnTextChangeCallback :: (String -> Action) -> Request ()
   
mkCocoaCallbackLabel = class
    textChangeCallback := Nothing
    
    -- the component we are "extending"
    baseLabel = new mkCocoaLabel

{- Vi borde ju bygga in en extra-syntax för target=Cocoa som gör att man kan skriva typ baseComponent = new mkCocoa<Component_name> och så fylls allt nedan i vid kompilering, alltså typ arv..? -}                      
        
    addResponder = baseLabel.addResponder
    setResponders = baseLabel.setResponders
    getResponders = baseLabel.getResponders
    setParent = baseLabel.setParent
    getParent = baseLabel.getParent
    setIsFocusable = baseLabel.setIsFocusable
    getIsFocusable = baseLabel.getIsFocusable
    setName = baseLabel.setName
    getName = baseLabel.getName
    getState = baseLabel.getState
    setState = baseLabel.setState
    getAllComponents = baseLabel.getAllComponents
    respondToInputEvent = baseLabel.respondToInputEvent
    
    setText s = request
        baseLabel.setText s
        if (isJust textChangeCallback) then
            send (fromJust textChangeCallback) s
        
    getText = baseLabel.getText     
    appendText s = request
        baseLabel.appendText s
        if (isJust textChangeCallback) then
            send (fromJust textChangeCallback) (<- baseLabel.getText)
        
    setTextColor = baseLabel.setTextColor
    getTextColor = baseLabel.getTextColor
    setPosition = baseLabel.setPosition  
    getPosition = baseLabel.getPosition
    setSize = baseLabel.setSize
    getSize = baseLabel.getSize        
    destroy = baseLabel.destroy
    init = baseLabel.init
    getCocoaRef = baseLabel.getCocoaRef
    
    installOnTextChangeCallback a = request
        textChangeCallback := Just a
    
    this = Tutorial5CallbackLabel{id_temp=self;..}

    result this