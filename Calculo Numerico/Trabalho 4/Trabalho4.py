'''
' Calculo Numerico - Trabalho 4
' Fabricio N. Hubert (121151513)
'''


import math

coeficientes = []
precisao = 0.00001
mostrar = False	# True para mostar as iteracoes passo a passo


def briotRuffini(x):

	while(True):

		primeiro, segundo = [], []
		r1, r2, rf = 0.0, 0.0, 0.0

		primeiro.append(coeficientes[0])
		for i in range(1, 6):
			primeiro.append(x*primeiro[i-1] + coeficientes[i])
		r1 = primeiro[-1]
		
		if(mostrar):
			print(primeiro)
		

		segundo.append(primeiro[0])
		for i in range(1, 6):
			segundo.append(x*segundo[i-1] + primeiro[i])
		r2 = segundo[-2]

		if(mostrar):
			print(segundo)

		rf = r1/r2
		x = x - rf

		if(rf < precisao):
			break

	return x






print("Digite os coeficientes A, B, C, D, E, F: ")
for i in range(6):
	coeficientes.append(float(input()))


while(True):
	print("Digite o chute inicial ou `CTRL-C` para parar:")

	x = float(input())
	print("Resultado: %.8lf\n" % briotRuffini(x))



