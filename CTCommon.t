module CTCommon where

import POSIX 

data ApplicationState = Running | Stopped
data CocoaState = Active | Inactive | Destroyed

data WindowEventType = WindowClosed | WindowNotClosed
data MouseEventType = MouseClicked Position | MousePressed Position | MouseReleased Position | MouseMoved Position
data KeyEventType  = KeyPressed CocoaKey | KeyReleased CocoaKey

data CocoaEvent = WindowEvent WindowEventType | MouseEvent MouseEventType | KeyEvent KeyEventType

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

instance eqCocoaKey :: Eq CocoaKey where
  (==) = compareKeys
  (/=) = compareKeys

instance eqCocoaState :: Eq CocoaState where
    (==) = compareState
    (/=) = compareState
    
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
    setPosition :: Position -> Action
    getPosition :: Request Position
    
struct HasSize < HasPosition where
    setSize :: Size -> Action
    getSize :: Request Size

struct HasBackgroundColor where
    setBackgroundColor :: Color -> Action
    getBackgroundColor :: Request Color
    
struct HandlesEvents where
    handleEvent :: CocoaEvent -> [CocoaKey] -> Request (Maybe Component)

struct HandlesWindowEvents < HandlesEvents where
    installWindowListener :: (WindowEventType -> Request Bool) -> Request ()

struct HandlesKeyEvents where
    installKeyListener :: (KeyEventType -> Request Bool) -> Request ()
    
struct HandlesMouseEvents where
    installMouseListener :: (MouseEventType -> Request Bool) -> Request ()

struct IsFocusable where
    setNextFocusTarget :: (Maybe Component) -> Request ()
    getNextFocusTarget :: Request (Maybe Component)
    setPreviousFocusTarget :: (Maybe Component) -> Request ()
    getPreviousFocusTarget :: Request (Maybe Component)
    setIsFocusable :: Bool -> Request ()
    getIsFocusable :: Request Bool
    
struct CocoaID where
    dummy :: Int

{- This is a hack. We expose id to be able to access the id on each component because this
   is where we hide the pointer into Cocoa! Not used as a "static variable" -}                 
struct Component < IsFocusable, HasSize, HandlesEvents where   
    id :: CocoaID          
    init :: App -> Request ()
    destroy :: Request ()
    setName :: String -> Request ()
    getName :: Request String

struct ContainsComponents where
    addComponent :: Component -> Request ()
    getComponents :: Request [Component]

struct CocoaWindow < ContainsComponents, HandlesKeyEvents, HandlesWindowEvents, HandlesMouseEvents where 
    windowId :: CocoaID
    getId :: Request Int
    initWindow :: App -> Request ()
    destroyWindow :: Request ()
    hide :: Request Bool
    setVisible :: Request Bool
    setFocus :: Component -> Action

struct App where
    showWindow          :: CocoaWindow -> Request () 
    getApplicationState :: Request ApplicationState 
    eventDispatcher     :: CocoaEvent -> Int -> Action
    setEnv  :: Env -> Request ()

focusWrapper this focusable = class
    next := (Just this)
    previous := (Just this)
    isFocusable := focusable
    
    setNextFocusTarget target = request
        next := target

    focusResult Nothing = do result Nothing
    focusResult (Just a) = do
        if (<- a.getIsFocusable) then
            result (Just a)
        else
            result (<- a.getNextFocusTarget)
    
    getNextFocusTarget = request
        result (<- focusResult next)

    setPreviousFocusTarget target = request
        previous := target

    getPreviousFocusTarget = request
        result previous

    setIsFocusable isIt = request
        isFocusable := isIt

    getIsFocusable = request
        result isFocusable  

    result IsFocusable{..}

dynamicHandleEvent :: a -> Maybe (a -> Request Bool) -> Cmd _ Bool
dynamicHandleEvent event (Just handler) = do
    result (<- handler event)

dynamicHandleEvent _ Nothing = do
    result False

boolToMaybe (Just cmp) True = Just cmp
boolToMaybe _ False = Nothing
boolToMaybe _ _ = Nothing -- why is this needed????????????????????

showName Nothing = do result "Nothing"
showName (Just c) = do result <- c.getName

--other stuff
extern mkCocoaID :: Class CocoaID
extern compareCocoaIDs :: CocoaID -> CocoaID -> Bool
extern compareKeys :: CocoaKey -> CocoaKey -> Bool
extern compareState :: CocoaState -> CocoaState -> Bool
