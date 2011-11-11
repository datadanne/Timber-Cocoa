module Tutorial5CallbackLabel where

import CTLabel
   
mkCocoaCallbackLabel :: (Class Label) -> (String->Action) -> Class Label
mkCocoaCallbackLabel mkLabel cb = class
    Label {setText=setTextImpl;appendText=appendTextImpl;id=idImpl;..} = new mkLabel
    setText s = request
        setTextImpl s
        send cb s
    appendText s = request
        appendTextImpl s
        send cb (<- getText)
    result Label{id=self;..}