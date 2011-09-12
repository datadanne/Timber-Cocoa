module COCOA where

import POSIX

import CTApplication
import CTWindow -- imports CTCommon, CTContainer

import CTButton
import CTLabel
import CTTextField
import CTDropDown


struct Env where
	startApplication	:: (App -> Action) -> Request ()   	-- what to do?           

extern cocoa :: World -> Class Env

root w = class
    env = new posix w
    result action