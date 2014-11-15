# para interpolacao usando metodos de
# newton e de lagrange: veja os trabs 7 e 8

import math
from systemSolver import eliminacaoGaussiana3



x = [86.0, 93.3, 98.9, 104.4, 110.0]
y = [1552, 1548, 1544, 1538, 1532]
n = len(x)


def intervalo(val):
	for i in range(n-1):
		if (x[i] < val < x[i+1]) or (x[i] > val > x[i+1]):
			return (i, i+1)
	return (-1, -1)



def roundp(number, precision=4):
	return  ("{:."+str(precision)+"f}").format(number) 


def interpolacao_linear(val):

	i, j = intervalo(val)
	if i == -1:
		print("Intervalo para o valor de x nao existe nos pontos passados")
		return (0, "")

	a0 = (x[j]*y[i] - x[i]*y[j])/(x[j]-x[i])
	a1 = (y[j]-y[i])/(x[j]-x[i])
	
	res = a0 + a1*val
	equacao = roundp(a0) + " + " + roundp(a1) + "x"

	return (res, equacao)


def interpolacao_quadratica(val):

	i, k = intervalo(val)
	if i == -1 and k == -1:
		print("Intervalo para o valor de x nao existe nos pontos passados")
		return (0, "")

	if i == -1 and k != i:
		i += 1
	elif k+1 == n:
		i -= 1

	j = i+1
	k = j+1
	print(i, j, k)

	# 3x3
	mat = [[0 for y in range(3)] for x in range(3)]
	vet = [0 for x in range(3)]

	mat[0][0] = 1
	mat[1][0] = 1
	mat[2][0] = 1
	
	mat[0][1] = x[i]
	mat[1][1] = x[j]
	mat[2][1] = x[k]

	mat[0][2] = x[i]**2
	mat[1][2] = x[j]**2
	mat[2][2] = x[k]**2

	vet[0] = y[i]
	vet[1] = y[j]
	vet[2] = y[k]

	a0, a1, a2 = eliminacaoGaussiana3(mat, vet)

	res = a0 + a1*val + a2*val*val
	equacao = roundp(a0) + " + " + roundp(a1) + "x + " + roundp(a2) + "x^2"

	return (res, equacao)




if __name__ == "__main__":

	print("Interpolacao Linear: ")
	res, pol = interpolacao_linear(90)
	print("Polinomio: %s" % pol)
	print("Resultado: %.2f" % res)

	print("Interpolacao Quadratica: ")
	res, pol = interpolacao_quadratica(88)
	print("Polinomio: %s" % pol)
	print("Resultado: %.2f" % res)
