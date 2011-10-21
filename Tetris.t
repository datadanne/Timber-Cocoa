module Tetris where

import POSIX
import COCOA
import CTContainer  -- Compiler panic if this redundant import of CTContainer is removed

root w = class
    env = new posix w
    osx = new cocoa w
    
    gameWindow = new mkCocoaWindow env
    gameGrid = new tetrisGrid 10 20 env
    
    getKey (KeyPressed key) = key
    getKey _ = raise 9

    
    testResponder (KeyEvent keyEventType) modifiers = request
        theKey = getKey keyEventType
        case (theKey) of
            W -> iteration := iteration +1
            A -> iteration := iteration -20
            S -> iteration := iteration -1
            D -> iteration := iteration +20
            _ -> 
            
        if (iteration < 0) then
            iteration := (-iteration)
        if (iteration > 200) then
            iteration := iteration - 200
            
        result False
    
    testResponder _ modifiers = request
        result False
        
    iteration := 0
    tileX := 0
    tileY := 0
    currentPiece := square

    gameLoop env = action
        gameGrid.clear
        
        (currentX,currentY, currentShape) = currentPiece
        tileX := 0
        tileY := 0
        forall tx <- [0..4] do
            forall ty <- [0..4] do
                if (currentShape!(5*tx+ty) > 0) then
                    gameGrid.setValueAt (1+tx+currentX) (1+ty+currentY) 1        
        
        currentPiece := (currentX,currentY-1,currentShape)
        
        gameGrid.update                
        after (millisec 1250) send gameLoop env
                
    applicationDidFinishLaunching app = action

        gameWindow.addResponder ({respondToInputEvent=testResponder})
        
        gameWindow.setSize ({width=300;height=500}) 
        gameWindow.setBackgroundColor ({r=100;g=100;b=100})
        gameWindow.addComponent gameGrid
        app.addWindow gameWindow
        
        send gameLoop env
    result action
        osx.startApplication applicationDidFinishLaunching

struct GameGrid < Container where
    setValueAt :: Int -> Int -> Int -> Request Bool
    getValueAt :: Int -> Int -> Request Int
    clear :: Request ()
    update :: Request ()
    
tetrisGrid width height env = class
    base = new mkCocoaContainer env
    id = base.id

    color := ({r=0;g=0;b=0})
    update = request
        forall (tileX,tileY,val,container) <- grid do
            --env.stdout.write ("("++(show tileX)++","++ (show tileY)++") : " ++ (show val) ++ "\n")
            case (val) of
                1 -> color := ({r=255;g=0;b=0})
                     container.setBackgroundColor color

                _ -> color := ({r=0;g=110;b=0})
                     container.setBackgroundColor color

        
    -- Remove a tile and replace it with a tile with the new value.
    newGrid := []
    setValueAt x y val = request
        newGrid := []
        
        forall (tileX,tileY,oldVal, container) <- grid do
            if (tileX == x && tileY == y) then
                newGrid := (tileX,tileY,val,container) : newGrid
            else
                newGrid := (tileX,tileY,oldVal,container) : newGrid

        grid := newGrid

        result False
        
    value := -1
    getValueAt x y = request
        value := -1
        forall (tileX,tileY,val, container) <- grid do
            if (tileX == x && tileY == y) then
                value := val
        result value
    
    grid :: [(Int, Int, Int, Container)]
    grid := []
    
    clear = request
        newGrid := []
        forall (x,y,val,container) <- grid do
            newGrid := (x,y,0,container) : newGrid
        grid := newGrid
                
    init app = request
        tileSize = 20
        backgroundColor = ({r=0;g=0;b=0})
        base.setSize ({width=tileSize*12;height=tileSize*34})
        base.init app
        
        forall row <- [1..height] do
            forall col <- [1..width] do    
               tile = new mkCocoaContainer env
               tile.setSize ({width=tileSize;height=tileSize})
               tile.setBackgroundColor ({r=10*row;g=10*col;b=128})--backgroundColor
               tile.setPosition ({x=col*tileSize;y=(row+1)*tileSize})
               grid := (col,row, 0, tile) : grid
               
               base.addComponent tile
               
    destroy = request

    -- Fill out rest of interface using base container --
    addResponder = base.addResponder
    setResponders = base.setResponders
    getResponders = base.getResponders
    setParent = base.setParent
    getParent = base.getParent
    setIsFocusable = base.setIsFocusable
    getIsFocusable = base.getIsFocusable
    setName s = base.setName s
    getName = base.getName
    getState = base.getState
    setState = base.setState
    respondToInputEvent = base.respondToInputEvent

    setPosition = base.setPosition
    getPosition = base.getPosition

    setSize = base.setSize
    getSize = base.getSize

    setBackgroundColor = base.setBackgroundColor
    getBackgroundColor = base.getBackgroundColor
    
    addComponent = base.addComponent
    removeComponent = base.removeComponent
    removeAllComponents = base.removeAllComponents
    getAllComponents = base.getAllComponents
    getComponents = base.getComponents
               
    result GameGrid {..}
    
    
{- 
    Tetris shapes!
    
    Structure is: (offsetX, offsetY, shape)
-}


square = (4,18, array [0,0,0,0,0, 
                       0,0,0,0,0, 
                       0,0,2,1,0, 
                       0,0,1,1,0, 
                       0,0,0,0,0])
               
linePiece0 = (3,18, array [0,0,0,0,0, 
                           0,0,0,0,0, 
                           0,1,2,1,1, 
                           0,0,0,0,0, 
                           0,0,0,0,0])

linePiece90 = (4,18, array [0,0,0,0,0, 
                            0,0,1,0,0, 
                            0,0,2,0,0, 
                            0,0,1,0,0, 
                            0,0,1,0,0])
                     
linePiece180 = (4,18, array [0,0,0,0,0, 
                             0,0,0,0,0, 
                             1,1,2,1,0, 
                             0,0,0,0,0, 
                             0,0,0,0,0])
                     
linePiece270 = (4,18, array [0,0,1,0,0, 
                             0,0,1,0,0, 
                             0,0,2,0,0, 
                             0,0,1,0,0, 
                             0,0,0,0,0])