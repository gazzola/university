# coding=UTF-8
"""
Fazer um corretor ortográfico usando o Algoritmo de Viterbi.

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
For run use: python3 corretor_ortografico.py <arquivo_texto> <arquivo_palavras>
"""

import sys, os, unicodedata, codecs
from gerador_probabilidades import gerador_probabilidades


class corretor_ortografico:

	modelo = []

	alfabeto = []
	
	prob_letras = {}
	prob_bigramas = {}
	prob_erros = {}

	palavra_correta = ""
	palavra_errada = ""
	palavra_provavel = ""

	prob_errada = 0
	prob_correta = 0
	prob_provavel = 0

	prob_final_evidencia = 0

	transicoes = 0
	

	def __init__(self, palavra_errada, palavra_correta):
		self.palavra_errada = palavra_errada
		self.palavra_correta = palavra_correta




	# setters

	def set_probabilidade_priori(self, prob):
		self.prob_letras = prob

	def set_probabilidade_bigramas(self, prob):
		self.prob_bigramas = prob

	def set_probabilidade_evidencias(self, prob):
		self.prob_erros = prob

	def set_alfabeto(self, alfabeto):
		self.alfabeto = alfabeto




	# getters

	'''
	Probabilidade de estar no estado `x1`: P(x1)
	@return: float
	'''
	def get_prob_priori(self, x1):
		return self.prob_letras[x1]
	

	'''
	Probabilidade do estado `x2` dado que estava no estado `x1`: P(x2|x1)
	@return: float
	'''
	def get_prob_posteriori(self, x2, x1):

		if x1 in self.prob_bigramas:
			if x2 in self.prob_bigramas[x1]:
				if self.prob_bigramas[x1][x2] > 0:
					return self.prob_bigramas[x1][x2]

		return 0.000001	# se nao foi calculada ou for 0, entao retornamos uma probabilidade muito baixa


	'''
	Remove os acentos e a sensibilidade do caso para poder capturar os erros
	@return: char
	'''
	def __remove_acento(self, letra):

		letra = letra.lower()	# tira o case sensitive

		if letra == 'ç':		# cedilha faz parte do teclado, entao eh obrigado a ser calculado
			return letra

		nkfd_form = unicodedata.normalize('NFKD', letra) 
		return u''.join([c for c in nkfd_form if not unicodedata.combining(c)])


	'''
	Probabilidade da evidencia `e` dado que esta no estado `x`: P(e|x)
	@return: float
	'''
	def get_prob_erro(self, e, x): 

		e = self.__remove_acento(e)
		x = self.__remove_acento(x)
		return self.prob_erros[x][e]




	# algoritmo

	'''
	Cria nova lista para armazenar os resultados finais para cada `x2`
	A lista eh composto por: [valor final, ponteiro para seu predecessor]
	@return: list
	'''
	def __novas_finais(self):
		finais = {}
		for letra in self.alfabeto:
			finais[letra] = [-1, '']	# valor, antecessor
		return finais


	'''
	Normaliza os valores dos resultados finais
	'''
	def __normalizar(self, finais):
		soma = 0
		for x in finais:
			soma += finais[x][0]

		for x in finais:
			finais[x][0] /= soma

	
	'''
	Seta para o modelo o resultado final relativo a ele
	'''
	def __selecionar_finais(self, dia, finais):	#final para cada estado x2 (x1->x2)
		for letra in self.alfabeto:
			final = ("final", letra)
			self.modelo[dia][final] = finais[letra]



	'''
	Identifica a melhor sequencia no modelo gerado
	@return: str
	'''
	def __achar_melhor_caminho(self):

		melhor_caminho = ""
		tam_pal = len(self.palavra_errada)
		dia_final = tam_pal-1

		# acha a letra com maior probabilidade no ultimo dia
		melhor_letra = self.alfabeto[0]
		for letra in self.alfabeto:

			tupla_l = ("final", letra)
			tupla_m = ("final", melhor_letra)
			
			if self.modelo[dia_final][tupla_l] > self.modelo[dia_final][tupla_m]:
				melhor_letra = letra


		# palavra mais provavel termina com a melhor letra
		melhor_caminho = melhor_letra 

		# adiciona uma posicao de erro para cada letra da palavra errada
		self.transicoes = [0 for i in range(tam_pal)]


		# percorre o modelo atraves dos ponteiros antecessores e identifica os erros
		tupla_f = ("final", melhor_letra)
		for dia in range(dia_final, 0, -1):

			antecessor = self.modelo[dia][tupla_f][1]
			resultado = self.modelo[dia][tupla_f][0]

			if dia < len(self.palavra_correta):
				self.transicoes[dia] = resultado

			melhor_caminho = antecessor+melhor_caminho
			tupla_f = ("final", antecessor)
			
		self.transicoes[0] = self.modelo[0][tupla_f][0]

		return melhor_caminho



	def __novos_somas(self):
		somas = {}
		for k in self.alfabeto:
			somas[k] = 0
		return somas

	def __normalizar_somas(self, somas):
		soma = sum(somas.values())
		for k in self.alfabeto:
			somas[k] /= soma

	def __em_porcentagem(self, somas, palavra):
		count, soma = 0, 0
		for dicio in somas:
			e = palavra[count]
			soma += dicio[e]
			count += 1
		return soma/len(palavra)*100


	'''
	Implementacao do Algoritmo de Viterbi
	'''
	def viterbi(self, normalizar=False):

		palavra = self.palavra_errada
		tam_pal = len(palavra)
		todos_filtros = []
		todas_somas = []
		
		for dia in range(tam_pal):

			tabela = {}
			evidencia = palavra[dia]

			finais = self.__novas_finais()
			somas = self.__novos_somas()

			for x1 in self.alfabeto:
				for x2 in self.alfabeto:

					linha = (x1, x2)
					final = ("final", x1)

					if dia == 0:	# se for o primeiro dia, pegamos a probabilidade a priori
						primeiro = self.get_prob_priori(x1) 
					else:
						primeiro = self.modelo[dia-1][final][0]

					segundo = self.get_prob_posteriori(x2, x1)
					terceiro = self.get_prob_erro(evidencia, x2)
					result = primeiro*segundo*terceiro
					tabela[linha] = [evidencia, primeiro, segundo, terceiro, result]


					# resultados finais
					if result > finais[x2][0]:
						finais[x2] = [result, x1]


					# soma das probabilidades (filtragem)
					if dia == 0:
						somas[x2] += primeiro*segundo*terceiro
					else:
						somas[x2] += todas_somas[dia-1][x1]*segundo*terceiro
			 

			# inclui a nova tabela no modelo
			self.modelo.append(tabela)
			
			# normaliza e seleciona as finais
			if(normalizar):
				self.__normalizar(finais)
			self.__selecionar_finais(dia, finais)

			# normaliza as somas
			self.__normalizar_somas(somas)
			todas_somas.append(somas)


		# coloca em porcentagem a probabilidade de estar no estado final dada toda a evidencia P(Xt|g1,..,gt)
		self.prob_final_evidencia = self.__em_porcentagem(todas_somas, palavra)
		
		# por fim, calculamos a palavra mais provavel de acordo com o algoritmo
		self.palavra_provavel = self.__achar_melhor_caminho()




	# printers

	'''
	Exibe na tela a tabela completa de todos os dias com seus respectivos dados
	calculados pelo Algoritmo de Viterbi
	'''
	def print_modelo(self):

		tam_pal = len(self.palavra_errada)

		for dia in range(tam_pal):

			print("Dia %d:" % (dia+1))
			print(78*"-")

			tupla = (dia, dia+1, dia, dia, dia+1, dia, dia+1, dia+1)
			print("|  x%d -> x%d  |  e%d  |  P(x%d)  |  P(x%d|x%d)  |  P(e%d|x%d)  |  result  |  final   |" % tupla)
			print(78*"-")

			for x1 in self.alfabeto:
				for x2 in self.alfabeto:

					linha = (x1, x2)

					e = self.modelo[dia][linha][0]
					primeiro = self.modelo[dia][linha][1]
					segundo = self.modelo[dia][linha][2]
					terceiro = self.modelo[dia][linha][3]
					result = self.modelo[dia][linha][4]

					final = ("final", x2)
					final = self.modelo[dia][final][0]

					tupla = (x1, x2, e, primeiro, segundo, terceiro, result, final)
					print("|   %s ->  %s  |   %s  |  %5.3f  |  %8.3f  |  %8.3f  |  %6.4f  |  %5.4f  |" % tupla)

			print("\n\n")


	
	'''
	Exibe na tela a palavra mais provavel, a errada e a correta,
	juntamente com estatisticas de erro e acerto do programa
	'''
	def print_resultado(self):
		
		print("")
		print("MAIS PROVÁVEL: %s  |  ERRADA: %s  |  CORRETA: %s" %(self.palavra_provavel, self.palavra_errada, self.palavra_correta))
		print(90*"-")

		if self.palavra_provavel == self.palavra_correta:
			print("Algoritmo descobriu que deve-se trocar `%s` por `%s`!" % (self.palavra_errada, self.palavra_correta))
		
		prob_leve = self.__levenshtein(self.palavra_provavel, self.palavra_errada)*100
		prob_dice = self.__dice_coefficient(self.palavra_provavel, self.palavra_errada)*100
		print("Levenshtein: Similaridade da errada `%s` em relação a mais provável `%s`: %.2f%%" % (self.palavra_errada, self.palavra_provavel, prob_leve))
		print("Dice's     : Similaridade da errada `%s` em relação a mais provável `%s`: %.2f%%" % (self.palavra_errada, self.palavra_provavel, prob_dice))

		prob_leve = self.__levenshtein(self.palavra_provavel, self.palavra_correta)*100
		prob_dice = self.__dice_coefficient(self.palavra_provavel, self.palavra_correta)*100
		print("Levenshtein: Similaridade da mais provável `%s` em relação a correta `%s`: %.2f%%" % (self.palavra_provavel, self.palavra_correta, prob_leve))
		print("Dice's     : Similaridade da mais provável `%s` em relação a correta `%s`: %.2f%%" % (self.palavra_provavel, self.palavra_correta, prob_dice))
		
		print("")

		print("Prob. de estar no estado final dada toda a evidência: %.2f%%" % self.prob_final_evidencia)

		print("")

		print("Prob. cada transição do algoritmo de viterbi para a palavra mais provável em relação a correta:")

		
		tam_correta = len(self.palavra_correta)
		tam_provavel = len(self.palavra_provavel)
		tam_pal = max(tam_correta, tam_provavel)
		count_erros = 0

		for i in range(tam_pal):
			
			x1, x2, v, a = ' ', ' ', ' ', ''
			if i < tam_provavel:
				x1 = self.palavra_provavel[i]
				v = self.transicoes[i]*100

			if i < tam_correta:
				x2 = self.palavra_correta[i]

			if x1 != x2 and x2 != ' ':
				count_erros += 1
				a = '*'

			print("%s-%s: %.2f%% %s" %(x1, x2, v, a))

		print("Total: %d erro(s)" % count_erros)

		print("\n\n")



	'''
	Metodo para medir a similaridade entre duas strings
	@return: float
	'''
	# retirado de: 
	# http://rosettacode.org/wiki/Levenshtein_distance#Python
	def __levenshtein(self, s1, s2):
		
		if len(s1) > len(s2):
			s1,s2 = s2,s1
		
		distances = range(len(s1) + 1)
		for index2,char2 in enumerate(s2):
			
			newDistances = [index2+1]
			for index1,char1 in enumerate(s1):
				if char1 == char2:
					newDistances.append(distances[index1])
				else:
					newDistances.append(1 + min((distances[index1], distances[index1+1], newDistances[-1])))
			
			distances = newDistances

		return 1-distances[-1]/len(s2)	# linha alterada para ja dar a porcentagem


	'''
	Metodo para medir a similaridade entre duas strings
	@return: float
	'''
	# retirado de: 
	# http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Dice%27s_coefficient#Python
	def __dice_coefficient(self, a, b):
		a_bigrams = set(a)
		b_bigrams = set(b)
		overlap = len(a_bigrams & b_bigrams)
		return overlap * 2.0/(len(a_bigrams) + len(b_bigrams))





