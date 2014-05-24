module Main( main ) where
import System.Console.GetOpt
import System.Environment(getArgs, getProgName)

import Data.List


multMatrix :: Num a => [[a]] -> [[a]] -> [[a]]
multMatrix a b = [[ sum (zipWith (*) ad bc) | bc <- (transpose b)] | ad <- a ]


main = do

	args <- getArgs
	let x = args!!0
	let n = read x :: Integer
	let mat1 = [[ i+j | i <- [1..n]] | j <- [1..n]]
	let mat2 = [[ i*j | i <- [1..n]] | j <- [1..n]]
	print(multMatrix mat1 mat2)

