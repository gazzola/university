import math


a, b, c = 0, 0, 0

def eq(x):
	return a*math.sin(x) + b*math.cos(x) + c*x



def getH(i, j, n):
	return (j-i)/(n*1.0)


def metodo_retangulos(i, j, n):
	
	h = getH(i, j, n)
	h2 = h/2.0

	s = 0
	for k in range(i, j):
		x = i + k*h
		s += eq(x+h2)*h
	 
	return s


def metodo_trapezios(i, j, n):

	h = getH(i, j, n)
	
	s = 0
	for k in range(i, j):
		x = (eq(k) + eq(k+1)) / 2.0
		s += x*h
	 
	return s



while(True):
	
	print("Digite os valores dos coeficientes a, b, c:")
	a, b, c = map(int, input().split())

	print("Digite os intervalos de integracao i, j:")
	i, j = map(int, input().split())

	print("Digite o numero de divisoes n:")
	n = int(input())

	print("Metodo dos Retangulos : %.8f" % metodo_retangulos(i, j, n))
	print("Metodo dos Trapezios  : %.8f" % metodo_trapezios(i, j, n))
	print("")

