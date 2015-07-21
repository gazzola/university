print "INSERT INTO robos5 (nome, sobrenome, pais, idade, email, telefone, senha, salt) VALUES "

ate = 1000000-3
for i in xrange(ate):
	print " (FLOOR(RAND()*1000), FLOOR(RAND()*1000), FLOOR(RAND()*250), FLOOR(RAND()*100), FLOOR(RAND()*1000000), FLOOR(RAND()*1000000), FLOOR(RAND()*1000000), FLOOR(RAND()*1000000)),"

