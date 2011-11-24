tabCountLabel = new mkCocoaLabel w
tabCountLabel.setText "Tab counter"
tabCountLabel.setSize ({width=150;height=36})
tabCountLabel.setPosition ({x=40;y=70})
ta.addResponder (new myTabResponder tabCountLabel)
rightContainer.addComponent tabCountLabel