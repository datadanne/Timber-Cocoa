module Tetris where

import POSIX
import COCOA
import CTButton
import CTWindow
import CTContainer  -- Compiler panic if this redundant import of CTContainer is removed
import RandomGenerator

data TileValue = EmptyTile | RedTile | OrangeTile | BlueTile | OutOfBoundsTile
-- deriving instance eqTileValue :: Eq TileValue 
-- Stopped working after update. Haven't figured out why yet...

gameGridWidth = 10
gameGridHeight = 20

root w = class
    env = new posix w
    osx = new cocoa w
    
    gameWindow = new mkCocoaWindow
    gameGrid = new tetrisGrid gameGridWidth gameGridHeight env
    gu = new gridUpdater gameGrid env
    
    startButton = new mkCocoaButton env
    
    -- Responder for keyboard events
    keyboardResponder event modifiers = request
        case event of
            (KeyEvent (KeyPressed theKey)) ->
                case (theKey) of
                    A -> 
                         gu.movePiece (-1) 0
                         gameGrid.update
                    S -> gu.movePiece 0 1
                         gameGrid.update
                    D -> gu.movePiece 1 0
                         gameGrid.update
                    _ -> 
            _ ->
        result False

    started := False
    newGameResponder event modifiers = request
        case event of
            (MouseEvent m) ->
                if (not started) then
                    started := True
                    after (millisec 500) send gameLoop env
            _ ->
        result False
        
    gameLoop env = action
        if (not (<- gu.checkGameOver)) then
            gu.movePiece 0 1
            gu.clearFilledLines
            gameGrid.update
            after (millisec 500) send gameLoop env

    applicationDidFinishLaunching app = action
        app.addWindow gameWindow
        
    result action
        gameGrid.setPosition ({x=30;y=20})

        startButton.setPosition ({x=270;y=20})
        startButton.setTitle "New Game"
        startButton.addResponder ({respondToInputEvent=newGameResponder})
        
        gameWindow.setSize ({width=400;height=500})
        gameWindow.setBackgroundColor ({r=100;g=100;b=100})
        gameWindow.setPosition ({x=100;y=100})
        gameWindow.addComponent startButton
        gameWindow.addComponent gameGrid
        gameWindow.addResponder ({respondToInputEvent=keyboardResponder}) 

        osx.startApplication applicationDidFinishLaunching


struct GridUpdater < HasPosition where
    movePiece :: Int -> Int -> Request Bool
    clearFilledLines :: Request ()
    checkGameOver :: Request Bool
    
gridUpdater gameGrid env = class
    movePiece x y = request result False
    clearFilledLines = request
    checkGameOver = request result False
    
    getPosition = request result ({x=0;y=0})
    setPosition s = request

    randomizer = new baseGen 31415926
    position := {x=0;y=0}
    gameOver := False    
    
    shape :: Array Int
    shape := array []
    
    color :: TileValue
    color := RedTile

    checkGameOver = request
        result gameOver

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
            if (position.y < 0) then
                -- Game Over!
                env.stdout.write "GAME OVER"
                gameOver := True
            else
                -- Sideway collision is ok but we now hit something while descending! Create a new piece.
                setPieceValues color
                createNextPiece
        setPieceValues color
        
        result (not collides)
        
    collision := False
    testCollision offsetX offsetY = do
        collision := False
        forall ty <- [0..4] do
            forall tx <- [0..4] do
                if (shape!(5*ty+tx) > 0) then
                    gridValue <- gameGrid.getValueAt (tx+position.x+offsetX) (ty+position.y+offsetY)
                    collision := collision || (isSolid gridValue)
        result collision

    isSolid :: TileValue -> Bool
    isSolid (EmptyTile) = False
    isSolid _ = True  

    blocksInRow := 0
    clearFilledLines = request
        setPieceValues EmptyTile
        forall row <- [1..gameGridHeight] do
                blocksInRow := 0
                forall col <- [1..gameGridWidth] do
                    lineVal = <- gameGrid.getValueAt col row
                    case lineVal of
                        EmptyTile ->
                        OutOfBoundsTile ->
                        _ -> blocksInRow := blocksInRow + 1 

                if (blocksInRow == gameGridWidth) then
                    forall col <- [1..gameGridWidth] do
                        forall r <- [0 .. (row-2)] do
                            above <- gameGrid.getValueAt col (row-r-1)
                            
                            case above of   
                                OutOfBoundsTile ->
                                    gameGrid.setValueAt col (row-r) EmptyTile
                                _ ->
                                    gameGrid.setValueAt col (row-r) above
        setPieceValues color

    nextShape := square
    createNextPiece = do
        (startX,startY, newShape) = nextShape
        shape := newShape
        position := {x=startX;y=startY}
        color := case ((<- randomizer.next) `mod` 3 +1) of
                    3 -> BlueTile
                    2 -> OrangeTile
                    _ -> RedTile

        nextShape := case ((<- randomizer.next) `mod` 3 + 1) of
                        1 -> square
                        2 -> linePiece0
                        _ -> linePiece90
    
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
    
    setColorAt x y v = request result False
    setValueAt x y v = request result False
    getValueAt x y = request result EmptyTile
    clear = request
    update = request

    backgroundColor = ({r=20;g=30;b=30})
    
    update = request
        forall (tx,ty,val,container) <- grid do
            case (val) of
                RedTile -> container.setBackgroundColor ({r=249;g=126;b=100})
                OrangeTile -> container.setBackgroundColor ({r=249;g=232;b=100})
                BlueTile -> container.setBackgroundColor ({r=74;g=106;b=154})
                EmptyTile -> container.setBackgroundColor backgroundColor
                _ -> container.setBackgroundColor ({r=255;g=255;b=255})

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

    value := OutOfBoundsTile
    getValueAt x y = request
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
                
    initGrid app = request
        tileSize = 20
        base.setSize ({width=1+(tileSize+1)*width;height=1+(tileSize+1)*height})
        ref <- base.initComp app
        
        forall row <- [1..height] do
            forall col <- [1..width] do
               tile = new mkCocoaContainer
               tile.setSize ({width=tileSize;height=tileSize})
               tile.setBackgroundColor backgroundColor
               tile.setPosition ({x=(col-1)*(tileSize+1)+1;y=(row-1)*(tileSize+1)+1})
               grid := (col,row, EmptyTile, tile) : grid
               base.addComponent tile
        result ref
        

    -- Fill out rest of interface using base container --
    base = new mkCocoaContainer
    Container {..} = base
               
    result GameGrid {initComp=initGrid;..}
    
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
