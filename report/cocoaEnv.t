struct CocoaEnv where
  startApplication    :: (App -> Action) -> Request ()

extern cocoa :: World -> Class CocoaEnv