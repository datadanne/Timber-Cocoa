module Notes where

import COCOA
import POSIX

c w = class
	osx = new cocoa w
	w1 = new NSWindow                       
	
	showAction app = action
		app.showW w1
	
	result action
		osx.startApplication (showAction)
		
	startApplication :: (App -> Action) -> Request ()
	app.showWindow :: NSWindow -> Request ()