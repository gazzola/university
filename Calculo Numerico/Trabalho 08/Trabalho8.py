import math

n = 6
x = [0.15, 0.20, 0.25, 0.30, 0.35, 0.40]
y = [0.12, 0.16, 0.19, 0.22, 0.25, 0.27]
mat = [[0 for y in range(n)] for x in range(n)]

def newton():

	for i in range(n):
		mat[i][0] = y[i]

	for i in range(1, n):
		for j in range(i, n):
			mat[j][i] = (mat[j][i-1]-mat[j-1][i-1])/(x[j]-x[j-i])
	

	for i in range(n):
		for j in range(n):
			if(j > i):
				print("%4.4s " % "~", end="")
			else:
				print("%4.4f " % mat[i][j], end="")
		print("")



def roundp(number, precision):
	return  ("{:."+str(precision)+"f}").format(number) 


def polynomial(p=4):
	
	polynom = roundp(y[0], p)
	for i in range(1, n):
		polynom += " + "
		for j in range(0, i):
			polynom += "(x - "+roundp(x[j], p)+")*"
		polynom += "("+roundp(mat[i][i], p)+")"

	return polynom


def phi(valorX):

	total = y[0]
	for i in range(1, n):
		prod = 1.0
		for j in range(0, i):
			prod *= (valorX - x[j])
		total += (prod*mat[i][i])

	return total


print("Metodo de Newton para valores: ")
print("X: ", end="")
print(x)
print("Y: ", end="")
print(y, end="\n\n")

print("Tabela de solucao: ")
newton();
print("")

print("Polinomio gerador: ")
print("Phi(x) = "+polynomial())
print("")

while(True):
	print("Digite o valor de X ou `CTRL-C` para parar:")

	valorX = float(input())
	print("Resultado: %.4lf\n" % phi(valorX))
