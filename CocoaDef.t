module CocoaDef where

struct CocoaEnv where
	startApplication :: (App -> Action) -> Request ()

struct App < AppImpl where
    addWindow :: CocoaWindow -> Request ()  

struct AppImpl where
    sendInputEvent         :: InputEvent -> WindowID -> Request Bool
    sendWindowResize       :: Size -> WindowID -> Request ()
    sendWindowCloseRequest :: WindowID -> Request Bool       

struct CocoaWindow < RespondsToWindowEvents, RespondsToInputEvents, HasSize, HasBackgroundColor, 
    ContainsComponents, HasTitle, HasResponders, HasWindowResponder, IsResizable where 
    getId         :: Request WindowID
    initWindow    :: App -> Request ()
    destroyWindow :: Request ()
    setVisible    :: Bool -> Request Bool
    setFocus      :: Component -> Request ()
    getFocus      :: Request Component

struct Component < BaseComponent where 
    initComp    :: App -> Request CocoaRef
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
    respondToInputEvent :: InputEvent -> Modifiers -> Request Bool

struct HasWindowResponder where
    setWindowResponder   :: RespondsToWindowEvents -> Bool -> Request ()

struct RespondsToWindowEvents where
    onWindowResize       :: Size -> Request ()
    onWindowCloseRequest :: Request Bool

struct DefaultEventResponder < HasResponders, RespondsToInputEvents

struct HasSelectionResponder where
    setSelectionResponder :: RespondsToSelectionEvents -> Request ()
    
struct RespondsToSelectionEvents where
    selectionChanged      :: String -> Action

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

data InputEvent     = MouseEvent MouseEventType | KeyEvent KeyEventType
data KeyEventType   = KeyPressed CocoaKey | KeyReleased CocoaKey
data MouseEventType = MouseWheelScroll Position Float Float | MouseClicked Position | 
                      MousePressed Position | MouseReleased Position | MouseMoved Position

data CocoaKey = A | S | D | F | H | G | Z | X | C | V | Dummy1 | 
                B | Q | W | E | R | Y | T | Num1 | Num2 | Num3 | Num4 | 
                Num6 | Num5 | Equal | Num9 | Num7 | Minus | Num8 | Num0 | RightBracket |
                O | U | LeftBracket | I | P | Return | L | J | Quote | 
                K | Semicolon | Backslash | Comma  | Slash | N | M |
                Period | Tab | Space | Grave | Delete | Dummy2 | Escape | 
                Dummy3 | Command | Shift | CapsLock | Option | Control | 
                RightShift | RightOption | RightControl | Function | F17 |
                KeypadDecimal | Dummy4 | KeypadMultiply | Dummy5 | KeypadPlus | 
                Dummy6 | KeypadClear | VolumeUp | VolumeDown | Mute | KeypadDivide |
                KeypadEnter | Dummy7 | KeypadMinus | F18 | F19 | KeypadEquals | Keypad0 |
                Keypad1 | Keypad2 | Keypad3 | Keypad4 | Keypad5 | Keypad6 | Keypad7 |
                F20 | Keypad8 | Keypad9 | Dummy8 | Dummy9 | Dummy10 | F5 | F6 | 
                F7 | F3 | F8 | F9 | Dummy11 | F11 | Dummy12 | F13 | F16 | F14 | Dummy13 |
                F10 | Dummy14 | F12 | Dummy15 | F15 | Help |Home | PageUp |
                ForwardDelete | F4 | End | F2 | PageDown | F1 |
                LeftArrow | RightArrow | DownArrow | UpArrow

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
