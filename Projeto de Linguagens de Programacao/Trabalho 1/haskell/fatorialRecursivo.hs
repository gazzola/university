module Main( main ) where
import System.Console.GetOpt
import System.Environment(getArgs, getProgName)


factorialRec :: (Integral n) => n -> n 
factorialRec n = if n <= 1 
				 then 1 
				 else n * factorialRec (n-1)

main = do

	args <- getArgs
	let x = args!!0
	let n = read x :: Integer
	print(factorialRec n)