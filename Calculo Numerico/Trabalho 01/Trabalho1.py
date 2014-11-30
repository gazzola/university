import math

def inteiroParaBinario(inteiro):

	if inteiro == 0:
		return "0"

	binario = ""

	while(inteiro != 0):
		resto = inteiro%2
		binario = str(resto)+binario
		inteiro = int(inteiro/2)

	return binario




def binarioParaInteiro(binario):
	inteiro = 0
	tamanho = len(binario)-1
	contador = 0

	for i in range(tamanho, -1, -1):
		if binario[i] == '1':
			inteiro += (2**contador)
		contador += 1

	return inteiro




def flutuanteParaBinario(flutuante):

	expoente = 0

	# sig    exp        |  mantissa
	# 1   |  111111111  |  10101010111010101

	sinal = '1'
	if flutuante < 0:
		sinal = '0'

	# 12 -> 2
	
	# 12.75
	# 12.75 / 10^2
	# 0.1275 

	if flutuante > 1:
		expoente = len(str(int(flutuante)))
		flutuante = flutuante/(10**expoente)


	
	binario = ""
	bits = 52
	while(bits > 0):
		
		if flutuante > 1:
			binario += '1'
		elif flutuante < 1:
			binario += '0'
		else:
			binario += '1'
			break

		flutuante = flutuante - int(flutuante);
		flutuante = flutuante*2

		bits -= 1

	return sinal + "-" + inteiroParaBinario(expoente) + "-" + binario




def binarioParaFlutuante(binario):

	sinal, expoente, mantissa = binario.split("-")
	
	expoente = binarioParaInteiro(expoente)
	flutuante = 0
	contador = 0

	for i, bit in enumerate(mantissa):
		flutuante += int(bit) * 2**(-i)

	if sinal == '0':
		flutuante = -flutuante;

	return flutuante * 10**expoente





print(inteiroParaBinario(25))
print(binarioParaInteiro("11001"))
print(flutuanteParaBinario(0.625))
print(binarioParaFlutuante("1-00-0101"))