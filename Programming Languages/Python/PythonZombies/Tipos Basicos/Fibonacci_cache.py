from functools import lru_cache

@lru_cache(maxsize=None)
def fib_super(n):
	print('fib(%d)' %n)
	if n <= 1:
		return n

	return fib_super(n-1) + fib_super(n-2)


fib_cache = {}
def fib(n):
	print('fib(%d)' %n)
	if n <= 1:
		return n
	else:
		if n not in fib_cache:
			fib_cache[n] = fib(n-1) + fib(n-2)
		return fib_cache[n]


def fib_ruim(n):
	print('fib(%d)' %n)
	if n <= 1:
		return n
	else:
		return fib_ruim(n-1) + fib_ruim(n-2)


def fib_it(n):
	a, b = 0, 1
	i = 0

	while(i <= n-2):
		a, b = b, a+b
		i += 1

	return b


def fib_generator():
	a, b = 0, 1
	while True:
		yield a
		a, b = b, a + b



result = fib_generator()
for x in range(8):
	print(next(result), end = " ")

print(fib(8))


