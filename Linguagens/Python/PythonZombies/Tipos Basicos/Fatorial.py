num = int(input("Digite n: "))
fat = 1

while (num > 1):
	fat *= num
	num -= 1

print "fat: ", fat
