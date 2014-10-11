'''
' Calculo Numerico - Trabalho 2
' Fabricio N. Hubert (121151513)
'''

from decimal import Decimal
from math import ceil, floor

INF = 999999
a, b, c, d = 0, 0, 0, 0


def equacaoLog(x):
	if(x == 0):
		return -INF
	return x * x.log10() - 1


def equacao3Grau(x):
	return (a * x**3) + (b * x**2) + (c * x) + d


def bissecao(a, b, max_erro):

	ini, meio, fim = a, 0, b
	erro = fim - ini
	
	while(erro > max_erro):
		
		meio = (ini+fim)/2
		resx = equacao3Grau(meio)
		resa = equacao3Grau(ini)
		
		if(resa * resx > 0):
			ini = meio
		else:
			fim = meio
			
		erro = fim - ini

	return meio




# main
a, b, c, d = 1, -6, 4, 12
precisao = 0.0001

rx = bissecao(-INF, INF, precisao)
r1 = bissecao(-INF, rx, precisao)
r3 = bissecao(rx, INF, precisao)
r2 = bissecao(r1+precisao, r3-precisao, precisao)

print("Raiz 1:", r1)
print("Raiz 2:", r2)
print("Raiz 3:", r3)