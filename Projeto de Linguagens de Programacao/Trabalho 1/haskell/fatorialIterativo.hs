module Main( main ) where
import System.Console.GetOpt
import System.Environment(getArgs, getProgName)


factorialIter :: (Integral n) => n -> n 
factorialIter n = product [1..n]


main = do

	args <- getArgs
	let x = args!!0
	let n = read x :: Integer
	print(factorialIter n)
