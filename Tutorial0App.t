module Tutorial0App where

import COCOA

root w = class
    osx = new cocoa w
    w1  = new mkCocoaWindow w

    start app = action   
        w1.setPosition({x=100;y=100})
    	w1.setSize ({width=400;height=400})
    	w1.setBackgroundColor ({r=200;g=200;b=100})
    	w1.setTitle "Tutorial"
    	app.addWindow w1
    	
    	after sec 3 send action
    	    w1.destroyWindow
    	
    	after sec 5 send action
    	    app.addWindow w1

    result action
        osx.startApplication start