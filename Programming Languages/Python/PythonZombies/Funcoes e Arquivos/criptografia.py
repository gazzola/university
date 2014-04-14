print ord('X')
print chr(100)


limit = 15

def esconde(msg):
	s = ''
	for c in msg:
		s += chr(ord(c) + limit)
	return s

def mostra(msg):
	s = ''
	for c in msg:
		s += chr(ord(c) - limit)
	return s


x = esconde('bely')
print x
print mostra(x)