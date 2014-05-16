main = do

	putStrLn("Operacoes Aritmeticas:")
	print(2+5)
	print(4*8)
	print(18-15)
	print(5/2) 


	putStr("\n")


	putStrLn("Prioridade por Parenteses:")
	print( (50*100)-499 )
	print( 50*100-499 )
	print( 50*(100-4999) )
	-- print( 4*-1 ) #error
	print( 4*(-1) )


	putStr("\n")


	putStrLn("Algebra Booleana:")
	print(True && False)
	print(True && True)
	print(False || True)
	print(not False)
	print(not (True && True))


	putStr("\n")


	putStrLn("Funcoes:")
	print(succ 8)
	print(min 9 10)
	print(max 3.4 3.2)
	print(max 100 101)
	print((succ 9) + (max 5 4) + 1)




