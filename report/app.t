struct App < AppImpl where
  addWindow :: CocoaWindow -> Request ()  

struct AppImpl where
  {- a consumed event should not be handled by Cocoa -}
  sendInputEvent         :: InputEvent -> WindowID -> Request Consumed
  {- this event is always handled by Cocoa -}
  sendWindowResize       :: Size -> WindowID -> Request ()
  {- True iff the window should be closed automatically -}
  sendWindowCloseRequest :: WindowID -> Request Bool           