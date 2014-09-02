"""
Fazer um corretor ortografico usando o Algoritmo de Viterbi.

Inteligencia Artificial
Universidade Federal do Pampa

------------------------------------

Gustavo Alves Rodrigues, 121151605, gugax35@gmail.com
Marcos Vinícius Treviso, 121150107, marcosvtreviso@gmail.com
Thayson Rafael Karlinski, 111151990, thaysonr.karlinski@gmail.com

------------------------------------

Version of python: 3
For run use: python3 corretor_ortografico.py <arquivo_texto>
"""

import sys, os, unicodedata
from gerador_probabilidades import gerador_probabilidades


class corretor_ortografico:

	modelo = []

	alfabeto = []
	
	prob_letras = {}
	prob_bigramas = {}
	prob_erros = {}

	palavra_correta = ""
	palavra_errada = ""
	

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



	def criar_modelo(self):

		palavra = " "+self.palavra_errada	# so para ter a probabilidade do dia 0
		for evidencia in palavra:
			tabela = {}

			for x1 in self.alfabeto:

				prob = self.prob_letras[x1]	# primeira prob eh a priori
				for x2 in self.alfabeto:
					linha = (x1, x2)
					tabela[linha] = [evidencia, 0, 0, 0, prob]

				final = ("final", x1)
				tabela[final] = prob

			self.modelo.append(tabela)

	

	def get_prob_dada(self, x2, x1):	# estado `x2` dado que estava no estado `x1`

		dado = x1+x2
		if dado in self.prob_bigramas:
			if self.prob_bigramas[dado] == 0: # se a probabilidade de x2|x1 for 0, entao retornamos uma probabilidade muito baixa
				return 0.000001
			return self.prob_bigramas[dado]

		return 0.000001	# se nao foi calculada eh como fosse 0, pois nao apareceu nenhuma vez no texto



	def __remove_acento(self, letra):

		letra = letra.lower()	# tira o case sensitive

		if letra == 'ç':		# cedilha faz parte do teclado, entao eh obrigado a ser calculado
			return letra

		nkfd_form = unicodedata.normalize('NFKD', letra) 
		return u''.join([c for c in nkfd_form if not unicodedata.combining(c)])


	def get_prob_erro(self, e, x):	# evidencia `e` dado que esta no estado `x`

		e = self.__remove_acento(e)
		x = self.__remove_acento(x)
		return self.prob_erros[x][e]



	def __novas_finais(self):
		finais = {}
		for letra in self.alfabeto:
			finais[letra] = 0
		return finais


	def __normalizar(self, lista):
		soma = sum(lista.values())
		for x in lista:
			lista[x] /= soma
		return lista

	
	def __selecionar_finais(self, dia, finais):
		for letra in self.alfabeto:
			final = ("final", letra)
			self.modelo[dia][final] = finais[letra]



	def viterbi(self):

		palavra = self.palavra_errada
		tam_pal = len(palavra)+1

		for dia in range(1, tam_pal):

			evidencia = palavra[dia-1]
			finais = self.__novas_finais()

			for x1 in self.alfabeto:
				for x2 in self.alfabeto:

					linha = (x1, x2)
					final = ("final", x1)

					primeiro = self.modelo[dia-1][final]
					segundo = self.get_prob_dada(x2, x1)
					terceiro = self.get_prob_erro(evidencia, x2)
					result = primeiro*segundo*terceiro
					self.modelo[dia][linha] = [evidencia, primeiro, segundo, terceiro, result]

					finais[x2] = max(result, finais[x2])	# maior entre todos os x2

			
			finais = self.__normalizar(finais)
			self.__selecionar_finais(dia, finais)




	def print_modelo(self):

		tam_pal = len(self.palavra_errada)+1

		for dia in range(1, tam_pal):

			print("Dia %d:" % (dia))
			print(78*"-")

			tupla = (dia, dia+1, dia, dia, dia+1, dia, dia+1, dia+1)
			print("|  x%d -> x%d  |  e%d  |  P(x%d)  |  P(x%d|x%d)  |  P(e%d|x%d)  |  result  |  final  |" % tupla)
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
					final = self.modelo[dia][final]

					tupla = (x1, x2, e, primeiro, segundo, terceiro, result, final)
					print("|   %s ->  %s  |   %s  |  %5.3f  |  %8.3f  |  %8.3f  |  %6.3f  |  %5.3f  |" % tupla)

			print("\n\n")



	def __achar_erro(self):	# acha o melhor caminho

		nova_palavra = list(self.palavra_errada)
		tam_pal = len(self.palavra_errada)+1
		tam_alf = len(self.alfabeto)
		
		melhor = self.alfabeto[0]
		for dia in range(1, tam_pal):
			for i in range(tam_alf):

				tupla = ("final", self.alfabeto[i])
				tupla_m = ("final", melhor)
				
				if self.modelo[dia][tupla] > self.modelo[dia][tupla_m]:
					melhor = self.alfabeto[i]
			
			nova_palavra[dia-1] = melhor

		return ''.join(nova_palavra)
		

	
	def print_resultado(self):
		
		nova_palavra = self.__achar_erro()

		print("")
		print("ERRADA: %s  |  CORRETA: %s  |  MAIS PROVÁVEL: %s" %(self.palavra_errada, self.palavra_correta, nova_palavra))
		print(90*"-")

		if nova_palavra == self.palavra_correta:
			print("\033[92mAlgoritmo descobriu que deve-se trocar `%s` por `%s`!\033[0m" % (self.palavra_errada, self.palavra_correta))
		
		prob_leve = self.__levenshtein(nova_palavra, self.palavra_errada)*100
		prob_dice = self.__dice_coefficient(nova_palavra, self.palavra_errada)*100
		print("Levenshtein: Prob. da errada `%s` em relação a mais provável `%s`! [%.2f%%]" % (self.palavra_errada, nova_palavra, prob_leve))
		print("Dice's     : Prob. da errada `%s` em relação a mais provável `%s`! [%.2f%%]" % (self.palavra_errada, nova_palavra, prob_dice))

		prob_leve = self.__levenshtein(nova_palavra, self.palavra_correta)*100
		prob_dice = self.__dice_coefficient(nova_palavra, self.palavra_correta)*100
		print("Levenshtein: Prob. da mais provável `%s` em relação a correta `%s`: [%.2f%%]" % (nova_palavra, self.palavra_correta, prob_leve))
		print("Dice's     : Prob. da mais provável `%s` em relação a correta `%s`: [%.2f%%]" % (nova_palavra, self.palavra_correta, prob_dice))
		
		print("")



	# retirado de: http://rosettacode.org/wiki/Levenshtein_distance#Python
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

		return 1-distances[-1]/len(s2)	# linha alterada para ja dar a probabilidade


	# retirado de: http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Dice%27s_coefficient#Python
	def __dice_coefficient(self, a, b):
		a_bigrams = set(a)
		b_bigrams = set(b)
		overlap = len(a_bigrams & b_bigrams)
		return overlap * 2.0/(len(a_bigrams) + len(b_bigrams))







