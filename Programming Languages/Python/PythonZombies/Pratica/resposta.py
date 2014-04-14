print 'Bem vindo ao maior enigma da humanidade!'
print 'Diga um numero inteiro, so acertando o numero para vencer.'



chute = 0
resposta = ord('-') - 3
#import random
#resposta = random.randint(1, 100)
tentativas = 10

print 'Obs: Voce tem '+str(tentativas)+' tentativas.'

while tentativas > 0:
	
	chute = int(input('Diga um numero: '))
	tentativas -= 1

	if chute == resposta:
		print '\o/\o/\o/ Voce venceu! \o/\o/\o/'
		break
	else:
		if chute > resposta:
			print 'Alto!'
		else:
			print 'Baixo!'

if tentativas == 0:
	print 'Game Over!'
else:
	print 'Fim de Jogo!'