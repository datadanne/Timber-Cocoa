buttonHandler :: Label -> Class Action
buttonHandler label = class
   clickCount := 0
   result action
       clickCount := clickCount + 1
       label.setText ("Click #" ++ show clickCount)