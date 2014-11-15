import math

def eliminacaoGaussiana3(matriz, vetor):

	n = 3

	# juncao de L1 com L2
	a = matriz[0][0]
	b = matriz[1][0]
	x = -b/a

	for i in range(n):
		matriz[1][i] += matriz[0][i]*x
	vetor[1] += vetor[0]*x


	# juncao de L1 com L3
	a = matriz[0][0]
	b = matriz[2][0]
	x = -b/a

	for i in range(n):
		matriz[2][i] += matriz[0][i]*x
	vetor[2] += vetor[0]*x


	# juncao de L2 com L3
	a = matriz[1][1]
	b = matriz[2][1]
	x = -b/a

	for i in range(1, n):
		matriz[2][i] += matriz[1][i]*x
	vetor[2] += vetor[1]*x


	# valores das incognitas
	x3 = vetor[2]/matriz[2][2]
	x2 = (vetor[1] - matriz[1][2]*x3)/matriz[1][1]
	x1 = (vetor[0] - matriz[0][2]*x3 - matriz[0][1]*x2)/matriz[0][0]

	return (x1, x2, x3)


def eliminacaoGaussiana2(matriz, vetor):

	n = 2
	a = matriz[0][0]
	b = matriz[1][0]
	x = (-b)/a

	for i in range(n):
		matriz[1][i] += matriz[0][i]*x
	vetor[1] += vetor[0]*x


	x2 = vetor[1]/matriz[1][1]
	x1 = (vetor[0] - matriz[0][1]*x2)/matriz[0][0]  
	
	return (x1, x2)