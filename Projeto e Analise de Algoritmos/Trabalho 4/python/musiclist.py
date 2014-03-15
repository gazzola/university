class MusicList:

	__ammount = 0
	__maxSize = 0
	__musics = []

	__matrix = None
	__weight = [0]
	__rank = [0]


	def __init__(self, filename, divisor=1):
		f = open(filename)
		maxSize, ammount = f.readline().split()

		if(int(maxSize) < divisor):
			divisor = 1

		maxSize = self.divide(float(maxSize), divisor)

		self.setMaxSize(maxSize)
		self.setAmmount(ammount)
		
		self.setMusics(f, divisor)
		#self.setMatriz(self.getAmmount()+1, self.getMaxSize()+1) #madness
		self.setMatriz(2, self.getMaxSize()+1)




	def divide(self, value, divisor):
		if(value >= divisor):
			return int(value/divisor)
		return value


	def setAmmount(self, value):
		self.__ammount = int(value)

	def setMaxSize(self, value):
		self.__maxSize = int(value)

	def setMatriz(self, lines, columns):
		self.__matrix = [[0 for y in range(columns)] for x in range(lines)]

	def setMusics(self, filename, divisor):
		for line in filename:
		    i, size, rank = line.split()
		    size = self.divide(float(size), divisor)
		    self.__musics.append((int(i), int(size), int(rank), float(rank)/int(size)))
		    self.__weight.append(int(size))
		    self.__rank.append(int(rank))



	def getAmmount(self):
		return self.__ammount

	def getMaxSize(self):
		return self.__maxSize

	def getWeight(self):
		return self.__weight

	def getRank(self):
		return self.__rank

	def getMusics(self):
		return sorted(self.__musics, key = lambda x : x[1])



	def showMusics(self, musics):
		print("ID-TAM-FAV")
		for i in musics:
			print(i)



	def copyLineMatrix(self, maxSize):
		for i in range (maxSize+1):
			self.__matrix[0][i] = self.__matrix[1][i]


	def binaryKnapsackOptimized(self, ammount, weight, rank, maxSize):
		for x in range(ammount+1):
			for i in range(maxSize+1):
				a = self.__matrix[0][i]

				vi = rank[x]
				pi = weight[x]

				if(i-pi >= 0):
					b = vi + self.__matrix[0][i-pi]
					if(a < b):
						a = b

				self.__matrix[1][i] = a

			self.copyLineMatrix(maxSize)

		return self.__matrix[1][maxSize]


	def binaryKnapsack(self, ammount, weight, rank, maxSize):
		for x in range(maxSize+1):
			self.__matrix[0][x] = 0

			for i in range(1, ammount+1):
				a = self.__matrix[i-1][x]

				vi = self.__rank[i]
				pi = self.__weight[i]

				if(x-pi >= 0):
					b = vi + self.__matrix[i-1][x-pi]

					if(a < b):
						a = b

				self.__matrix[i][x] = a

		return self.__matrix[ammount][maxSize]



	def selectMusics(self, musics):
		ratio = sorted(musics, key = lambda x : x[3], reverse=True)

		sumsize, sumrank = 0, 0
		for i, size, fav, more in ratio:
			if(sumsize+size <= self.__maxSize):
				sumsize += size
				sumrank += fav

		return sumrank
