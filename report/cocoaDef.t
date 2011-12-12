module CocoaDef where

struct CocoaEnv where
  startApplication :: (App -> Action) -> Request ()

struct App < AppImpl where
  addWindow :: CocoaWindow -> Request () 

struct AppImpl where
    {- a consumed event should not be handled by Cocoa -}
    sendInputEvent         :: InputEvent -> WindowID -> Request Consumed
    {- this event is always handled by Cocoa -}
    sendWindowResize       :: Size -> WindowID -> Request ()
    {- True iff the window should be closed automatically -}
    sendWindowCloseRequest :: WindowID -> Request Bool 

struct CocoaWindow < RespondsToInputEvents, HasSize, 
  HasBackgroundColor, ContainsComponents, HasTitle, 
  HasResponders, IsResizable where
  getId       :: Request WindowID
  initWindow  :: App -> Request ()
  {- True: override window close events, False: don't override  -}
  setWindowResponder :: RespondsToWindowEvents -> Bool -> Request ()
  windowClosing  :: Request Bool
  windowResizing :: Size -> Request ()
  destroyWindow  :: Request ()
  setVisible  :: Bool -> Request Bool
  setFocus    :: Component -> Request ()
  getFocus    :: Request Component

struct Component < BaseComponent where
  initComp  :: App -> Request ComponentState
  destroyComp :: Request ()
  getState  :: Request ComponentState
  id      :: OID

struct BaseComponent < IsFocusable, HasSize, HasResponders, 
  RespondsToInputEvents where
  setName    :: String -> Request ()
  getName    :: Request String
  setParent    :: Component -> Request ()
  getParent    :: Request (Maybe Component)
  getAllChildren :: Request [Component]

data ComponentState =  Inactive | Active CocoaRef | 
  Destroyed (Maybe CocoaRef)

struct Container < Component, ContainsComponents, HasBackgroundColor

struct ContainsComponents where
  addComponent    :: Component -> Request ()
  removeComponent   :: Component -> Request ()
  removeAllComponents :: Request ()
  getComponents     :: Request [Component]
  
struct HasResponders where
  addResponder  :: RespondsToInputEvents -> Request ()
  setResponders :: [RespondsToInputEvents] -> Request ()
  getResponders :: Request [RespondsToInputEvents]

struct RespondsToInputEvents where
  respondToInputEvent :: InputEvent -> Modifiers -> Request Consumed
  
data Consumed = NotConsumed | Consumed

struct RespondsToWindowEvents where
  onWindowResize     :: Size -> Request ()
  onWindowCloseRequest :: Request ()

struct DefaultEventResponder < HasResponders, RespondsToInputEvents

struct HasSelectionResponder where
  setSelectionResponder :: RespondsToSelectionEvents -> Request ()
  
struct RespondsToSelectionEvents where
  selectionChanged :: String -> Action

struct Position where
  x :: Int
  y :: Int

struct Size where
  width :: Int
  height :: Int
      
-- values > 255 will be interpreted as 255 
struct Color where
  r :: Int
  g :: Int
  b :: Int
                        
struct HasPosition where
  setPosition :: Position -> Request ()
  getPosition :: Request Position
  
struct HasSize < HasPosition where
  setSize :: Size -> Request ()
  getSize :: Request Size

struct IsResizable where
  setResizable :: Bool -> Request ()
  getResizable :: Request Bool

struct HasBackgroundColor where
  setBackgroundColor :: Color -> Request ()
  getBackgroundColor :: Request Color
  setBackgroundColorWithAlpha :: Color -> Float -> Request ()

struct HasTitle where
  setTitle :: String -> Request ()
  getTitle :: Request String

struct HasText where
  setText :: String -> Request ()
  getText :: Request String
  appendText :: String -> Request ()
  
struct IsScrollable where
  setDocumentSize :: Size -> Request ()
  getDocumentSize :: Request Size

struct IsFocusable where
  setIsFocusable :: Bool -> Request ()
  getIsFocusable :: Request Bool

data InputEvent   = KeyEvent KeyEventType | MouseEvent MouseEventType
data KeyEventType   = KeyReleased CocoaKey | KeyPressed CocoaKey
data MouseEventType = 
    MouseMoved Position | 
    MouseReleased Position | 
    MousePressed Position | 
    MouseClicked Position | 
    MouseWheelScroll Position Float Float

-- Mapping for Swedish-Pro keyboard layout
data CocoaKey = A | S | D | F | H | G | Z | X | C | 
  V | Section | B | Q | W |
  E | R | Y | T | Num1 | Num2 | Num3 | Num4 | Num6 | Num5 |
     Grave | Num9 | Num7 | Plus | Num8 | Num0 | Umlaut | O | U |
     A_Ring | I | P | Enter | L | J | A_Umlaut | K | O_Umlaut |
     Apostrophe | Comma  | Hyphen | N | M | Period | Tab | Space |
     LessThan | Backspace | Dummy1 | Escape | RightCommand | Command |
     Shift | CapsLock | Option | Control | RightShift | RightOption |
     RightControl | Function | Dummy2 | KeypadDecimal | Dummy3 |
     KeypadMultiply | Dummy4 | KeypadPlus | Dummy5 | KeypadClear |
     Dummy6 | Dummy7 | Dummy8 | KeypadDivide | KeypadEnter | Dummy9 |
     KeypadMinus | Dummy10 | Dummy11 | KeypadEquals | Keypad0 |
     Keypad1 | Keypad2 | Keypad3 | Keypad4 | Keypad5 | Keypad6 |
     Keypad7 | Dummy12 | Keypad8 | Keypad9 | Dummy13 | Dummy14 |
     Dummy15 | F5 | F6 | F7 | F3 | F8 | F9 | Dummy16 | F11 |
     Dummy17 | F13 | F16 | F14 | Dummy18 |F10 | Dummy19 | F12 |
     Dummy20 | F15 | Dummy21 |Home | PageUp | Delete | F4 | End |
     F2 | PageDown | F1 | LeftArrow | RightArrow | DownArrow | UpArrow

-- abstract types
WindowID   :: *
CocoaRef   :: *

private

type WindowID = Int
type CocoaRef = Int