letras = ['N', 'O', 'P']
m, end = 5000, 0
res = list(m*" ")

def thue():
	global res, end
	x = len(res[:end])
	for i in range(1, int(x/2)+1):
		j = 0
		while j+i+i <= x:
			# print(v[j:i+j]+"=="+v[j+i:j+i+i], end=" ")
			if(res[j:i+j] == res[j+i:j+i+i]):
				return False
			j += 1
		# print("")
	return True


def backtrack():
	global res, letras, m, end
	if end == m:
		return True
	print("".join(res[:20]))
	print("".join(res))
	for l in letras:
		res[end-1] = l
		if thue() and backtrack():
			return True

	end -= 1
	return False


backtrack()
print("".join(res[:20]))

