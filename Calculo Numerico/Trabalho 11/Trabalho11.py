import math


c1 = 0
coefs = [() for x in range(5)]
coefs[0] = ((1, 1), 1/2.0)
coefs[1] = ((1, 4, 1), 1/3.0)
coefs[2] = ((1, 3, 3, 1), 3/8.0)
coefs[3] = ((7, 32, 12, 32, 7), 2/45.0)
coefs[4] = ((19, 75, 50, 50, 75, 19), 5/288.0)


def eq(x):
	return math.sin(x**2)


def get_h(a, b, n):
	return (b-a)/(n*1.0)


def solve(i, h, m):
	a = i*h*m
	xs = [a+i*h for i in range(m+1)]
	soma = sum([c*eq(x) for c, x in zip(coefs[m-1][0], xs)])
	return soma * coefs[m-1][1]*h


def newton_cotes(a, b, m, M):
	n = m*M
	h = get_h(a, b, n)
	soma = 0
	ads = a+M
	for k in range(M):
		soma += solve(i, h, m)
	return soma


while(True):
	
	print("Digite os valores dos coeficientes a:")
	c1 = int(input())

	print("Digite os intervalos de integracao i, j:")
	i, j = map(float, input().split())

	print("Digite o grau m e o n de subdivisoes M:")
	m, M = map(int, input().split())

	print("Metodo de Newton Cotes: %.8f" % newton_cotes(i, j, m, M))
	print("")

