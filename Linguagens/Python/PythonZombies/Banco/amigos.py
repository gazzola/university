import sqlite3

con = sqlite3.connect('alunos.bd')
cur = con.cursor()

#cur.execute("CREATE TABLE alunos(login varchar(8), ra integer)")

cur.execute("INSERT INTO alunos VALUES('marcos', 42)")
cur.execute("INSERT INTO alunos VALUES('bely', 12)")

cur.execute("SELECT * FROM alunos")

for linha in cur.fetchall():
	print linha[0], linha[1]

cur.close()
con.commit()
con.close()