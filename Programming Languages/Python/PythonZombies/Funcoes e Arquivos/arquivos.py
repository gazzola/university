import random, sys

arquivo = open('numeros', 'r')



lista = []
for linha in arquivo.readlines():
	lista.append(linha.rstrip())

print ''.join(lista)

arquivo.close()

#other way to do the same thing:
#with open('numeros') as f:
#	print f.read().splitlines(), 



#crypt message replacing vogals by *
entrada = open('mensagem')
saida = open('mensagemcrypt', 'w')

for linha in entrada.readlines():
	for letra in linha:
		if letra in 'aeiou':
			saida.write('*')
		else:
			saida.write(letra)

entrada.close()
saida.close()




#Verify IP
def ip_ok(ip):
	ip = ip.split('.')
	for byte in ip:
		if int(byte) > 255:
			return False
	return True

arq = open('listadeips')
validos = []
invalidos = []

for linha in arq.readlines():
	if(ip_ok(linha)):
		validos.append(linha.rstrip())
	else:
		invalidos.append(linha.rstrip())

arq.close()

print 'Validos:', validos
print '\nInvalidos', invalidos





#Write html page
arq =open('hello.html', 'w')
arq.write('''<!DOCTYPE html>
<html lang="pt-BR">
<head>
<meta charset="utf-8" />
<title>Titulo da Pagina</title>
</head>
<body>
<h1>Hello World!!!</h1>
</body>
</html>''')
arq.close()