module LockTest where

import POSIX
import COCOA

root w = class
    env = new posix w
    osx = new cocoa w
    
    result action
        superTest = KeyEvent (KeyPressed Tab)