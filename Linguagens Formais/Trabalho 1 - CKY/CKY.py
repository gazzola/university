"""
Algoritmo CKY
Linguagens Formais
UNIPAMPA
------------------

Marcos Treviso (121150107)
marcosvtreviso@gmail.com

Version of python: 3
For run use: python3 CKY.py <gramatica.txt> <strings.txt>
"""

import sys
import os


def parar():
	sys.stdin.read(1)


def getListBySimbols(gramatica, simb):
	variaveis = []
	for var, sentencas in gramatica.items():
		if simb in sentencas:
			variaveis.append(var)
	return variaveis


def getListByCombinations(gramatica, combinacoes):
	variaveis = []

	for A, B in combinacoes:
		for var, sentencas in gramatica.items():

			#ok1 = False
			#ok2 = False
			#
			#for i in range(len(sentencas)):
			#	if sentencas[i] == A:
			#		ok1 = True
			#		break
			#
			#for j in range(i+1, len(sentencas)):
			#	if sentencas[j] == B:
			#		ok2 = True
			#		break
			#
			#if ok1 and ok2:
			#	variaveis.append(var)

			if A in sentencas and B in sentencas:
				if sentencas.index(A) < sentencas.index(B):
					variaveis.append(var)

	return set(variaveis)


def makeCombinations(chart, i, j):
	comb = []
	for k in range(i, j):
		for eles1 in chart[i][k]:
			for eles2 in chart[k+1][j]:
				comb.append([eles1, eles2])
	return comb


'''
Algoritmo CKY. Calcula a matrix (chart) X de acordo com a gramatica G e a string w.
'''
def parse_CKY(gramatica, string):
	
	tam = len(string)
	chart = [[[] for y in range(tam)] for x in range(tam)]

	for j in range(tam):
		for i in range(j, -1, -1):

			if i == j:
				simb = string[i]
				chart[i][j] = getListBySimbols(gramatica, simb)
			else:
				comb = makeCombinations(chart, i, j)
				chart[i][j] = getListByCombinations(gramatica, comb)

	return chart


'''
Considere que a gramatica esta na Forma Normal de Chomsky.
Ha uma producao por linha. Lado esquerdo e direito sao separados por '->'. Simbolos do lado direito sao separados por espaco.
Regras com o mesmo lado esquerdo podem estar na mesma linha, separadas por '|', mas tambem podem estar em linhas diferentes.
Exemplos:
A -> B C
A -> a
A -> C D | b
'''
def le_gramatica(arquivo):
	f = open(arquivo, 'r')
	gramatica = {}

	for string in f:

		string = string.strip()
		cadeia = string.split("->")

		variavel = cadeia[0].strip()
		valores = cadeia[1].replace(" |", "")
		sentencas = valores.strip().split(" ")

		if variavel in gramatica:
			gramatica[variavel] += sentencas
		else:
			gramatica[variavel] = sentencas


	f.close()
	return gramatica



def le_strings(arquivo):
	f = open(arquivo,'r')
	strings = []
	for str in f:
		str = str.strip()  # Limpa eventuais espacos em branco no comeco e no fim
		strings.append(str)
	f.close()
	return strings


def printChart(chart):
	tam = len(chart)
	for i in range(tam):
		for j in range(i, tam):
			print(formatElements(chart[i][j]), end="")
			if j < tam-1:
				print(" ", end="")
		print("")


def formatElements(lista):
	
	#string = ""
	#for element in sorted(lista):
	#	string += element+","
	#
	#tam = len(string)-1
	#return string[0:tam]

	return ','.join(sorted(lista))


def main(arquivo_gramatica, arquivo_strings):
	gramatica = le_gramatica(arquivo_gramatica)
	strings = le_strings(arquivo_strings)

	for w in strings:
		# print('Processando string \'{}\''.format(w))
		chart = parse_CKY(gramatica, w)
		printChart(chart)


if __name__ == '__main__':
	if len(sys.argv) != 3:
		print('Use: {} ARQUIVO_GRAMATICA ARQUIVO_STRINGS'.format(os.path.basename(sys.argv[0])))
		exit()
	main(sys.argv[1], sys.argv[2])
