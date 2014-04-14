arq = open('surf', 'r')

people = []
for linha in arq.readlines():
	nome, nota = linha.split()
	people.append((nome, nota))

arq.close()

people = sorted(people, key = lambda x : x[1], reverse = True)
print people[0]