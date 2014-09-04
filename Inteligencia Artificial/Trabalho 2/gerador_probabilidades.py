# coding=UTF-8
"""
Programa que calcule as probabilidades a priori das letras e
das probabilidades de transição de uma letra para a outra.

Inteligência Artificial
José Carlos Bins Filho
---
Ciência da Computação
Universidade Federal do Pampa

------------------------------------

Gustavo Alves Rodrigues, 121151605, gugax35@gmail.com
Marcos Vinícius Treviso, 121150107, marcosvtreviso@gmail.com
Thayson Rafael Karlinski, 111151990, thaysonr.karlinski@gmail.com

------------------------------------

Version of python: 3
For run use: python3 gerador_probabilidades.py <arquivo_texto>
"""

import sys, os, re, unicodedata, codecs

class gerador_probabilidades:

	__prob_letras = {}
	__prob_bigramas = {}
	__prob_erros = {}

	__total_letras = 0
	__total_bigramas = {}
	
	__alfabeto_re = None

	__alfabeto = []
	__sensitivo = False
	__acentos = False
	__digitos = False


	def __init__(self, arquivo_texto, sensitivo=False, acentos=False, digitos=False):
		
		
		self.__alfabeto_re = re.compile("\W")	# da para usar ER para verificar se eh do alfabeto
		
		self.__sensitivo = sensitivo
		self.__acentos = acentos
		self.__digitos = digitos
		self.__set_alfabeto()

		self.__inicializa_probabilidades()

		f = codecs.open(arquivo_texto, 'r', 'utf-8')
		for linha in f:
			count = 0
			tam = len(linha)

			for letra in linha:
				self.__set_qtd_letras(letra)

				if count+2 < tam:
					self.__set_qtd_bigramas(linha[count:count+2])

				count += 1

		f.close()


	def __inicializa_probabilidades(self):	#caso tenha alguma combinacao que nao apareca no texto
		for x in self.__alfabeto:
			self.__prob_letras[x] = 0
			self.__prob_bigramas[x] = {}
			for y in self.__alfabeto:
				self.__prob_bigramas[x][y] = 0


	def __set_alfabeto(self):

		# mais detalhes em:
		# http://www.utf8-chartable.de/

		inicio = ord("a")
		fim = ord("z")+1
		minusculas = [chr(i) for i in range(inicio, fim)]+['ç']

		inicio = ord("A")
		fim = ord("Z")+1
		maiusculas = [chr(i) for i in range(inicio, fim)]+['Ç']

		#inicio = ord("à")
		#fim = ord("ÿ")+1
		acent_minusculas = ['à', 'á', 'â', 'ã', 'ä', 'å', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', 'ù', 'ú', 'û', 'ü']

		#inicio = ord("À")
		#fim = ord("ß")+1
		acent_maiusculas = [x.upper() for x in acent_minusculas]

		todos_digitos = [str(i) for i in range(0, 10)]

		
		self.__alfabeto = minusculas

		if self.__sensitivo:
			self.__alfabeto += maiusculas
			if self.__acentos:
				self.__alfabeto += acent_maiusculas

		if self.__acentos:
			self.__alfabeto += acent_minusculas

		if self.__digitos:
			self.__alfabeto += todos_digitos



	def __set_qtd_letras(self, letra):
		
		if not self.__sensitivo:
			letra = letra.lower()

		if not self.__acentos:
			letra = self.__remove_acento(letra)

		if not self.__digitos and letra.isdigit():
			return None


		if letra in self.__alfabeto:

			if letra not in self.__prob_letras:
				self.__prob_letras[letra] = 1
			else:
				self.__prob_letras[letra] += 1

			self.__total_letras += 1



	def __set_qtd_bigramas(self, bigrama):
		
		if not self.__sensitivo:
			bigrama = bigrama.lower()

		if not self.__acentos:
			bigrama = self.__remove_acento(bigrama)

		if not self.__digitos and (bigrama[0].isdigit() or bigrama[1].isdigit()):
			return None


		match1 = bigrama[0] in self.__alfabeto
		match2 = bigrama[1] in self.__alfabeto

		if match1 and match2:

			if bigrama[0] not in self.__prob_bigramas:
				self.__prob_bigramas[bigrama[0]] = {}
			else:
				if bigrama[1] not in self.__prob_bigramas[bigrama[0]]:
					self.__prob_bigramas[bigrama[0]][bigrama[1]] = 1
				else:
					self.__prob_bigramas[bigrama[0]][bigrama[1]] += 1

			if bigrama[0] not in self.__total_bigramas:
				self.__total_bigramas[bigrama[0]] = 1
			else:
				self.__total_bigramas[bigrama[0]] += 1



	def __remove_acento(self, letra):

		if letra == 'ç' or letra == 'Ç':	# cedilha faz parte do teclado, entao eh obrigado a ser calculado
			return letra

		nkfd_form = unicodedata.normalize('NFKD', letra) 
		return u''.join([c for c in nkfd_form if not unicodedata.combining(c)])



	def get_alfabeto(self):
		return self.__alfabeto


	def calc_prob_letras(self):

		for letra, qtd in self.__prob_letras.items():
			self.__prob_letras[letra] = qtd/self.__total_letras

		return self.__prob_letras


	def calc_prob_bigramas(self):
	
		for b0 in self.__prob_bigramas:
			for b1 in self.__prob_bigramas[b0]:
				if b0 in self.__total_bigramas:
					self.__prob_bigramas[b0][b1] = self.__prob_bigramas[b0][b1]/self.__total_bigramas[b0]

		return self.__prob_bigramas


	def calc_prob_erros(self):

		teclado = [[], [], [], [], [], []]
		teclado[0] = list("            ")
		teclado[1] = list(" 1234567890 ")
		teclado[2] = list(" qwertyuiop ")
		teclado[3] = list(" asdfghjklç ")
		teclado[4] = list(" zxcvbnm    ")
		teclado[5] = list("            ")
		
		for i in range(1, 5):
			for j in range(1, 12):
				if teclado[i][j] != " ":
					self.__prob_erros[teclado[i][j]] = {}
					self.__porcentagens_teclado(teclado, i, j)

		return self.__prob_erros


	def __quantidade_teclado(self, teclado):
		soma = 0
		for lista in teclado:
			soma += len(lista)-lista.count(' ')
		return soma


	def __porcentagens_teclado(self, teclado, i, j):

		# no n ne
		# o  X  l
		# so s se
		
		no = teclado[i-1][j-1]
		n = teclado[i-1][j]
		ne = teclado[i-1][j+1]

		o = teclado[i][j-1]
		l = teclado[i][j+1]

		so = teclado[i+1][j-1]
		s = teclado[i+1][j]
		se = teclado[i+1][j+1]

		posicoes = [no, n, ne, o, l, so, s, se]
		posicoes = self.__posicoes_validas(posicoes)
		
		porcent_acerto = 0.6 		# 60% de chance de acertar a teclada
		porcent_lados = 0.35 		# 35% divido entre as do lados
		porcent_resto = 0.05		# 05% dividido entre o resto
		total_letras_teclado = 37	# self.__quantidade_teclado()
		total_posicoes_lados = len(posicoes)
		total_posicoes_resto = total_letras_teclado - total_posicoes_lados - 1	# total_teclado - posicoes_validas - atual


		atual = teclado[i][j]
		for lin in range(1, 5):
			for col in range(1, 12):
				letra = teclado[lin][col]

				if letra != " ":
					if letra == atual:
						self.__prob_erros[atual][letra] = porcent_acerto
					elif letra in posicoes:
						self.__prob_erros[atual][letra] = porcent_lados/total_posicoes_lados
					else:
						self.__prob_erros[atual][letra] = porcent_resto/total_posicoes_resto



	def __posicoes_validas(self, posicoes):
		novas = []
		for pos in posicoes:
			if pos != " ":
				novas.append(pos)
		return novas


	def print_erros(self, erros):
		
		for k in erros:
			soma = 0
			for j in erros[k]:
				x = erros[k][j]
				soma += x
				print("%s[%s] = %f" %(k,j, x))
			print("SOMA:%f\n\n" % soma)



	def print_prob_priori(self, prob_priori):

		count = 0
		for simb, prob in sorted(prob_priori.items()):
			print('%s: %7.4f%%  |  ' %(simb, prob*100), end="")
			count += 1

			if count % 3 == 0:
				print("")

		print("\n\n")


	def print_prob_bigramas(self, prob_bigramas):
		count = 0
		for b0 in sorted(prob_bigramas):
			soma = sum(prob_bigramas[b0].values())
			for b1 in sorted(prob_bigramas[b0]):
				simb = b0+b1
				prob = prob_bigramas[b0][b1]
				print('%s: %7.4f%%  |  ' %(simb, prob*100), end="")
				count += 1

				if count % 3 == 0:
					print("")
			print("SOMA %s: %.3f\n" %(b0, soma))

		print("\n\n")


	'''
	Metodo de ajuda para verificar se um bigrama acentuado
	tem maior probabilidade do que um que nao eh acentuado
	'''
	def maior_acentuado(self, prob_bigramas):

		acent_minusculas = ['à', 'á', 'â', 'ã', 'ä', 'å', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', 'ù', 'ú', 'û', 'ü']
		acent_maiusculas = [x.upper() for x in acent_minusculas]
		acents = acent_minusculas+acent_maiusculas
		total = sum(self.__total_bigramas.values())

		for b0 in sorted(prob_bigramas):
			for b1 in sorted(prob_bigramas[b0]):
				if b0 in acents or b1 in acents:

					prob = prob_bigramas[b0][b1]
					c0 = self.__remove_acento(b0)
					c1 = self.__remove_acento(b1)
					prob_outra = prob_bigramas[c0][c1]

					# desnormalizar para pegar em relacao a todo os bigramas
					soma1, soma2 = 1, 1
					if b0 in self.__total_bigramas:
						soma1 = self.__total_bigramas[b0]

					if c0 in self.__total_bigramas:
						soma2 = self.__total_bigramas[c0]

					prob = ((prob*soma1)/total)*100
					prob_outra = ((prob_outra*soma2)/total)*100

					if prob > prob_outra:
						print('%s: %8.4f%%  |  %s: %8.4f%%' %(b0+b1, prob, c0+c1, prob_outra), end="")
						print("")

		print("\n\n")



def main(arquivo_texto):
	gp = gerador_probabilidades(arquivo_texto, False, True, False) #sensitivo=False, acentos=True, digitos=False
	
	pl = gp.calc_prob_letras()
	pb = gp.calc_prob_bigramas()
	pe = gp.calc_prob_erros()

	#gp.print_prob_priori(pl)
	#gp.print_prob_bigramas(pb)
	#gp.print_erros(pe)
	gp.maior_acentuado(pb)


if __name__ == '__main__':
	if len(sys.argv) != 2:
		print('Use: {} <arquivo_texto>'.format(os.path.basename(sys.argv[0])))
		exit()
	main(sys.argv[1])

