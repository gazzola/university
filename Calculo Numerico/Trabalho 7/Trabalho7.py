'''
' Calculo Numerico - Trabalho 7
' Fabricio N. Hubert (121151513)
'''



x = [1, 2, 3, 4]
y = [1, 4, 9, 16]

def lagrange(valorX):
	
	n = len(x)
	mat = [[0 for y in range(n)] for x in range(n)]

	phi = 0
	for k in range(n):
		
		lk = 1
		for i in range(n):
			if(i != k):
				lk *= ((valorX-x[i])/(x[k]-x[i]))

		phi += lk*y[k]

	return phi


while(True):
	print("Digite o valor de X ou `CTRL-C` para parar:")

	valorX = float(input())
	print("Resultado: %.4lf\n" % lagrange(valorX))

