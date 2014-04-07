x = '0123456789'
print x[0:2]
print x[2:6]

#SEM COLOCAR = INICIO OU FIM / NEGATIVO = MENOS POSICAO
print x[:2]
print x[4:]
print x[4:-1]
print x[-4:-1]
print x[:]

#INCREMENTO
print x[::2]
print x[::-1]

txt = 'Alo Mundo'
txt = '@'+txt[1:]
print txt

palavra = raw_input('Palavra: ')
troca = ''

for i in palavra:
	if(i in 'aeiou'):
		troca = troca + '*'
	else:
		troca = troca + i

print "Nova palavra:", troca



dia, mes, ano = raw_input('Data (d/m/Y): ').split('/')
meses = ['janeiro', 'fevereiro', 'marco', 'abril', 'maio', 'junho', 'julho', 'agosto', 'setembro', 'outubro', 'novembro', 'dezembro']
print ('Voce nasceu em: %s de %s de %s' %(dia, meses[int(mes)-1], ano))
