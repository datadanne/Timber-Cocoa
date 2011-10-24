module COCOA where

struct CocoaID where
	dummy :: Int

struct CocoaWindow < RespondsToWindowEvents, HasSize, HasBackgroundColor, ContainsComponents, HasResponders, RespondsToInputEvents where 
    --windowId :: CocoaID
    getId :: Request WindowID
    initWindow :: App -> Request ()
    destroyWindow :: Request ()
    setVisible :: Bool -> Request Bool
    setFocus :: Component -> Request ()
    getFocus :: Request Component

struct HasResponders where
    addResponder :: RespondsToInputEvents -> Request ()
    setResponders :: [RespondsToInputEvents] -> Request ()
    getResponders :: Request [RespondsToInputEvents]

struct RespondsToInputEvents where
    respondToInputEvent :: InputEvent -> Modifiers -> Request Bool

struct RespondsToSelectionEvents where
    selectionChanged :: String -> Action
    setSelectionResponder :: RespondsToSelectionEvents -> Request ()

struct RespondsToWindowEvents where
    onWindowResize :: Size -> Request ()
    onWindowCloseRequest :: Request Bool
    setWindowResponder :: RespondsToWindowEvents -> Request ()

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

struct HasBackgroundColor where
    setBackgroundColor :: Color -> Request ()
    getBackgroundColor :: Request Color

struct HasText where
    setText :: String -> Request ()
    getText :: Request String
    appendText :: String -> Request ()
    
struct IsScrollable where
    setScrollable :: (Bool, Bool) -> Request ()
    getScrollable :: Request (Bool, Bool)
    
struct IsFocusable where
    setIsFocusable :: Bool -> Request ()
    getIsFocusable :: Request Bool

struct BaseComponent < IsFocusable, HasSize, HasResponders, RespondsToInputEvents where
    setName :: String -> Request ()
    getName :: Request String
    setParent :: (Maybe Component) -> Request ()
    getParent :: Request (Maybe Component)
    setState :: ComponentState -> Request ()
    getState :: Request ComponentState
    getAllComponents :: Request [Component]

type CocoaRef = Int
defaultCocoaRef = 0 :: CocoaRef
       
struct Component < BaseComponent where   
    id :: CocoaID          
    getCocoaRef :: Request CocoaRef
    init :: App -> Request ()
    destroy :: Request ()
    id_temp :: OID

struct ContainsComponents where
    addComponent :: Component -> Request ()
    removeComponent :: Component -> Request ()
    removeAllComponents :: Request ()
    getComponents :: Request [Component]
    
struct CocoaEnv where
	startApplication	:: (App -> Action) -> Request ()   	-- what to do?           

instance eqComponent :: Eq Component where
  (==) a b = (a.id_temp == b.id_temp)
  (/=) a b = (a.id_temp /= b.id_temp)
  
instance eqCocoaKey :: Eq CocoaKey where
  (==) = (compareKeys True)
  (/=) = (compareKeys False)

instance eqComponentState :: Eq ComponentState where
    (==) = (compareState True)
    (/=) = (compareState False)
    
    
struct App < AppImpl where
    addWindow              :: CocoaWindow -> Request () 
    getApplicationState     :: Request ApplicationState 
struct AppImpl where
    sendInputEvent          :: InputEvent -> WindowID -> Request Bool
    sendWindowResize        :: Size -> WindowID -> Request ()
    sendWindowCloseRequest  :: WindowID -> Request Bool    
    
data ApplicationState = Running | Stopped
data ComponentState = Active | Inactive | Destroyed
data MouseEventType = MouseWheelScroll Position Float Float | MouseClicked Position | MousePressed Position | MouseReleased Position | MouseMoved Position
data KeyEventType  = KeyPressed CocoaKey | KeyReleased CocoaKey
data InputEvent = MouseEvent MouseEventType | KeyEvent KeyEventType

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
                
type Modifiers = [CocoaKey]
type WindowID = Int

extern cocoa :: World -> Class CocoaEnv
extern compareKeys :: Bool -> CocoaKey -> CocoaKey -> Bool
extern compareState :: Bool -> ComponentState -> ComponentState -> Bool
extern mkCocoaID :: Class CocoaID

private
{-  The Cocoa environment will create and pass an instance of this class 
    to the callback installed when startApplication was invoked. 
    
    Note: This class is not meant to be instantiated by users.  
-}

cocoaApplication = class
    activeWindows := []
    blockDefaultCocoaBehavior := False

    addWindow w = request
        w.initWindow this
        activeWindows := w:activeWindows

    modifiers := []

    sendInputEvent (KeyEvent k) windowId = request
        name = case k of 
            (KeyPressed  n) -> n
            (KeyReleased n) -> n
        case name of 
            Tab -> updateList name
            Shift -> updateList name
            Control -> updateList name
            Command -> updateList name
            _ -> 
            
        sendInputToWindow (KeyEvent k) windowId
        result False -- Let keys pass through so that they appear in text fields etc.
    
    sendInputEvent (MouseEvent m) windowId = request
        sendInputToWindow (MouseEvent m) windowId
        
        case m of
            (MouseWheelScroll _ _ _) -> result True -- Block scroll since we control it in Timber instead.
            _ -> result blockDefaultCocoaBehavior
  
    sendInputEvent _ _ = request
        result blockDefaultCocoaBehavior
        
    sendInputToWindow recvEvent windowId = do
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                _ <- window.respondToInputEvent recvEvent modifiers
    
    sendWindowResize toSize windowId = request
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                window.onWindowResize toSize

    shouldClose := True
    sendWindowCloseRequest windowId = request
        shouldClose := True
        forall window <- activeWindows do
            if (<- window.getId == windowId) then
                shouldClose := (<- window.onWindowCloseRequest)
        result shouldClose
    
    updateList key = do
        if (elem key modifiers) then
            modifiers := [d | d <- modifiers, not (d == key) ]
        else 
            modifiers := key : modifiers

    getApplicationState = request
        result Running

    this = App {..}

    result this