'''
pega as palavras do arquivo e coloca numa lista
a lista eh composta por: [palavra_errada, palavra_correta]
@return: list
'''
def get_palavras(arquivo_palavras):
	palavras = []
	f = open(arquivo_palavras, 'r')
	for linha in f:
		linha = linha.strip().split(" ")
		palavras.append(linha)
	f.close()
	return palavras


'''
verifica se a palavra faz parte do alfabeto
ou seja, se cada caracter faz parte do alfabeto
@return: boolean
'''
def palavra_ok(palavra, alfabeto):
	for char in palavra:
		if char not in alfabeto:
			return False
	return True



def main(arquivo_texto, arquivo_palavras):

	# gera as probabilidades de acordo com o arquivo de texto e as regras relativas
	gp = gerador_probabilidades(arquivo_texto, True, True, True)
	pl = gp.calc_prob_letras()
	pb = gp.calc_prob_bigramas()
	pe = gp.calc_prob_erros()
	alf = gp.get_alfabeto()

	palavras = get_palavras(arquivo_palavras)

	# 	como no livro:
	#	pl = {'v':0.5, 'f':0.5}
	#	pb = {'vv':0.7, 'vf':0.3, 'fv':0.3, 'ff':0.7}
	#	pe = {'v':{'v':0.9, 'f':0.1}, 'f':{'v':0.2, 'f':0.8}}
	#	alf = ['c', 'a', 'z', 's']
	#	palavras = [['caza', 'casa']]

	for palavra_errada, palavra_correta in palavras:

		if(not palavra_ok(palavra_errada, alf)):
			
			print("Palavra errada `%s` nao esta no alfabeto" % palavra_errada)
			continue

		if(not palavra_ok(palavra_correta, alf)):
			
			print("Palavra correta `%s` nao esta no alfabeto" % palavra_correta)
			continue
			

		# se tiver tudo ok, inicializa o corretor ortografico
		co = corretor_ortografico(palavra_errada, palavra_correta)
		
		# seta as probabilidades necessarias e o alfabeto utilizado
		co.set_probabilidade_priori(pl)
		co.set_probabilidade_bigramas(pb)
		co.set_probabilidade_evidencias(pe)
		co.set_alfabeto(alf)

		# cria o modelo
		co.criar_modelo()

		# aplica o algoritmo de viterbi para a correcao e mostra os resultados
		co.viterbi()
		co.print_resultado()
		#co.print_modelo()


if __name__ == '__main__':
	if len(sys.argv) != 3:
		print('Use: {} <arquivo_texto> <arquivo_palavras>'.format(os.path.basename(sys.argv[0])))
		exit()
	main(sys.argv[1], sys.argv[2])

