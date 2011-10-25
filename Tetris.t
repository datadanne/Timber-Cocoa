module Tetris where

import POSIX
import COCOA
import CTWindow
import CTContainer  -- Compiler panic if this redundant import of CTContainer is removed
import RandomGenerator

data TileValue = EmptyTile | RedTile | GreenTile | BlueTile | OutOfBoundsTile
deriving instance eqTileValue :: Eq TileValue

gameGridWidth = 10
gameGridHeight = 20

root w = class
    env = new posix w
    osx = new cocoa w
    
    gameWindow = new mkCocoaWindow env
    gameGrid = new tetrisGrid 10 20 env
    gu = new gridUpdater gameGrid env
    
    -- Responder for keyboard events
    testResponder event modifiers = request
        case event of
            (KeyEvent (KeyPressed theKey)) ->
                case (theKey) of
                    A -> gu.movePiece (-1) 0
                    S -> gu.movePiece 0 1
                    D -> gu.movePiece 1 0
                    _ -> 

                gameGrid.update
            _ ->
        result False
        
    gameLoop env = action
        _ <- gu.movePiece 0 1
        gu.clearFilledLines
        gameGrid.update        
        after (millisec 500) send gameLoop env
                
    applicationDidFinishLaunching app = action
        app.addWindow gameWindow
        send gameLoop env

    result action
        gameGrid.setPosition ({x=30;y=20})
        gameWindow.addResponder ({respondToInputEvent=testResponder}) 
        gameWindow.setSize ({width=300;height=500})
        gameWindow.setBackgroundColor ({r=100;g=100;b=100})
        gameWindow.addComponent gameGrid

        osx.startApplication applicationDidFinishLaunching

struct GridUpdater < HasPosition where
    movePiece :: Int -> Int -> Request Bool
    clearFilledLines :: Request ()
    
gridUpdater gameGrid env = class
    randomizer = new baseGen 31415926
    
    -- These default values are not used.
    shape := array []
    color :: TileValue
    color := RedTile
    position := {x=0;y=0}

    movePiece addX addY = request
        -- Ensure we have a valid piece.
        if (size shape <= 0 || size shape > 25) then
            createNextPiece
        
        -- Perform collision test. Begin by removing the piece to avoid it interfering.
        setPieceValues EmptyTile
        collides <- testCollision addX addY
        if (not collides) then
            position := {x=position.x+addX;y=position.y+addY}
        elsif (addX == 0 && addY == 1) then
            -- Sideway collision is ok but we now hit something while descending! Create a new piece.
            setPieceValues color
            createNextPiece
        setPieceValues color
        
        result (not collides)

    blocksInRow := 0
    clearFilledLines = request
        setPieceValues EmptyTile
        forall row <- [1..gameGridHeight] do
                blocksInRow := 0
                forall col <- [1..gameGridWidth] do
                    lineVal = <- gameGrid.getValueAt col row
                    if (lineVal /= EmptyTile && lineVal /= OutOfBoundsTile ) then
                        blocksInRow := blocksInRow + 1 

                if (blocksInRow == gameGridWidth) then
                    forall col <- [1..gameGridWidth] do
                        forall r <- [0 .. (row-2)] do
                            above <- gameGrid.getValueAt col (row-r-1)
                            gameGrid.setValueAt col (row-r) above
        setPieceValues color

    nextShape := square
    createNextPiece = do
        (startX,startY, newShape) = nextShape
        shape := newShape
        position := {x=startX;y=startY}
        color := case ((<- randomizer.next) `mod` 3 +1) of
                    3 -> BlueTile
                    2 -> GreenTile
                    _ -> RedTile

        nextShapeId = <- (randomizer.next) `mod` 3 + 1
        case (nextShapeId) of
            1 -> nextShape := square
            2 -> nextShape := linePiece0
            _ -> nextShape := linePiece90
            
    collision := False
    testCollision offsetX offsetY = do
        collision := False

        forall ty <- [0..4] do
            forall tx <- [0..4] do
                if (shape!(5*ty+tx) > 0) then
                    gridValue <- gameGrid.getValueAt (tx+position.x+offsetX) (ty+position.y+offsetY)
                    collision := collision || (isTrue gridValue)
        result collision
    
    setPieceValues val = do
        forall tx <- [0..4] do
            forall ty <- [0..4] do
                if (shape!(5*ty+tx) > 0) then
                    gameGrid.setValueAt (tx+position.x) (ty+position.y) val
    
    setPosition s = request
        position := s
        
    getPosition = request
        result position
        
    result GridUpdater {..}
    
