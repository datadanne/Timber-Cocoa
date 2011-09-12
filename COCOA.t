module COCOA where

import CTCommon
import CTButton
import CTLabel
import CTContainer
import CTWindow
import CTApplication
import CTTextField
import CTDropDown
import POSIX

struct Env where
	startApplication	:: (App -> Action) -> Request ()   	-- what to do?           

extern cocoa :: World -> Class Env

root w = class
    env = new posix w
    result action