module CTCommon where

import POSIX 

data ApplicationState = Running | Stopped
data CocoaState = Active | Inactive | Destroyed

data WindowEventType = WindowClose | WindowResize Size
data MouseEventType = MouseWheelScroll Position Float Float | MouseClicked Position | MousePressed Position | MouseReleased Position | MouseMoved Position
data KeyEventType  = KeyPressed CocoaKey | KeyReleased CocoaKey

data CocoaEvent = WindowEvent WindowEventType | MouseEvent MouseEventType | KeyEvent KeyEventType

data TimberResult = ResultBool Bool | ResultSize Size | ResultPosition Position

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

instance eqComponent :: Eq Component where
  (==) = (compareComponents True)
  (/=) = (compareComponents False)
  
instance eqCocoaKey :: Eq CocoaKey where
  (==) = (compareKeys True)
  (/=) = (compareKeys False)

instance eqCocoaState :: Eq CocoaState where
    (==) = (compareState True)
    (/=) = (compareState False)
    
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
    --getRelativePosition :: Request Position
    
struct HasSize < HasPosition where
    setSize :: Size -> Request ()
    getSize :: Request Size
    
struct HasText where
    setText :: String -> Request ()
    getText :: Request String
    appendText :: String -> Action

struct HasBackgroundColor where
    setBackgroundColor :: Color -> Request ()
    getBackgroundColor :: Request Color
    

    
struct RespondsToWindowEvents where
    onWindowResize :: Size -> Modifiers -> Request ()
    onWindowCloseRequest :: Modifiers -> Request Bool
    setWindowResponder :: RespondsToWindowEvents -> Request ()
    
struct HasResponders where
    addResponder :: RespondsToInputEvents -> Request ()
    setResponders :: [RespondsToInputEvents] -> Request ()
    getResponders :: Request [RespondsToInputEvents]

struct RespondsToInputEvents where
    handleEvent :: CocoaEvent -> Modifiers -> Request Bool

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
    setState :: CocoaState -> Request ()
    getState :: Request CocoaState
    getAllComponents :: Request [Component]

{- This is a hack. We expose id to be able to access the id on each component because this
   is where we hide the pointer into Cocoa! Not used as a "static variable" -}

struct CocoaID where
    dummy :: Int
       
struct Component < BaseComponent where   
    id :: CocoaID          
    init :: App -> Request ()
    destroy :: Request ()

struct ContainsComponents where
    addComponent :: Component -> Request ()
    removeComponent :: Component -> Request ()
    removeAllComponents :: Request ()
    getComponents :: Request [Component]

struct CocoaWindow < HasSize, HasBackgroundColor, ContainsComponents, HasResponders, RespondsToWindowEvents, RespondsToInputEvents where 
    windowId :: CocoaID
    getId :: Request WindowID
    initWindow :: App -> Request ()
    destroyWindow :: Request ()
    hide :: Request Bool
    setVisible :: Request Bool
    setFocus :: Component -> Action
    getFocus :: Request Component
    getContainerID :: Request CocoaID

struct App where
    showWindow              :: CocoaWindow -> Request () 
    getApplicationState     :: Request ApplicationState 
    sendInputEvent          :: CocoaEvent -> WindowID -> Request Bool
    sendWindowResize        :: Size -> WindowID -> Request ()
    sendWindowCloseRequest  :: WindowID -> Request Bool
    setEnv  :: Env -> Request ()


struct DefaultEventResponder < HasResponders, RespondsToInputEvents

basicHasResponders = class

    handlers := []
    addResponder a = request
        handlers := a : handlers

    setResponders aa = request
        handlers := aa
    
    getResponders = request
        result handlers
    
    -- Return true (block cocoa) if any of the installed handlers say so.
    returnVal := False
    handleEvent cocoaEvent modifiers = request
        returnVal := False
        forall h <- handlers do
            res <- h.handleEvent cocoaEvent modifiers
            if (res == True) then
                returnVal := True

        result returnVal
    

    result DefaultEventResponder {..}


basicComponent f p n = class

    baseResponder = new basicHasResponders
    addResponder = baseResponder.addResponder
    setResponders = baseResponder.setResponders
    getResponders = baseResponder.getResponders
    handleEvent = baseResponder.handleEvent

    nameWrap = new wrapper n
    getName = nameWrap.get
    setName = nameWrap.set
    
    parentWrap = new wrapper p
    getParent = parentWrap.get
    setParent = parentWrap.set

    focusWrap = new wrapper f
    getIsFocusable = focusWrap.get
    setIsFocusable = focusWrap.set
    
    positionWrap = new wrapper ({x=0; y=0})
    getPosition = positionWrap.get
    setPosition = positionWrap.set
    
    sizeWrap = new wrapper ({width=100; height=100})
    getSize = sizeWrap.get
    setSize = sizeWrap.set
    
    {-state := Inactive 
    getState = request
        result state
        
    setState s = request
        if (state /= Destroyed) then
            state := s -}
    stateWrap = new wrapper Inactive
    getState = stateWrap.get
    setState = stateWrap.set
    
    getAllComponents = request
        result []
    
    result BaseComponent {..}

struct Wrapper a where
    set :: a -> Request ()
    get :: Request a
    
wrapper s = class
    a := s
    
    set b = request
        a := b
        
    get = request
        result a
        
    result Wrapper {..}


dynamicHandleEvent :: a -> Maybe (a -> Request Bool) -> Cmd _ Bool
dynamicHandleEvent event (Just handler) = do
    result (<- handler event)

dynamicHandleEvent _ Nothing = do
    result False

showName Nothing = do result "Nothing"
showName (Just c) = do result <- c.getName

--other stuff
extern mkCocoaID :: Class CocoaID
extern compareCocoaIDs :: CocoaID -> CocoaID -> Bool
extern compareComponents :: Bool -> Component -> Component -> Bool
extern compareKeys :: Bool -> CocoaKey -> CocoaKey -> Bool
extern compareState :: Bool -> CocoaState -> CocoaState -> Bool
