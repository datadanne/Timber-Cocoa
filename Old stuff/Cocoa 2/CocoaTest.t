module CocoaTest where

import Cocoa
import POSIX

root w = class
	env = new posix w
	osx = new cocoa w
	
	result action
		env.stdout.write "Timber: Calling showWindow\n"
		osx.showWindow
		env.stdout.write "Timber: Window gone?\n"