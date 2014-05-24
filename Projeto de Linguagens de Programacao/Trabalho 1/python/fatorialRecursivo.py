import os, sys


def fatRec(n):
	if n <= 1:
		return 1
	return (n * fatRec(n-1))



val = int(sys.argv[1])
fat = fatRec(val)
print(fat)