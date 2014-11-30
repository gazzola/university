import math
# ver metodos disponiveis na math:
# print(dir(math))


def equacao(x):
	return x*x + x - 6

def eqDerivada(x):
	return 2*x + 1

def phi(x):
	return x - equacao(x)/eqDerivada(x)


def newtonRaphson(x, precisao):
	
	y = equacao(x)
	while(abs(y) > precisao):
		x = phi(x)
		y = equacao(x)

	return x



# main
precisao = 0.0001

while(True):
	print("Digite a aproximacao inicial ou `STOP` para parar:")
	aprox = input()
	if(aprox.upper() == 'STOP'):
		break
	print("Resultado: %.4lf\n" % newtonRaphson(float(aprox), precisao))