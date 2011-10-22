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
            A -> currentPiece.movePiece (-1) 0
            S -> currentPiece.movePiece 0 (-1)
            D -> currentPiece.movePiece 1 0
            _ -> 

        gameGrid.update
        
        result False
    
    testResponder _ modifiers = request
        result False

    currentPiece := new tetrisPiece gameGrid env

    gameLoop env = action
        moved <- currentPiece.movePiece 0 (-1)
        isAt <- currentPiece.getPosition
        env.stdout.write ("moving piece: " ++ (show isAt.x) ++ "," ++ (show isAt.y) ++ ":" ++ (show moved) ++ "\n")
        if (not moved) then
            currentPiece.setShape square
            
        gameGrid.update        
        after (millisec 500) send gameLoop env
                
    applicationDidFinishLaunching app = action
        app.addWindow gameWindow
        send gameLoop env
    result action
        currentPiece.setShape square
        currentPiece.addToGrid

        gameWindow.addResponder ({respondToInputEvent=testResponder}) 
        gameWindow.setSize ({width=300;height=500}) 
        gameWindow.setBackgroundColor ({r=100;g=100;b=100})
        gameWindow.addComponent gameGrid

        osx.startApplication applicationDidFinishLaunching

struct TetrisPiece < HasPosition where
    removeFromGrid :: Request ()
    addToGrid :: Request ()
    setShape :: (Int,Int, Array Int) -> Request ()
    movePiece :: Int -> Int -> Request Bool
    
tetrisPiece gameGrid env = class
    position := {x=0;y=0}
    shape := array [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    collision := False
        
    setShape s = request
        (startX,startY, newShape) = s
        
        position := {x=startX;y=startY}
        shape := newShape
                    
    movePiece addX addY = request
        setPieceValues 0 -- remove from grid temporarily so as to not interfere with collision test

        collides <- testCollision addX addY
        if (not collides) then
            position := {x=position.x+addX;y=position.y+addY}
        
        setPieceValues 1
        result (not collides)    

    testCollision offsetX offsetY = do
        collision := False

        forall tx <- [0..4] do
            forall ty <- [0..4] do
                if (shape!(5*tx+ty) > 0) then
                    gridValue <- gameGrid.getValueAt (tx+position.x+offsetX) (ty+position.y+offsetY)
                    --env.stdout.write ("grid value: " ++ (show gridValue) ++ "\n")
                    collision := collision || (isTrue gridValue)
                    

        result collision

    removeFromGrid = request
        setPieceValues 0
    
    addToGrid = request
        setPieceValues 1
    
    setPieceValues val = do
        forall tx <- [0..4] do
            forall ty <- [0..4] do
                if (shape!(5*tx+ty) > 0) then
                    gameGrid.setValueAt (tx+position.x) (ty+position.y) val
    
    setPosition s = request
        position := s
        
    getPosition = request
        result position
        
    result TetrisPiece {..}
    
struct GameGrid < Container where
    setColorAt :: Int -> Int -> (Int,Int,Int) -> Request Bool
    setValueAt :: Int -> Int -> Int -> Request Bool
    getValueAt :: Int -> Int -> Request Int
    clear :: Request ()
    update :: Request ()
    
tetrisGrid width height env = class
    base = new mkCocoaContainer env
    id = base.id
    
    emptyTile = 0
    redTile = 1
    greenTile = 2
    blueTile = 3

    -- Grid of tiles. Each tile has (X,Y, Value, Container)
    grid :: [(Int, Int, Int, Container)]
    grid := []
    
    color := (0,0,0)
    update = request
        forall (tx,ty,val,container) <- grid do
            case (val) of
                1 -> container.setBackgroundColor ({r=250;g=100;b=100})
                _ -> container.setBackgroundColor ({r=50;g=50;b=50})

    setColorAt x y newColor = request
        newGrid := []
        forall (tx,ty,val,container) <- grid do
            if (tx == x && ty == y) then
                newGrid := (tx,ty,val,container) : newGrid
            else
                newGrid := (tx,ty,val,container) : newGrid
        grid := newGrid
        result False

    -- Remove a tile and replace it with a tile with the new value.        
    newGrid := []
    setValueAt x y val = request
        newGrid := []
        
        forall (tileX,tileY,oldVal,container) <- grid do
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
    
    clear = request
        newGrid := []
        forall (x,y,val, container) <- grid do
            newGrid := (x,y,emptyTile,container) : newGrid
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
               tile.setBackgroundColor backgroundColor
               tile.setPosition ({x=col*(tileSize+1);y=(row+1)*(tileSize+1)})
               grid := (col,row, emptyTile, tile) : grid
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
  
isTrue 0 = False
isTrue _ = True  
    
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