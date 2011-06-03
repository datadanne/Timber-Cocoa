module TEMP where
    
import POSIX

root w = class
    env = new posix w

    handleMouseEvent :: a -> Maybe (a -> Request Bool) -> Cmd () Bool
    handleMouseEvent m (Just meh) = do
        result (<- meh m)

    handleMouseEvent m Nothing = do
        result (False) 


    result action    
				env.stdout.write "fail"