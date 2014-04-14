import sqlite3

banco = sqlite3.connect('surfersDB.sdb')
banco.row_factory = sqlite3.Row
cursor = banco.cursor()
cursor.execute('SELECT * FROM surfers WHERE age > 25')
geral = cursor.fetchall()

for linha in geral:
	print "Nome    :", linha['name']
	print "Pais    :", linha['country']
	print "Media   :", linha['average']
	print "Estilo  :", linha['board']
	print "Idade   :", linha['age']
	print ''

cursor.close()