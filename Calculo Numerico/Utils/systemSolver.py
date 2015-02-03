import math
import numpy as np


def solve(matriz, vetor):
	a = np.array(matriz)
	b = np.array(vetor)
	return np.linalg.solve(a, b)


def gauss(matriz, vetor):

	n = len(matriz)
	for i in range(n):
		matriz[i].append(vetor[i])


	for i in range(n):
		
		# Search for maximum in this column
		maxEl = abs(matriz[i][i])
		maxRow = i
		for k in range(i+1, n):
			if abs(matriz[k][i]) > maxEl:
				maxEl = abs(matriz[k][i])
				maxRow = k

		
		# Swap maximum row with current row (column by column)
		for k in range(i, n+1):
			tmp = matriz[maxRow][k]
			matriz[maxRow][k] = matriz[i][k]
			matriz[i][k] = tmp

		
		# Make all rows below this one 0 in current column
		for k in range(i+1, n):
			c = -matriz[k][i]/matriz[i][i]
			for j in range(i, n+1):
				if i == j:
					matriz[k][j] = 0
				else:
					matriz[k][j] += c * matriz[i][j]


	# Solve equation Ax=b for an upper triangular matrix matriz
	x = [0 for i in range(n)]
	for i in range(n-1, -1, -1):
		x[i] = matriz[i][n]/matriz[i][i]
		for k in range(i-1, -1, -1):
			matriz[k][n] -= matriz[k][i] * x[i]

	return x




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





if __name__ == "__main__":
	
	mat = [[1., 0.20, 0.04], [1., 0.25, 0.0625], [1., 0.30, 0.09]]
	vet = [0.16, 0.19, 0.22]

	k = solve(mat, vet)
	print(k)

	x = 0.28
	print(k[0] + k[1]*x + k[2]*x*x)

