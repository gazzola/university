"""
Programa que calcule as probabilidades a priori das letras e
das probabilidades de transicao de uma letra para a outra.

Inteligencia Artificial
Universidade Federal do Pampa

------------------------------------

Marcos Treviso (121150107)
marcosvtreviso@gmail.com

Version of python: 3
For run use: python3 gerador_probabilidades.py <arquivo_texto>
"""

import sys, os, re, unicodedata

class gerador_probabilidades:

	__prob_letras = {}
	__prob_bigramas = {}
	__prob_erros = {}

	__total_letras = 0
	__total_bigramas = 0
	
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

		f = open(arquivo_texto, 'r')
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
			for y in self.__alfabeto:
				self.__prob_bigramas[x+y] = 0


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

			if bigrama not in self.__prob_bigramas:
				self.__prob_bigramas[bigrama] = 1
			else:
				self.__prob_bigramas[bigrama] += 1

			self.__total_bigramas += 1



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

		for bigrama, qtd in self.__prob_bigramas.items():
			self.__prob_bigramas[bigrama] = qtd/self.__total_bigramas

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
		
		porcent_acerto = 0.5 		# 50% de chance de acertar a teclada
		porcent_lados = 0.4 		# 40% divido entre as do lados
		porcent_resto = 0.1 		# 10% dividido entre o resto
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



	def print_probabilidades(self, probabilidades):

		count = 0
		for simb, prob in sorted(probabilidades.items()):
			print('%s: %7.4f%%  |  ' %(simb, prob*100), end="")
			count += 1

			if count % 3 == 0:
				print("")

		print("\n\n")



	'''
	Metodo de ajuda para verificar se um bigrama acentuado minusculo
	tem maior probabilidade do que um que nao eh acentuado minusculo
	'''
	def maior_acentuado(self, probabilidades):

		acent_minusculas = ['à', 'á', 'â', 'ã', 'ä', 'å', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', 'ù', 'ú', 'û', 'ü']
		for simb, prob in sorted(probabilidades.items()):
			if simb[0] in acent_minusculas or simb[1] in acent_minusculas:

				outra = self.__remove_acento(simb)
				prob_outra = self.acha_outra(probabilidades, outra)
				if prob > prob_outra:
					print('%s: %.4f%%  |  %s: %.4f%%' %(simb, prob*100, outra, prob_outra*100), end="")
					print("")

		print("\n\n")


	'''
	Metodo de ajuda para trazer a probabilidade do bigrama
	nao acentuada referente ao acentuado
	'''
	def acha_outra(self, probabilidades, outra):
		for simb, prob in sorted(probabilidades.items()):
			if simb == outra:
				return prob
		return 0



def main(arquivo_texto):
	gp = gerador_probabilidades(arquivo_texto, False, True, False) #sensitivo=False, acentos=True, digitos=False
	
	pl = gp.calc_prob_letras()
	pb = gp.calc_prob_bigramas()
	pe = gp.calc_prob_erros()

	#gp.print_probabilidades(pl)
	#gp.print_probabilidades(pb)
	#gp.print_erros(pe)
	gp.maior_acentuado(pb)

if __name__ == '__main__':
	if len(sys.argv) != 2:
		print('Use: {} <arquivo_texto>'.format(os.path.basename(sys.argv[0])))
		exit()
	main(sys.argv[1])