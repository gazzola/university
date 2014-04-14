arq = open('surf', 'r')

people = {}
for linha in arq.readlines():
	nome, nota = linha.split()
	people[float(nota)] = nome

arq.close()
for nota in sorted(people, reverse=True):
	print ('%s tem nota %4.2f'%(people[nota], nota))
