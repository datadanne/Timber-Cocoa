module Test where

import POSIX
import COCOA

root w = class
	env = new posix w
	osx = new cocoa w
	
	printApplicationState = action
		p <- osx.getApplicationState
		case p of
			Running -> 
				env.stdout.write "ApplicationState: Running\n"
			Stopped ->
				env.stdout.write "ApplicationState: Stopped\n"
			_ ->
			
	printComponentList window = action
		env.stdout.write "---\n"
		forall btns <- window.myComponents do
			env.stdout.write ("found a component in list!\n")
		env.stdout.write "---\n"
		
	printWindowList = action
		forall wnds <- osx.windows do
			env.stdout.write "window detected in list!\n"
		env.stdout.write "no more windows..\n"
	
	result action
		osx.startApplication
		
		window = new mkNSWindow
		printWindowList
		
		after (sec 2) send action
			window2 = new mkNSWindow
			window3 = new mkNSWindow
			--osx.addWindow window
			
			button2 = new mkButton
			window.addButton button2
			
			button = new mkButton
			window2.addButton button
		
			printApplicationState
			printComponentList window
	
			after (sec 2) send action
				printWindowList
				
				button.setTitle "Hello"
				
				printComponentList window