struct GameGrid < Container where
    setColorAt :: Int -> Int -> (Int,Int,Int) -> Request Bool
    setValueAt :: Int -> Int -> TileValue -> Request Bool
    getValueAt :: Int -> Int -> Request TileValue
    clear :: Request ()
    update :: Request ()
    
tetrisGrid width height env = class
    -- Grid of tiles. Each tile has (X,Y,TileValue,Container)
    grid :: [(Int, Int, TileValue, Container)]
    grid := []
    
    blocksInRow := 0
    update = request
        forall (tx,ty,val,container) <- grid do
            case (val) of
                RedTile -> container.setBackgroundColor ({r=250;g=100;b=100})
                GreenTile -> container.setBackgroundColor ({r=70;g=170;b=250})
                BlueTile -> container.setBackgroundColor ({r=170;g=250;b=70})
                OutOfBoundsTile-> container.setBackgroundColor ({r=255;g=255;b=255})
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
        result (<- internalSetValueAt x y val)
    
    internalSetValueAt x y val = do
        newGrid := []
        
        forall (tileX,tileY,oldVal,container) <- grid do
            if (tileX == x && tileY == y) then
                newGrid := (tileX,tileY,val,container) : newGrid
            else
                newGrid := (tileX,tileY,oldVal,container) : newGrid

        grid := newGrid

        result False

    value := OutOfBoundsTile
    getValueAt x y = request
        result (<- internalGetValueAt x y)
        
    internalGetValueAt x y = do
        value := OutOfBoundsTile
        forall (tileX,tileY,val, container) <- grid do
            if (tileX == x && tileY == y) then
                value := val
        result value
    
    clear = request
        newGrid := []
        forall (x,y,val, container) <- grid do
            newGrid := (x,y,EmptyTile,container) : newGrid
        grid := newGrid
                
    init app = request
        tileSize = 20
        backgroundColor = ({r=0;g=0;b=0})
        base.setSize ({width=1+(tileSize+1)*width;height=1+(tileSize+1)*height})
        base.setBackgroundColor ({r=200;g=200;b=200})
        base.init app
        
        forall row <- [1..height] do
            forall col <- [1..width] do
               tile = new mkCocoaContainer env
               tile.setSize ({width=tileSize;height=tileSize})
               tile.setBackgroundColor backgroundColor
               tile.setPosition ({x=(col-1)*(tileSize+1)+1;y=(row-1)*(tileSize+1)+1})
               grid := (col,row, EmptyTile, tile) : grid
               base.addComponent tile
               
    destroy = request

    -- Fill out rest of interface using base container --
    base = new mkCocoaContainer env
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
    
    getCocoaRef = base.getCocoaRef

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
               
    result GameGrid {id_temp=base.id_temp;..}
  
isTrue (EmptyTile) = False
isTrue _ = True  
    
{- 
    Tetris shapes!
    
    Structure is: (offsetX, offsetY, shape)
-}


square = (4,(-2), array [0,0,0,0,0, 
                       0,0,0,0,0, 
                       0,0,2,1,0, 
                       0,0,1,1,0, 
                       0,0,0,0,0])
               
linePiece0 = (3,(-2), array [0,0,0,0,0, 
                           0,0,0,0,0, 
                           0,1,2,1,1, 
                           0,0,0,0,0, 
                           0,0,0,0,0])

linePiece90 = (4,(-1), array [0,0,0,0,0, 
                            0,0,1,0,0, 
                            0,0,2,0,0, 
                            0,0,1,0,0, 
                            0,0,1,0,0])
                     
linePiece180 = (2,(-2), array [0,0,0,0,0, 
                             0,0,0,0,0, 
                             1,1,2,1,0, 
                             0,0,0,0,0, 
                             0,0,0,0,0])
                     
linePiece270 = (4,0, array [0,0,1,0,0, 
                             0,0,1,0,0, 
                             0,0,2,0,0, 
                             0,0,1,0,0, 
                             0,0,0,0,0])