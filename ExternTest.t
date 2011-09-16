module ExternTest where

import POSIX
    
root w = class
    env = new posix w

    printLoop c = action
        env.stdout.write c
        after (millisec 10) send printLoop c

    printSome w env stuff =  action
        env.stdout.write stuff
            
    extLoop = action
        doAllTheThings (printSome w env)
        after (millisec 10) send extLoop

    result action
        printLoop "Timber #1\n"
        printLoop "Timber #2\n"
        extLoop

        
extern doAllTheThings :: (String -> Action) -> Request Bool