class ListaDeMusicas:

	__qtdMusicas = 0
	__tamMaximo = 0
	__musicas = []


	def __init__(self, arquivo):
		f = open(arquivo)
		tam_max, num_musicas = f.readline().split()
		self.setQtdMusicas(num_musicas)
		self.setTamMaximo(tam_max)
		self.setMusicas(f)
	

	def setQtdMusicas(self, value):
		self.__qtdMusicas = int(value)


	def setTamMaximo(self, value):
		self.__tamMaximo = int(value)


	def setMusicas(self, arquivo):
		for linha in arquivo:
		    i, tam, nota = linha.split()
		    self.__musicas.append((int(i), int(tam), int(nota), float(nota)/int(tam)))


	def getMusicas(self):
		return sorted(self.__musicas, key = lambda x : x[1])


	def exibeMusicas(self, musicas):
		print("ID-TAM-FAV")
		for i in musicas:
			print(i)


	def selecionaMusicas(self, musicas):
		
		razao = sorted(musicas, key = lambda x : x[3], reverse=True)

		somatam, somafav = 0, 0
		for i, tam, fav, more in razao:
			if(somatam+tam <= self.__tamMaximo):
				somatam += tam
				somafav += fav

		return somafav
