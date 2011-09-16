module DummyPOSIX where

import POSIX

dummyPosix w = class
    real = new posix w
    
    exit :: Int -> Request ()
    exit = real.exit
        
    argv :: Array String 
    argv = real.argv
    
    stdin :: RFile
    stdin = real.stdin
    
    seek i = request
        result 1
    write s = request
        result 0
    installW p = request
        result ()
    
    close = request
        result ()

    stdout :: WFile        
    stdout = WFile {seek=seek;write=write;installW=installW;close=close}
    

    openR :: String -> Request (Maybe RFile)
    openR s = request
        result Nothing
    
    openW :: String -> Request (Maybe WFile)
    openW s = request
        result Nothing
        
    startTime :: Time
    startTime = real.startTime
    
    inet :: Internet
    inet = real.inet
    
    result POSIX.Env {..}