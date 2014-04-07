import MySQLdb

con = MySQLdb.connect('localhost', 'root', 'root', 'testes') 
cursor = con.cursor()
cursor.execute('SELECT * FROM usuarios')
rs = cursor.fetchall()

print rs