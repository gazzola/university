import math

def ln(x):
	return math.log(x, math.e)



a, b, c, d = 0, 0, 0, 0

def eq(x):
	return x*x - math.e**x


def getH(i, j, n):
	return (j-i)/(n*1.0)


def metodo_simpson_composta(i, j, n):
	
	h = getH(i, j, n)

	s = eq(i) + eq(j)
	for k in range(1, n):
		if k % 2 == 0:
			s += 2 * eq(i + k*h)
		else:
			s += 4 * eq(i + k*h)

	return  s * h/3.0




while(True):
	
	print("Digite os valores dos coeficientes a, b, c, d:")
	a, b, c, d = map(int, input().split())

	print("Digite os intervalos de integracao i, j:")
	i, j = map(int, input().split())

	if i <= 0 or j <= 0:
		print("Os valores dos intervalores devem ser maiores que 0")
		continue

	print("Digite o numero de divisoes n:")
	n = int(input())

	print("Metodo de Simpson Comp: %.8f" % metodo_simpson_composta(i, j, n))
	print("")

