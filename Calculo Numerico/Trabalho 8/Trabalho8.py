'''
' Calculo Numerico - Trabalho 8
' Fabricio N. Hubert (121151513)
'''


n = 5
x = [0.2, 0.4, 0.6, 0.8, 1.0]
y = [1.22, 1.49, 1.82, 2.23, 2.72]
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
				print("  ~  ", end="")
			else:
				print("%.2f " % mat[i][j], end="")
		print("")


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


while(True):
	print("Digite o valor de X ou `CTRL-C` para parar:")

	valorX = float(input())
	print("Resultado: %.4lf\n" % phi(valorX))
