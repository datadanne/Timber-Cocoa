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
    {- True: close window, False: ignore close request -}
    sendWindowCloseRequest :: WindowID -> Request Bool

struct CocoaWindow < RespondsToInputEvents, HasSize, HasBackgroundColor, 
    ContainsComponents, HasTitle, HasResponders, IsResizable where 
    getId          :: Request WindowID
    initWindow     :: App -> Request ()
    {- True: override window close events, False: don't override  -}
    setWindowResponder :: RespondsToWindowEvents -> Bool -> Request ()
    {- True: close window, False: ignore close request -}
    windowClosing  :: Request Bool
    windowResizing :: Size -> Request ()
    destroyWindow  :: Request ()
    setVisible     :: Bool -> Request Bool
    setFocus       :: Component -> Request ()
    getFocus       :: Request Component

struct Component < BaseComponent where 
    initComp    :: App -> Request ComponentState
    destroyComp :: Request ()
    getState    :: Request ComponentState
    id          :: OID

struct BaseComponent < IsFocusable, HasSize, HasResponders, RespondsToInputEvents where
    setName        :: String -> Request ()
    getName        :: Request String
    setParent      :: Component -> Request ()
    getParent      :: Request (Maybe Component)
    getAllChildren :: Request [Component]

data ComponentState =  Inactive | Active CocoaRef | Destroyed (Maybe CocoaRef)

isActive (Active _)       = True
isActive _                = False

isInactive Inactive       = True
isInactive _              = False

isDestroyed (Destroyed _) = True
isDestroyed _             = False

destroyState Inactive     = Destroyed Nothing
destroyState (Active ref) = Destroyed (Just ref)
destroyState s            = s

instance eqComponent :: Eq Component where
    (==) a b = a.id == b.id
    (/=) a b = a.id /= b.id

struct Container < Component, ContainsComponents, HasBackgroundColor

struct ContainsComponents where
    addComponent        :: Component -> Request ()
    removeComponent     :: Component -> Request ()
    removeAllComponents :: Request ()
    getComponents       :: Request [Component]
    
struct HasResponders where
    addResponder  :: RespondsToInputEvents -> Request ()
    setResponders :: [RespondsToInputEvents] -> Request ()
    getResponders :: Request [RespondsToInputEvents]

struct RespondsToInputEvents where
    respondToInputEvent :: InputEvent -> Modifiers -> Request Consumed
    
data Consumed = NotConsumed | Consumed

instance eqConsumed :: Eq Consumed where
    (==) Consumed Consumed       = True
    (==) NotConsumed NotConsumed = True
    (==) _ _                     = False
    (/=) a b                     = not (a == b)

isConsumed Consumed = True
isConsumed _        = False

struct RespondsToWindowEvents where
    onWindowResize       :: Size -> Request ()
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

instance showColor :: Show Color where
    show c =  "R: " ++ (show c.r) ++ 
             " G: " ++ (show c.g) ++ 
             " B: " ++ (show c.b)

-- Apple colors
black   = {r=0;   g=0;   b=0  }
blue    = {r=44;  g=38;  b=249}
brown   = {r=169; g=121; b=72 }
cyan    = {r=2;   g=254; b=254}
green   = {r=0;   g=252; b=56 }
magenta = {r=255; g=48;  b=250}
orange  = {r=254; g=146; b=40 }
purple  = {r=148; g=23;  b=143}
red     = {r=255; g=27;  b=24 }
yellow  = {r=252; g=253; b=63 }
white   = {r=255; g=255; b=255}

-- Web colors
web_black   = {r=0;   g=0;   b=0  }
web_red     = {r=255; g=0;   b=0  }
web_green   = {r=0;   g=255; b=0  }
web_blue    = {r=0;   g=0;   b=255}
web_yellow  = {r=255; g=255; b=0  }
web_cyan    = {r=0;   g=255; b=255}
web_magenta = {r=255; g=0;   b=255}
web_gray    = {r=192; g=192; b=192}
web_white   = {r=255; g=255; b=255}
                                              
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

data InputEvent     = KeyEvent KeyEventType | MouseEvent MouseEventType
data KeyEventType   = KeyReleased CocoaKey | KeyPressed CocoaKey
data MouseEventType = MouseMoved Position | MouseReleased Position | MousePressed Position |
                      MouseClicked Position | MouseWheelScroll Position Float Float 

data CocoaKey = UpArrow | DownArrow | RightArrow | LeftArrow |
                F1 | PageDown | F2 | End | F4 | ForwardDelete |
                PageUp | Home | Help | F15 | Dummy15 | F12 | Dummy14 | F10 |
                Dummy13 | F14 | F16 | F13 | Dummy12 | F11 | Dummy11 | F9 | F8 | F3 | F7 |
                F6 | F5 | Dummy10 | Dummy9 | Dummy8 | Keypad9 | Keypad8 | F20 |
                Keypad7 | Keypad6 | Keypad5 | Keypad4 | Keypad3 | Keypad2 | Keypad1 |
                Keypad0 | KeypadEquals | F19 | F18 | KeypadMinus | Dummy7 | KeypadEnter |
                KeypadDivide | Mute | VolumeDown | VolumeUp | KeypadClear | Dummy6 |
                KeypadPlus | Dummy5 | KeypadMultiply | Dummy4 | KeypadDecimal |
                F17 | Function | RightControl | RightOption | RightShift |  
                Control | Option | CapsLock | Shift | Command | Dummy3 | Escape | Dummy2 | 
                Delete | Grave | Space | Tab | Period | M | N | Slash | Comma | Backslash | 
                Semicolon | K | Quote | J | L | Return | P | I | LeftBracket | U | O |
                RightBracket | Num0 | Num8 | Minus | Num7 | Num9 | Equal | Num5 | Num6 |
                NUm4 | Num3 | Num2 | Num1 | T | Y | R | E | W | Q | B | Dummy1 |
                V | C | X | Z | G | H | F | D | S | A

getMousePosition :: MouseEventType -> Position
getMousePosition (MousePressed p)         = p 
getMousePosition (MouseReleased p)        = p 
getMousePosition (MouseClicked p)         = p
getMousePosition (MouseMoved p)           = p
getMousePosition (MouseWheelScroll p _ _) = p   

isMouseClick :: MouseEventType -> Bool
isMouseClick (MouseClicked _) = True
isMouseClick _                = False

getKey :: KeyEventType -> CocoaKey
getKey (KeyPressed k)  = k
getKey (KeyReleased k) = k

tabPressed :: KeyEventType -> Bool
tabPressed (KeyPressed Tab) = True
tabPressed _                = False

clickInsideBox :: Position -> Position -> Size -> Bool
clickInsideBox mousePos boxPos boxSize = 
    (inInterval mousePos.x boxPos.x boxSize.width) && (inInterval mousePos.y boxPos.y boxSize.height)

inInterval :: Int -> Int -> Int -> Bool
inInterval x startPos width = 
    (x >= startPos && x <= (startPos+width))

type Modifiers = [CocoaKey]

-- abstract types
WindowID   :: *
CocoaRef   :: *

private

type WindowID = Int
type CocoaRef = Int
