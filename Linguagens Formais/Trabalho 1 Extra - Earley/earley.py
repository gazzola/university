"""
Algoritmo Earley
Linguagens Formais
UNIPAMPA
------------------

Marcos Treviso (121150107)
marcosvtreviso@gmail.com

Version of python: 3
For run use: python3 earley.py <gramatica.txt> <strings.txt>

Important: 	
the strings in strings.txt must be separated by spaces, 
because the default example uses complete sentences to make
the test over the algorithm.

the gamma state is represented by `$` symbol, please 
be sure that the your grammar do not have this symbol,
and the start symbol is represented by 'S', then please
be sure that the your start symbol is it.

Extra:
if you want the parser tree, just make a pointer
to the parent state in completer function, after that,
you can use a bib to draw the tree or print a vector
with all pointers in order of creation.

Complexity:
Best case is O(n^2) [not ambiguous]
Worst case is O(n^3) [ambiguous]
"""

import sys
import os

inicial = '$'


def parar():
	sys.stdin.read(1)


def create_chart(w):
	w = w.split(" ")
	tam = len(w)+1
	return [[] for x in range(tam)]



def le_gramatica(arquivo):
	f = open(arquivo, 'r')
	gramatica = {}


	tem_inicial = False
	for string in f:

		cadeia = string.strip().split("->")
		
		variavel = cadeia[0].strip()

		if("|" in cadeia[1]):
			cadeia = cadeia[1].strip().split(" | ")
			producoes = []
			for c in cadeia:
				producoes += ["."+c]
		else:
			cadeia = cadeia[1].replace(" |", "").strip()
			producoes = ["."+cadeia]
		
		
		if(variavel == inicial):
			tem_inicial = True

		if variavel in gramatica:
			gramatica[variavel] += producoes
		else:
			gramatica[variavel] = producoes


	if(not tem_inicial):
		gramatica[inicial] = ['S']

	f.close()
	return gramatica






def mover_ponto_na_producao(producao):
	
	comeco = producao.index(".")+1
	producao = list(producao)

	if comeco < len(producao):
		if " " in producao:
			pos = producao.index(" ")
			producao[pos] = "."
		else:
			producao += "."

		producao[comeco-1] = " "
	
	return ''.join(producao).strip()



def pega_proxima_pelo_ponto(producao):
	return producao.split(".")[1].split(" ")[0]


def variavel_depois_do_ponto(char, producao):
	return (char == pega_proxima_pelo_ponto(producao))


def completa(valor):
	return (valor == " " or valor == "")



def scanner(chart, i, estado, gramatica, palavra):
	
	proxima = pega_proxima_pelo_ponto(estado[2])
	if proxima not in gramatica:
		if proxima == palavra:
			producao = mover_ponto_na_producao(estado[2])
			chart[i].append([estado[0], estado[1], producao])




def predictor(chart, i, estado, gramatica, visitados):
	
	proxima = pega_proxima_pelo_ponto(estado[2])
	if proxima not in visitados and proxima in gramatica:	
		visitados.append(proxima)
		for producao in gramatica[proxima]:
			chart[i].append([i, proxima, producao])



def completer(chart, i, estado):
	
	k = estado[0]
	char = estado[1]

	for est, var, prods in chart[k]:
		if variavel_depois_do_ponto(char, prods):
			prods = mover_ponto_na_producao(prods)
			if [est, var, prods] not in chart[i]:
				chart[i].append([est, var, prods])



def parse_earley(chart, gramatica, w):
	

	w = w.split(" ")
	chart[0].append([0, inicial, ".S"]) #noob state
		
	for i in range(len(chart)):
		
		visitados_predictor = []

		j = 0
		while j < len(chart[i]):

			estado = chart[i][j]
			proxima = pega_proxima_pelo_ponto(estado[2])

			if not completa(proxima) and proxima in gramatica:
				predictor(chart, i, estado, gramatica, visitados_predictor)
			elif not completa(proxima) and proxima not in gramatica:
				if i+1 < len(chart):
					scanner(chart, i+1, estado, gramatica, w[i])
			else:
				completer(chart, i, estado)

			j += 1




def aceita_string(chart):
	
	for est, var, prods in chart[-1]:
		if var == "$" and prods.index(".") == len(prods)-1:
			return True

	return False



def exibe_mensagem(chart, w):

	if(aceita_string(chart)):
		print("STRING `%s` ACEITA\n" % w)
	else:
		print("STRING `%s` NAO ACEITA\n" % w)



def print_chart(chart):
	i = 0
	for r in chart:
		print(i)
		print(20*"-")
		for x,y,z in r:
			if y == "$":
				print("\033[92m%d | %s -> %s\033[0m" %(x,y,z))
			else:
				print("%d | %s -> %s" %(x,y,z))
		print("\n")
		i+=1



def print_gramatica(gramatica):
	for x, y in gramatica.items():
		print(x, end=": ")
		print(y)
		print("\n\n")



def le_strings(arquivo):
	f = open(arquivo,'r')
	strings = []
	for str in f:
		str = str.strip()
		strings.append(str)
	f.close()
	return strings



def main(arquivo_gramatica, arquivo_strings):
	gramatica = le_gramatica(arquivo_gramatica)
	strings = le_strings(arquivo_strings)

	for w in strings:
		chart = create_chart(w)
		parse_earley(chart, gramatica, w)
		
		exibe_mensagem(chart, w)
		print_chart(chart)


if __name__ == '__main__':
	if len(sys.argv) != 3:
		print('Use: {} ARQUIVO_GRAMATICA ARQUIVO_STRINGS'.format(os.path.basename(sys.argv[0])))
		exit()
	
	main(sys.argv[1], sys.argv[2])
