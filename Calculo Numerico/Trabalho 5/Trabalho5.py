import math


def eliminacaoGaussiana(matriz, vetor):

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


def somaVetor(vet, grau):
	return sum(x**grau for x in vet)


def somaDoisVetores(vet1, vet2, grau):
	return sum((x**grau)*y for x,y in zip(vet1, vet2))


def equacao(a, b, x):
	return b*x + a

def solucao(x, y, a, b):
	for i in range(len(x)):
		y[i] = equacao(a, b, x[i])
		print("y[%d] = %f" %(i, y[i]))


def mostrarEquacao(a, b):
	print("%fx + %f" %(b, a))



m = 6

mat = [[0 for y in range(m)] for x in range(m)]
vet = [0 for x in range(m)]

x = [-2, -1.5, 0, 1, 2.2, 3.1]
y = [-30.5, -20.2, -3.3, 8.9, 16.8, 21.3]


mat[0][0] = m
mat[0][1] = somaVetor(x, 1)
mat[1][0] = mat[0][1]
mat[1][1] = somaVetor(x, 2)
vet[0] = somaVetor(y, 1)
vet[1] = somaDoisVetores(x, y, 1)


a, b = eliminacaoGaussiana(mat, vet)

mostrarEquacao(a, b)
solucao(x, y, a, b)

