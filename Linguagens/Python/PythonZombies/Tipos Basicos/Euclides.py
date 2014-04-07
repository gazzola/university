#mdc(21, 15) = 3

# a   b    a%b
# 21  15    6
# 15  6     3
# 6   3     0


a = int(input('a: '))
b = int(input('b: '))

tempa = a
tempb = b


i = 0

while(a % b != 0):
	a, b = b, a%b

print ("mdc(%d, %d): %d" %(tempa, tempb, b))