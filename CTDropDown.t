module CTDropDown where

import CTCommon   
import POSIX

struct DropDown < Component, RespondsToSelectionEvents where
    addOption :: String -> Action
    setOptions :: [String] -> Action
    getOptions :: Request [String]
    getCurrentOption :: Request String

--------------------------------------------------------------------------------------------------
------          ** CTDropDown **            ----------------------------------------------------------
indexOf :: Int -> [a] -> a -> Int \\ Eq a
indexOf count (x:xs) elem
    | x == elem     = count
    | otherwise     = indexOf (count+1) xs elem
indexOf count [] _  = count
        
mkCocoaDropDown env = class
    size := {width=108; height=17}
    extendedSize := {width=108; height=17}
    sizeState := Small
    
    title := ""
    position := {x=0; y=0}

    --extendedPosition := {x=0; y=0} 
    --tempSize := {width=0; height=0}
    --tempPosition := {x=0; y=0}    
    -- constants
    --topAndBottomOffset = 4                        
    --rightOffset = 6 
    --expandedOptionHeight = 18
    --            
    
    --keyEventHandler := Nothing
    --mouseEventHandler := Nothing 
    --selectionEventHandler := Nothing
    
    id = new mkCocoaID
    base = new basicComponent True Nothing "DropDown"
    addResponder = base.addResponder
    setResponders = base.setResponders
    getResponders = base.getResponders

    dsh := new defaultSelectionResponder env
    selectionChanged str = action
        dsh.selectionChanged str
        
    setSelectionResponder resp = request
        dsh := resp
        
    setParent = base.setParent
    getParent = base.getParent
    setIsFocusable = base.setIsFocusable
    getIsFocusable = base.getIsFocusable
    setName = base.setName
    getName = base.getName
    getState = base.getState
    setState = base.setState
    getAllComponents = base.getAllComponents
    respondToInputEvent = base.respondToInputEvent
    
    options := []
    
    addOption o = action
        _ <- insertOption o
    
    insertOption o = do
        options := o : options
        
        --extendedSize := <- calculateExtendedSize
        --extendedPosition := <- calculateExtendedPosition
        env.stdout.write ("adding option " ++ (show o))
        case (<- base.getState) of
            Active ->   dropDownAddOption id o  
                        currentOption := <- dropDownGetSelectedOption id
            _ ->
        
        
    setOptions os = action
        forall o <- os do
            _ <- insertOption o
        
    getOptions = request
        result options
    
    currentOption := ""
    
    refreshMyOptionAndPerformCallback = action 
        currentOption := <- dropDownGetSelectedOption id
        send selectionChanged currentOption
        
    getCurrentOption = request
        --opt <- cocoaGetCurrentOption id
        result currentOption

    -- setPosition
    setPosition p = request
        case (<- base.getState) of
            Active -> dropDownSetPosition id p
            _ -> 
        position := p       
    
    -- getPosition  
    getPosition = request
        result position

    setSize s = request
        case (<- base.getState) of
            Active -> dropDownSetSize id s
            _ ->
        size := s

    getSize = request
        result size
        
    destroy = request
        base.setState Destroyed
        
{-    installKeyListener kl = request
        keyEventHandler := Just kl

    installMouseListener ml = request
        mouseEventHandler := Just ml
        
    installSelectionListener sl = request
        selectionEventHandler := Just sl
-}    
    

    -- undocumented feature in Timber, init must be placed above this else we have some nice raise(2); :-)
    init app = request
            base.setState Active
            initDropDown this app
            
            inithelper
    
    inithelper = do
        forall o <- options do
            dropDownAddOption id o
            
        dropDownSetPosition id position
        currentOption := <- dropDownGetSelectedOption id   

        sh = new defaultHandler refreshMyOptionAndPerformCallback
        base.addResponder sh

            
    this = DropDown{..}

    result this


defaultSelectionResponder env = class
    selectionChanged str = action
        env.stdout.write ("selection changed to: " ++ str)
        
    setSelectionResponder _ = request -- not used ..
    
    result RespondsToSelectionEvents {..}



data SizeState = Small | Expanded
deriving instance eqSizeState :: Eq SizeState
 
defaultHandler dropdownUpdateMethod = class 
    sizeState := Small
    
    respondToInputEvent (KeyEvent t) modifiers = request
        result False 

    respondToInputEvent (MouseEvent t) modifiers = request
        case t of
            MouseClicked pos ->
                if (sizeState == Small) then
                                        --dropDownSetLastClickPosition id pos 
                    sizeState := Expanded
                else
                    sizeState := Small
                    dropdownUpdateMethod
                                        --currentOption := <- dropDownGetSelectedOption id
                                        --dynamicHandleEvent currentOption selectionEventHandler
            _ ->    
        result True 

    respondToInputEvent _ modifiers = request
        result False 
        
    result RespondsToInputEvents {..}
    
    
    
    
    
    
    
{-calculateExtendedPosition = do

        numberOfOptions = length options
        currentIndex = indexOf 0 options currentOption
        
        env.stdout.write ("nrOfOptions: " ++ (show numberOfOptions) ++ " - currentIndex: " ++ (show currentIndex) ++ "\n")
        
        x = position.x
        y = position.y - topAndBottomOffset                                                                       
        
        
        
        toReturn = {x = x; y = (y - currentIndex*expandedOptionHeight)}

        --updateExpandedPos toReturn

        env.stdout.write ("calculated extpos to " ++ (show toReturn.x) ++ ", " ++ (show toReturn.y) ++ "\n")
        result toReturn
        
    calculateExtendedSize = do
        numberOfOptions = length options
        
        env.stdout.write ("nr of options: " ++ (show numberOfOptions))
        
        baseWidth = (<- base.getSize).width                                                              
                         
        env.stdout.write ("basewidth: " ++ (show baseWidth))
        
        width = baseWidth - rightOffset    
        
        env.stdout.write ("width " ++ (show width))
        
        height = 2*topAndBottomOffset + (numberOfOptions)*expandedOptionHeight
                                         
        env.stdout.write ("height" ++ (show height))
        
        result {width=width; height=height}
    
    adjustUpwards pos count = do
        if (count == 0) then
            result pos
        else
            result <- adjustUpwards ({x=pos.x-topAndBottomOffset;y=pos.y}) (count-1)
    -}                  
--------------------------------------------------------------------------------------------------
------          ** EXTERN **            ----------------------------------------------------------  

--dropDown  
private
extern optionWasSelected :: DropDown -> String -> Action      
extern initDropDown :: DropDown -> App -> Request ()
extern dropDownAddOption :: CocoaID -> String -> Action
extern dropDownSetPosition :: CocoaID -> Position -> Action
extern dropDownSetSize :: CocoaID -> Size -> Action
extern dropDownSetLastClickPosition :: CocoaID -> Position -> Action
extern dropDownGetSelectedOption :: CocoaID -> Request String