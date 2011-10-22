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
    setShape :: (Int,Int,(Int,Int,Int), Array Int) -> Request ()
    movePiece :: Int -> Int -> Request Bool
    
tetrisPiece gameGrid env = class
    position := {x=0;y=0}
    shape := array [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    collision := False
    color := (250,150,150)
    
    setShape s = request
        (startX,startY, (r,g,b), newShape) = s
        
        position := {x=startX;y=startY}
        shape := newShape
        color := (r,g,b)
                    
    movePiece addX addY = request
        setPieceValues 0 -- remove from grid temporarily to not interfere with collision test

        collides <- testCollision addX addY
        if (not collides) then
            position := {x=position.x+addX;y=position.y+addY}
        
        setPieceValues 1
        setPieceColors
        result (not collides)    

    testCollision offsetX offsetY = do
        collision := False

        forall tx <- [0..4] do
            forall ty <- [0..4] do
                if (shape!(5*tx+ty) > 0) then
                    gridValue <- gameGrid.getValueAt (tx+position.x+offsetX) (ty+position.y+offsetY)
                    env.stdout.write ("grid value: " ++ (show gridValue) ++ "\n")
                    collision := collision || (isTrue gridValue)
                    

        result collision

    removeFromGrid = request
        setPieceValues 0
    
    addToGrid = request
        setPieceValues 1

    setPieceColors = do
        forall tx <- [0..4] do
            forall ty <- [0..4] do
                if (shape!(5*tx+ty) > 0) then
                    gameGrid.setColorAt (tx+position.x) (ty+position.y) color
        
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

    color := (0,0,0)
    update = request
        forall (tx,ty,val,(r,g,b),container) <- grid do
            case (val) of
                1 -> container.setBackgroundColor ({r=r;g=g;b=b})

                _ -> container.setBackgroundColor ({r=50;g=50;b=50})

        
    -- Remove a tile and replace it with a tile with the new value.

    setColorAt x y newColor = request
        newGrid := []
        forall (tx,ty,val,tileColor,container) <- grid do
            if (tx == x && ty == y) then
                newGrid := (tx,ty,val,tileColor,container) : newGrid
            else
                newGrid := (tx,ty,val,newColor,container) : newGrid
        grid := newGrid
        result False
        
    newGrid := []
    setValueAt x y val = request
        newGrid := []
        
        forall (tileX,tileY,oldVal,tileColor,container) <- grid do
            if (tileX == x && tileY == y) then
                newGrid := (tileX,tileY,val,tileColor,container) : newGrid
            else
                newGrid := (tileX,tileY,oldVal,tileColor,container) : newGrid

        grid := newGrid

        result False
        
    value := -1
    getValueAt x y = request
        value := -1
        forall (tileX,tileY,val, c, container) <- grid do
            if (tileX == x && tileY == y) then
                value := val
        result value
    
    grid :: [(Int, Int, Int, (Int,Int,Int), Container)]
    grid := []
    
    clearColor = (100,100,100)
    clearValue = 0
    
    clear = request
        newGrid := []
        forall (x,y,val,c, container) <- grid do
            newGrid := (x,y,clearValue,clearColor,container) : newGrid
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
               grid := (col,row, clearValue, clearColor, tile) : grid
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


square = (4,18, (150,0,0), array [0,0,0,0,0, 
                       0,0,0,0,0, 
                       0,0,2,1,0, 
                       0,0,1,1,0, 
                       0,0,0,0,0])
               
linePiece0 = (3,18, (0,150,0), array [0,0,0,0,0, 
                           0,0,0,0,0, 
                           0,1,2,1,1, 
                           0,0,0,0,0, 
                           0,0,0,0,0])

linePiece90 = (4,18, (0,150,0), array [0,0,0,0,0, 
                            0,0,1,0,0, 
                            0,0,2,0,0, 
                            0,0,1,0,0, 
                            0,0,1,0,0])
                     
linePiece180 = (4,18, (0,150,0), array [0,0,0,0,0, 
                             0,0,0,0,0, 
                             1,1,2,1,0, 
                             0,0,0,0,0, 
                             0,0,0,0,0])
                     
linePiece270 = (4,18, (0,150,0), array [0,0,1,0,0, 
                             0,0,1,0,0, 
                             0,0,2,0,0, 
                             0,0,1,0,0, 
                             0,0,0,0,0])