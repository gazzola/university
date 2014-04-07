#1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...

# a  b   a+b
# 1  1    2
# 1  2    3
# 2  3    5
# 3  5    8


n = int(input('N: '))

a, b = 1, 1
i = 0

while(i < n-2):
	a, b = b, a+b
	i += 1

print ("%d elemento: %d" %(n, b))