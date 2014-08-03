"""
Algoritmo CKY
Linguagens Formais
UNIPAMPA
"""
import sys
import os


'''
Algoritmo CKY. Calcula a matrix (chart) X de acordo com a gramatica G e a string w.
'''
def parse_CKY(G, w):
	
	tamString = len(w)
	chart = [[[] for y in range(tamString)] for x in range(tamString)]

	for j in range(tamString):
		for i in range(j, -1, -1):

			if i == j: #diagonal principal
				
				procurado = w[j]
				combinacoes = []

				for v in G:
					if procurado in G[v]:
						combinacoes.append(v)
				
				chart[i][j] = combinacoes

			else:

				combinacoes = []
				novasCombinacoes = []

				for k in range(i, j):
					for primeiro in chart[i][k]:
						for segundo in chart[k+1][j]:
							c = primeiro+segundo
							combinacoes.append(c)

				for c in combinacoes:
					for v in G:
						if c in G[v]:
							if v not in novasCombinacoes:
								novasCombinacoes.append(v)

				chart[i][j] = novasCombinacoes

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

	for s in f:

		s = s.strip().replace(" ", "").split("->")
		
		variavel = s[0]
		producoes = s[1].split("|")

		if variavel not in gramatica:
			gramatica[variavel] = producoes
		else:
			gramatica[variavel].extend(producoes)
			

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
		print(convertePraString(chart[i][i]), end="")
		for j in range(i+1, tam):
			print(" ", end="")
			print(convertePraString(chart[i][j]), end="")
		print("")


def convertePraString(lista):
	return ','.join(sorted(lista)) #como o implode do PHP


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
