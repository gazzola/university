import numpy

class ListaDeMusicas:

	__qtdMusicas = 0
	__tamMaximo = 0
	__musicas = []
	__matriz = [[]]

	__pesos = []
	__valores = []


	def __init__(self, arquivo):
		f = open(arquivo)
		tam_max, num_musicas = f.readline().split()

		self.setTamMaximo(tam_max)
		self.setQtdMusicas(num_musicas)
		
		self.setMusicas(f)
		self.setMatriz(self.getQtdMusicas()+1, self.getTamMaximo()+1)
	

	def setQtdMusicas(self, value):
		self.__qtdMusicas = int(value)


	def setTamMaximo(self, value):
		self.__tamMaximo = int(value)


	def getQtdMusicas(self):
		return self.__qtdMusicas

	def getTamMaximo(self):
		return self.__tamMaximo

	def getPesos(self):
		return self.__pesos

	def getValores(self):
		return self.__valores


	def setMatriz(self, linhas, colunas):
		self.__matriz = numpy.zeros((linhas,colunas), dtype=int)
		#self.__matriz = [[0 for y in range(colunas)] for x in range(linhas)]


	def setMusicas(self, arquivo):
		self.__pesos.append(0)
		self.__valores.append(0)

		for linha in arquivo:
		    i, tam, nota = linha.split()
		    self.__musicas.append((int(i), int(tam), int(nota), float(nota)/int(tam)))
		    
		    self.__pesos.append(int(tam))
		    self.__valores.append(int(nota))


	def getMusicas(self):
		return sorted(self.__musicas, key = lambda x : x[1])


	def exibeMusicas(self, musicas):
		print("ID-TAM-FAV")
		for i in musicas:
			print(i)


	def mochilaBinaria(self, qtdElementos, pesos, valores, tamMochila):

		for x in range(tamMochila+1):
			self.__matriz[0][x] = 0

			for i in range(1, qtdElementos+1):
				a = self.__matriz[i-1][x]

				vi = self.__valores[i]
				pi = self.__pesos[i]

				if(x-pi >= 0):
					b = vi + self.__matriz[i-1][x-pi]

					if(a < b):
						a = b

				self.__matriz[i][x] = a


		return int(self.__matriz[qtdElementos][tamMochila])



	def selecionaMusicas(self, musicas):

		razao = sorted(musicas, key = lambda x : x[3], reverse=True)

		somatam, somafav = 0, 0
		for i, tam, fav, more in razao:
			if(somatam+tam <= self.__tamMaximo):
				somatam += tam
				somafav += fav

		return somafav
