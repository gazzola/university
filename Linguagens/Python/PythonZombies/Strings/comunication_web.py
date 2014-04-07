import urllib2, time, json

def pega_preco():
	res = urllib2.urlopen('http://beans.itcarlow.ie/prices-loyalty.html')
	txt = res.read().decode('utf8')
	preco = txt[234:238]

	onde = txt.find('>$')
	inicio = onde+2
	fim = inicio+4
	return float(txt[inicio:fim])


opcao = raw_input('Deseja comprar ja? (Y/N) ').upper()

if opcao == 'Y': 
	preco = pega_preco()
	print ('Comprar! preco: %5.2f' %preco)
else:
	preco = 99.99
	ideal = 4.74
	while preco >= ideal:
		preco = pega_preco()
		if preco >= ideal:
			time.sleep(600)
	print ('Comprar! preco: %5.2f' %preco)