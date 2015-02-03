import math

x = [0.15, 0.20, 0.25, 0.30, 0.35, 0.40]
y = [0.12, 0.16, 0.19, 0.22, 0.25, 0.27]
n = len(x)
pols = ["" for i in range(n)]


def roundp(number, precision):
	return  ("{:."+str(precision)+"f}").format(number) 


def lagrange(valorX, p=2):
	
	mat = [[0 for y in range(n)] for x in range(n)]
	polynom = ""
	
	phi = 0
	for k in range(n):
		
		lk = 1
		for i in range(n):
			if(i != k):
				lk *= ((valorX-x[i])/(x[k]-x[i]))
				pols[k] += "((x - "+roundp(x[i], p)+")/("+roundp(x[k], p)+" - "+roundp(x[i], p)+"))."

		phi += lk*y[k]
		polynom += roundp(y[k], p)+".L"+str(k)+" + "

	return (phi, polynom)



def printPolynomial(polynom):
	for k in range(n):
		print("L"+str(k)+" = %s" % pols[k][0:-1])
	print("Phi(x) = " + polynom[0:-3])



while(True):
	print("Digite o valor de X ou `CTRL-C` para parar:")

	valorX = float(input())
	res, pol = lagrange(valorX)

	print("\nPolinomio gerador: ")
	printPolynomial(pol)
	print("")
	print("Resultado: %.4lf\n" % res)

