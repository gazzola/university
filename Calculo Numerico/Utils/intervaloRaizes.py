import math



def eq(x):
	return (2*(x**5)) - (x**3) - (4*x) + 6



def limites(a, b, debug):

	lims = []
	ant = eq(a)

	if debug:
		print("%d: %.8f" %(a, ant))

	for i in range(a+1, b+1):
		atual = eq(i)

		if((atual < 0 and ant > 0) or (atual > 0 and ant < 0)):
			lims.append((i-1, i))

		if debug:
			print("%2d: %.8f" %(i, atual))

		ant = atual

	return lims



def isolamento(a, b):
	return (eq(a)*eq(b)) < 0



def qtdRaizesReais(coefs):
	qtdPos = 0
	for i in range(1, len(coefs)):
		if (coefs[i-1] < 0 and coefs[i] > 0) or (coefs[i-1] > 0 and coefs[i] < 0):
			qtdPos += 1
	
	grau = len(coefs)-1
	for i in range(len(coefs)):
		if grau%2 == 0:
			coefs[i] *= -1
		grau -= 1

	qtdNeg = 0
	for i in range(1, len(coefs)):
		if (coefs[i-1] < 0 and coefs[i] > 0) or (coefs[i-1] > 0 and coefs[i] < 0):
			qtdNeg += 1

	return "pos: "+str(qtdPos)+"  |  neg: "+str(qtdNeg)



def temComplexas(coefs):
	g = len(coefs)-1
	for i in range(1, len(coefs)-1):
		if (coefs[i-1], coefs[i], coefs[i+1]) != (0,0,0):
			if((coefs[i]*(g-i)) <= coefs[i-1]*coefs[i+1]):
				return True
	return False
	



print(limites(-3, 3, True))
print(isolamento(-2, -1))
print(qtdRaizesReais([12, -7, 6, -171]))
print(temComplexas([-2, 1, -1]))