module Tutorial0App where

import COCOA
import POSIX

root w = class
    env = new posix w
    osx = new cocoa w

    applicationDidFinishLaunching app = action                         
    	w1 = new mkCocoaWindow env
    	w1.setSize ({width=400;height=400})
    	app.showWindow w1

    result action
        osx.startApplication applicationDidFinishLaunching