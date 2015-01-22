import os
from math import hypot, atan2

pivo = (0, float("inf"))

def cross(a, b):
	return a[0]*b[1] - a[1]*b[0]


def to_vec(a, b):
	return (b[0]-a[0], b[1]-a[1])


def colinear(a, b, c):
	return abs(cross(to_vec(a, b), to_vec(a, c))) < 1e-9


def ccw(a, b, c):
	return cross(to_vec(a, b), to_vec(a, c)) > 0


def compare(a, b):
	if colinear(pivo, a, b):
		if hypot(pivo[0]-a[0], pivo[1]-a[1]) < hypot(pivo[0]-b[0], pivo[1]-b[1]):
			return -1
		else:
			return 1


	d1 = (a[0]-pivo[0], a[1]-pivo[1])
	d2 = (b[0]-pivo[0], b[1]-pivo[1])

	if (atan2(d1[1], d1[0])-atan2(d2[1], d2[0])) < 0:
		return -1
	else:
		return 1


def menor(a, b):
	if a[1] < b[1]:
		return True
	elif a[1] > b[1]:
		return False
	return a[0] > b[0]


while True:

	n = int(raw_input())
	if n == 0:
		break

	pontos = []

	i = 0
	j = 0
	N = n

	while n > 0:
		x, y = map(int, raw_input().split())
		pontos.append([x, y])
		
		if(menor(pontos[i], pontos[j])):
			j = i

		n -= 1
		i += 1

	
	temp = pontos[j]
	pontos[j] = pontos[0]
	pontos[0] = temp
	pivo = pontos[0]
	
	#print pontos
	pontos = sorted(pontos[1:], cmp=compare)
	pontos.insert(0, pivo)

	print pontos

	s = []
	s.append(pontos[-1])
	s.append(pontos[0])
	s.append(pontos[1])
	
	i = 2
	while i < N:
		j = len(s)-1

		if ccw(s[j-1], s[j], pontos[i]) or colinear(s[j-1], s[j], pontos[i]):
			s.append(pontos[i])
			i += 1
		else:
			s.pop()


	print s

	print len(pontos)-len(s)




	

