rgbLabel       = new mkCocoaLabel w
colorButton    = new mkCocoaButton w
colorWindow    = new mkColorPicker w setColor

addColorPicker app = do
	rgbLabel.setText "R=100; G=100; B=200"
	rgbLabel.setSize ({width=150; height=36})
	rgbLabel.setPosition ({x=40; y=40})
	rightContainer.addComponent rgbLabel
	
	colorButton.setTitle "Open ColorPicker"
	colorButton.setSize ({width=150;height=21})
	colorButton.setPosition ({x=40; y=75})
	colorButton.setClickResponder (new mkColorToggle colorWindow colorButton)
	leftContainer.addComponent colorButton
	
	colorWindow.setPosition ({x=500;y=100})
	app.addWindow colorWindow
