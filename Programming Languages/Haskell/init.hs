doubleMe x = x + x

doubleUs x y = doubleMe x + doubleMe y

doubleSmallNumber x = if x > 100  
						then x  
						else x*2 

doubleSmallNumber' x = (if x > 100 then x else x*2) + 1

boomBangs xs = [ if x < 10 then "BOOM!" else "BANG!" | x <- xs, odd x]    

length' xs = sum [1 | _ <- xs] -- _ = nao me importo com oq 
							   --     vou extrair da lista  

removeNonUppercase st = [ c | c <- st, c `elem` ['A'..'Z']] 


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


	putStr("\n-----------------------------------\n\n")
	

	putStrLn("Criando Funcoes:")
	print(doubleMe 2)
	print(doubleUs 4 5)
	print(doubleSmallNumber 40)
	print(doubleSmallNumber 110)
	print(doubleSmallNumber' 40)


	putStr("\n")


	putStrLn("Listas:")
	let lostNumbers = [4,8,15,16,23,48]
	print(lostNumbers)

	print([1,2,3,4] ++ [6,7,8,9])
	print("hello" ++ " " ++ "world!")

	print('A':" SMALL CAT") -- O(1)
	print(0:[1,2,3,4,5]) -- O(1)


	putStr("\n")

	print("Marcos Treviso" !! 7)
	print([9.4,33.2,96.2,11.2,23.25] !! 1)


	putStr("\n")

	let b = [[1,2,3,4],[5,3,3,3],[1,2,2,3,4],[1,2,3]]
	print(b ++ [[1,1,1,1]])
	print([6,6,6]:b)
	print(b !! 2)


	putStr("\n")

	-- ordem lexicografica: pos por pos
	print([3,2,1] > [2,1,0])
	print([3,2,1] > [2,10,100])
	print([3,4,2] == [3,4,2]) 


	putStr("\n")


	print([5,4..1])

	putStr("head: ")
	print(head [5,4,3,2,1])
	
	putStr("tail: ")
	print(tail [5,4,3,2,1])

	putStr("last: ")
	print(last [5,4,3,2,1])

	putStr("init: ")
	print(init [5,4,3,2,1])

	putStr("length: ")
	print(length [5,4,3,2,1])

	putStr("null: ")
	print(null [5,4,3,2,1])

	putStr("reverse: ")
	print(reverse [5,4,3,2,1])

	putStr("take 3: ")
	print(take 3 [5,4,3,2,1])
	putStr("take 1: ")
	print(take 1 [5,4,3,2,1])
	putStr("take 0: ")
	print(take 0 [5,4,3,2,1])

	putStr("drop 3: ")
	print(drop 3 [5,4,3,2,1])
	putStr("drop 1: ")
	print(drop 1 [5,4,3,2,1])
	putStr("drop 100: ")
	print(drop 100 [5,4,3,2,1])

	putStr("minimum: ")
	print(minimum [5,4,3,2,1])

	putStr("maximum: ")
	print(maximum [5,4,3,2,1])

	putStr("sum: ")
	print(sum [5,4,3,2,1])

	putStr("product: ")
	print(product [5,4,3,2,1])

	putStr("elem 4: ")
	print(4 `elem` [5,4,3,2,1])
	putStr("elem 10: ")
	print(10 `elem` [5,4,3,2,1])



	putStr("\n")


	putStrLn("Texas Ranges:")
	print([1..20])
	print(['a'..'z'])
	print(['A'..'Z'])
	print([2,4..20])
	print([3,6..20])
	print(take 10 (cycle [1,2,3]))
	print(take 12 (cycle "MTC"))
	print(take 10 (repeat 5))


	putStr("\n")


	putStrLn("Compreensao de lista:")
	print([x*2 | x <- [1..10]])
	print([x*2 | x <- [1..10], x*2 >= 12])
	print([ x | x <- [50..100], x `mod` 7 == 0])
	print(boomBangs [7..13])
	print([ x | x <- [10..20], x /= 13, x /= 15, x /= 19])
	print([ x*y | x <- [2,5,10], y <- [8,10,11]]) --cool xD
	print(removeNonUppercase("IdontLIKEFROGS"))
	let xxs = [[1..6], [1..6], [1..6]]
	print([[ x | x <- xs, even x ] | xs <- xxs] )


	putStr("\n")


	putStrLn("Tuplas:")
	print(fst (8,11))
	print(snd (8,11))
	print(zip [1 .. 5] ['a'..'z'])

	let x = [1..10]
	let triangles = [(a,b,c) | c<-x, b<-x, a<-x]
	let rightTriangles = [(a,b,c) | c<-[1..10], b<-[1..c], a<-[1..b], a^2 + b^2 == c^2]
	print(rightTriangles)
	let rightTriangles' = [(a,b,c) | c<-[1..10], b<-[1..c], a<-[1..b], a^2 + b^2 == c^2, a+b+c==24]
	print(rightTriangles')
