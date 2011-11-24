module Tutorial0App where

import COCOA

root w = class
   osx = new cocoa w

   start app = action
       {- 
          Inside this method you can use the app
          object to open windows, add components, 
          etc.
       -}

   result action
       osx.startApplication start
