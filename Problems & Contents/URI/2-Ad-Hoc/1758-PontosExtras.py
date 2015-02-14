# import sys

try:
    # just to see the Python 2.5 + psyco speed - 17 times faster than Python 2.7 !!!
    import psyco
    psyco.full()
except:
    pass

TAM = 50
notas = [0 for i in range(TAM)]
maior = [0 for i in range(TAM)]
maior7 = [0 for i in range(TAM)]

t = int(raw_input())
for w in xrange(t):

	p, n = map(int, raw_input().split())

	for i in xrange(n):

		notas[i] = 0
		maior[i] = 0
		maior7[i] = 0

		for y in map(float, raw_input().split()):	
			if y < 7:
				maior7[i] = max(y, maior7[i])

			maior[i] = max(y, maior[i])
			notas[i] += y

	
		if notas[i] < 7*p:
			if notas[i] < 4*p:
				print "%.2f" % (notas[i]/p)
			else:
				if maior7[i]*p > notas[i]:
					print "%.2f" % maior7[i]
				else:
					print "%.2f" % (notas[i]/p)
		else:
			print "%.2f" % maior[i]



