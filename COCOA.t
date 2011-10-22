module COCOA where

import CTApplication
import CTWindow -- imports CTCommon, CTContainer

struct CocoaEnv where
	startApplication	:: (App -> Action) -> Request ()   	-- what to do?           

extern cocoa :: World -> Class CocoaEnv