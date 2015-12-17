import sys
b = 0
for line in sys.stdin:
	if b == 0:
		b = 1
		continue

	x = line.replace("/", " ")
	x = x.replace(":", " ")

	a = list(map(int, x.strip().split()))
	if a[2] != 0:
		print("%d %.4f" % (a[0], a[1]/a[2]))
