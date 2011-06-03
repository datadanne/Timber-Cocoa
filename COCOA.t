module COCOA where

import CTCommon
import CTButton
import CTLabel
import CTContainer
import CTWindow
import CTApplication

struct Env where
	startApplication	:: (App -> Action) -> Request ()   	-- what to do?           

extern cocoa :: World -> Class Env

