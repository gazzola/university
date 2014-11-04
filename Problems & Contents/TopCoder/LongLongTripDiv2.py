import math

class LongLongTripDiv2:
	def isAble(self, D, T, B):

		jump = 0
		for i in xrange(T + 1):
			if D == i * B + (T - i):
				return "Possible"
			jump += 1
		return "Impossible"


llt = LongLongTripDiv2()
print(llt.isAble(10, 6, 3))
print(llt.isAble(10, 5, 3))
print(llt.isAble(50, 100, 2))
print(llt.isAble(120, 10, 11))
print(llt.isAble(10, 10, 9999))
print(llt.isAble(1000, 100, 10))
print(llt.isAble(1000010000100001, 1100011, 1000000000))