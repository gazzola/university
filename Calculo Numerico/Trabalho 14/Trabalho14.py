import math


def print_res(res):
	for x, y in res:
		print("y(%.2f) = %.4f" % (x, y))


def eq(x, y):
	return x - y + 2

def next_y(x, y, h):
	return y + h*eq(x, y)


def euler(x0, xn, y0, h):

	y = []
	y.append((x0, y0))

	x = x0+h
	while x <= xn+h:
		y.append((x, next_y(x, y[-1][1], h)))
		x += h 

	return y


result = euler(0, 1, 2, 0.01)
print_res(result)
