mkCocoaCallbackLabel :: (Class Label) -> (String->Action) -> Class Label
mkCocoaCallbackLabel mkLabel cb = class

	Label {setText=setTextImpl;appendText=appendTextImpl;..} = new mkLabel

	setText s = request
		setTextImpl s
		send cb s

	appendText s = request
		appendTextImpl s
		send cb (<- getText)

	result Label{..}
