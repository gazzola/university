import os, sys


def fatIter(n):
	x = 1
	for i in range(1, n+1):
		x *= i
	return x


val = int(sys.argv[1])
fat = fatIter(val)
print(fat)
