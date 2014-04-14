soma = 0
while True:
	x = int(input('Digite um numero ou 0 para sair: '))
	if (x == 0):
		break
	soma += x

print ("Soma: %d" %soma)