# helper functions

'''
Pega as palavras do arquivo e coloca numa lista,
a lista eh composta por: [palavra errada, palavra correta]
@return: list
'''
def get_palavras(arquivo_palavras):
	palavras = []
	f = codecs.open(arquivo_palavras, 'r', 'utf-8')
	for linha in f:
		linha = linha.strip().split(" ")
		palavras.append(linha)
	f.close()
	return palavras


'''
Verifica se a palavra faz parte do alfabeto,
ou seja, se cada caracter faz parte do alfabeto
@return: boolean
'''
def palavra_ok(palavra, alfabeto):
	for char in palavra:
		if char not in alfabeto:
			return False
	return True



def main(arquivo_texto, arquivo_palavras):

	# gera as probabilidades de acordo com o arquivo de texto e as regras relativas ao alfabeto
	gp = gerador_probabilidades(arquivo_texto, True, True, True)
	pl = gp.calc_prob_letras()
	pb = gp.calc_prob_bigramas()
	pe = gp.calc_prob_erros()
	alf = gp.get_alfabeto()

	# joga as palavras para uma lista ao inves de executar o algoritmo na iteracao com o arquivo aberto
	palavras = get_palavras(arquivo_palavras)

	
	# 	exemplo do livro, atencao para valores normalizados:
	pl = {'v':0.5, 'f':0.5}
	pb = {'v':{'v':0.7, 'f':0.3}, 'f':{'v':0.3, 'f':0.7}}
	pe = {'v':{'v':0.9, 'f':0.1}, 'f':{'v':0.2, 'f':0.8}}
	alf = ['v', 'f']
	palavras = [['vvfvv', 'vvfvv']]

	#	pl = {'v':0.1, 'f':0.9}
	#	pb = {'v':{'v':0.8, 'f':0.2}, 'f':{'v':0.1, 'f':0.9}}
	#	pe = {'v':{'v':0.7, 'f':0.3}, 'f':{'v':0.2, 'f':0.8}}
	#	alf = ['v', 'f']
	#	palavras = [['vvfv', 'vvfv']]


	for palavra_errada, palavra_correta in palavras:

		# verifica se as palavras de entrada fazem parte do alfabeto utilizado
		if(not palavra_ok(palavra_errada, alf)):
			
			print("Palavra errada `%s` não está no alfabeto" % palavra_errada)
			continue

		if(not palavra_ok(palavra_correta, alf)):
			
			print("Palavra correta `%s` não está no alfabeto" % palavra_correta)
			continue
			
		# se tiver tudo ok, inicializa o corretor ortografico
		co = corretor_ortografico(palavra_errada, palavra_correta)
		
		# seta as probabilidades necessarias e o alfabeto utilizado
		co.set_probabilidade_priori(pl)
		co.set_probabilidade_bigramas(pb)
		co.set_probabilidade_evidencias(pe)
		co.set_alfabeto(alf)

		# aplica o algoritmo de viterbi para a correcao e mostra os resultados
		co.viterbi(True) # normalizar=True
		co.print_resultado()
		co.print_modelo()



if __name__ == '__main__':
	if len(sys.argv) != 3:
		print('Use: {} <arquivo_texto> <arquivo_palavras>'.format(os.path.basename(sys.argv[0])))
		exit()
	main(sys.argv[1], sys.argv[2])

