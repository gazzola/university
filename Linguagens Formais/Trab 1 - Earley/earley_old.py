"""
Algoritmo Earley
Linguagens Formais
UNIPAMPA
------------------

Marcos Treviso (121150107)
marcosvtreviso@gmail.com

Version of python: 3
For run use: python3 earley.py <gramatica.txt> <strings.txt>
"""

import sys
import os


def parar():
	sys.stdin.read(1)



def create_chart(w):

	w = w.split(" ")
	tam = len(w)+1
	w = ["@"]+w
	return [[] for x in range(tam)]



def le_gramatica(arquivo):
	f = open(arquivo, 'r')
	gramatica = {}

	inicial = '$'
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




def get_proxima_by_dot(producao):
	proxima = producao.split(".")
	proxima = proxima[1]

	if " " in proxima:
		temp = proxima.split(" ")
		proxima = temp[0]

	return proxima




def move_dot_in_producao(producao):
	
	comeco = producao.index(".")+1
	producao = list(producao)

	if comeco < len(producao):
		if " " in producao:
			pos = producao.index(" ")
			producao[comeco-1] = " "
			producao[pos] = "."
		else:
			producao[comeco-1] = " "
			producao += "."
	else:
		producao[comeco-1] = " "
		producao += "."


	novaprod = ""
	for x in producao:
		novaprod += x

	return novaprod.strip()




def scan(chart, estado, gramatica, palavra):
	
	for est, var, producoes in chart[estado-1]:
		proxima = get_proxima_by_dot(producoes)
		if proxima not in gramatica:
			if proxima == palavra:
				producoes = move_dot_in_producao(producoes)
				chart[estado].append([est, var, producoes])


def proxima_nas_regras(proxima, regras):
	for est, var, prod in regras:
		if var == proxima:
			return True
	return False



def predict_old(regras, regras_ant, estado):
	
	visitados = []
	for est, var, producoes in regras:
		proxima = get_proxima_by_dot(producoes)
		if proxima not in visitados and proxima_nas_regras(proxima, regras_ant):	
			visitados.append(proxima)
			for p in gramatica[proxima]:
				regras.append([estado, proxima, p])



def predict(chart, estado, gramatica):
	
	visitados = []
	for est, var, producoes in chart[estado]:
		proxima = get_proxima_by_dot(producoes)
		if proxima not in visitados and proxima in gramatica:	
			visitados.append(proxima)
			for p in gramatica[proxima]:
				chart[estado].append([estado, proxima, p])




def char_after_dot(char, producao):
	
	novaprod = ""
	for x in producao:
		novaprod += x

	novaprod = novaprod.split(".")[1].split(" ")

	if char in novaprod:
		return True

	return False



def attach(chart, estado, gramatica):
	
	
	visitados_ant = []
	visitados_atu = []
	i = 0

	while(True):

		regra = chart[estado][i]
		if regra not in visitados_atu:
			visitados_atu.append(regra)

			j = regra[0]
			char = regra[1]

			if j not in visitados_ant:
				visitados_ant.append(j)

				for est, var, prods in chart[j]:

					if char_after_dot(char, prods):
						prods = move_dot_in_producao(prods)
						chart[estado].append([est, var, prods])


		i += 1
		if j == 0 or i >= len(chart[estado]):
			break





def aceita_string(chart, estado):
	for est, var, prods in chart[estado]:
		if var == "$":
			if prods.index("S") < prods.index("."):
				return True
	return False


#def aceita_string(chart, estado):
#	for est, var, prods in chart[-1]:
#		if var == "S" and prods.index(".") == len(prods)-1:
#			return True
#
#	return False


def exibe_mensagem(chart, estado):
	if(aceita_string(chart, estado)):
		print(17*"-")
		print("| STRING ACEITA |")
		print(17*"-")
		print("")
	else:
		print(21*"-")
		print("| STRING NAO ACEITA |")
		print(21*"-")
		print("")



def parse_earley(chart, gramatica, w):
	
	estado = 0
	w = w.split(" ")
	w = ["@"]+w

	chart[estado].append([estado, "$", ".S"])
	predict(chart, estado, gramatica)
	
	while(estado < len(w)-1):
		estado += 1
		scan(chart, estado, gramatica, w[estado])
		attach(chart, estado, gramatica) #like completer
		predict(chart, estado, gramatica)

	
	exibe_mensagem(chart, estado)



def print_chart(chart):
	i = 0
	for r in chart:
		print(i)
		print(20*"-")
		for x,y,z in r:
			print("%d | %s -> %s" %(x,y,z))
		print("\n")
		i+=1


def print_chart_old(chart):
	for r in chart:
		print(r)
		print("\n\n")



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
		print_chart(chart)





if __name__ == '__main__':
	if len(sys.argv) != 3:
		print('Use: {} ARQUIVO_GRAMATICA ARQUIVO_STRINGS'.format(os.path.basename(sys.argv[0])))
		exit()
	main(sys.argv[1], sys.argv[2])
