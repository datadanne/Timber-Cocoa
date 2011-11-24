windowResponder textarea = class
    onWindowResize size modifiers = request
        newWidth = floor ((fromInt size.width) * 0.8)
        newTaSize = {width=newWidth; height=80}
        newX = floor ((fromInt size.width) * 0.1)
        newTaPosition = {x=newX; y=250}
        textarea.setSize newTaSize
        textarea.setPosition newTaPosition

    onWindowCloseRequest = request

    result RespondsToWindowEvents {..}