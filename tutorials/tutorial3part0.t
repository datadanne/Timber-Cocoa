myTabResponder :: Label -> Class RespondsToInputEvents
myTabResponder label = class
    tabCount := 0

    respondToInputEvent (KeyEvent (KeyPressed Tab)) _ = request
       tabCount := tabCount + 1
       label.setText ("Tabs blocked #" ++ (show tabCount))
       result Consumed

   respondToInputEvent _ _ = request
       result NotConsumed

   result RespondsToInputEvents {..}
