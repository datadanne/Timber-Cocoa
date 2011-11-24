label = new mkCocoaCallbackLabel (mkCocoaLabel w) textChangeCallback

tabCountLabel = new mkCocoaCallbackLabel (mkCocoaLabel w) textChangeCallback

textChangeCallback newText = action
    callbackLabel.setText ("CB: " ++ newText)

callbackLabel = new mkCocoaLabel

addCallbackLabel = do
    callbackLabel.setSize ({width=150; height=36})
    callbackLabel.setPosition ({x=40; y=10})    
    callbackLabel.setText "Callback label"
    rightContainer.addComponent callbackLabel