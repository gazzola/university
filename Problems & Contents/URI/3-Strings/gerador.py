import random

def f(m, n):
	print(n-m)
	for i in xrange(m, n):
		print(i)
	print(0)


def g(n):
	print(n)
	k = 10**12
	for i in xrange(n):
		print(random.randint(0,k))
	print(0)



f(1, 1001)
# g(1000)