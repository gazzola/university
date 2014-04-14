import random

print random.randint(10,20)
print random.randint(10,20)

alunos = ['Jose', 'Joao', 'Pedro']
print random.choice(alunos)


random.shuffle(alunos)
print str(alunos)


def embaralha(s):
	lista = list(s)
	random.shuffle(lista)
	return ''.join(lista)

print embaralha('marcos')

lista = []
for k in range(15):
	lista.append(random.randint(10, 100))

print lista


lista2 = []
while len(lista2) < 15:
	x = random.randint(10, 100)
	if(x not in lista2):
		lista2.append(x)

lista2.sort()
print lista2