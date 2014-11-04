import math

class PilingRectsDiv2:

	def area(self, width, height):
		return width*height

	def getmax(self, X, Y, limit):

		rects = zip(X, Y)
		rects = sorted(rects, key = lambda x:x[0])

		maxInters = 0
		tam = len(rects)

		for i in range(tam):
			
			x, y = rects[i]
			if self.area(x, y) >= limit:
				
				count = 0
				for j in range(i+1, tam):
					
					xx = min(rects[j][0], x)
					yy = min(rects[j][1], y)

					if self.area(xx, yy) >= limit:
						count += 1
						x, y = xx, yy

			maxInters = max(maxInters, count)

		if maxInters == 0:
			return -1
		return maxInters


pr = PilingRectsDiv2()