'''
' Calculo Numerico - Trabalho 6
' Fabricio N. Hubert (121151513)
'''


def eliminacaoGaussiana(matriz, vetor):

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



def somaVetor(vet, grau):
	return sum(x**grau for x in vet)


def somaDoisVetores(vet1, vet2, grau):
	return sum((x**grau)*y for x,y in zip(vet1, vet2))


def equacao(a, b, c, x):
	return c*x*x + b*x + a

def solucao(x, y, a, b, c):
	for i in range(len(x)):
		y[i] = equacao(a, b, c, x[i])
		print("y[%d] = %f" %(i, y[i]))


def mostrarEquacao(a, b, c):
	print("%fx^2 + %fx + %f" %(c, b, a))



m = 6

mat = [[0 for y in range(m)] for x in range(m)]
vet = [0 for x in range(m)]

x = [-2, -1.5, 0, 1, 2.2, 3.1]
y = [-30.5, -20.2, -3.3, 8.9, 16.8, 21.3]




mat[0][0] = m;
mat[0][1] = somaVetor(x, 1);
mat[0][2] = somaVetor(x, 2);
vet[0] = somaVetor(y, 1);

mat[1][0] = mat[0][1];
mat[1][1] = mat[0][2];
mat[1][2]= somaVetor(x, 3);
vet[1] = somaDoisVetores(x, y, 1);

mat[2][0] = mat[1][1];
mat[2][1] = mat[1][2];
mat[2][2]= somaVetor(x, 4);
vet[2] = somaDoisVetores(x, y, 2);


a, b, c = eliminacaoGaussiana(mat, vet)

mostrarEquacao(a, b, c)
solucao(x, y, a, b, c)