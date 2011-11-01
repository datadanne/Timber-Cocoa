module Tutorial5CallbackLabel where

import CTLabel

struct Tutorial5CallbackLabel < Label where
    installOnTextChangeCallback :: (String -> Action) -> Request ()
   
mkCocoaCallbackLabel w = class
    textChangeCallback := Nothing

    Label {setText=setTextImpl;appendText=appendTextImpl..} = new mkCocoaLabel w
    
    setText s = request
        setTextImpl s
        if (isJust textChangeCallback) then
            send (fromJust textChangeCallback) s

    appendText s = request
        appendTextImpl s
        if (isJust textChangeCallback) then
            send (fromJust textChangeCallback) (<- getText)

    installOnTextChangeCallback a = request
        textChangeCallback := Just a
    
    this = Tutorial5CallbackLabel{id=self;..}

    result this