import math


def print_res(res):
	for x, y in res:
		print("y(%.2f) = %.4f" % (x, y))


def eq(x, y):
	return 2*x*y

def next_y(x, y, h):


	incog = [0 for i in range(4)]

	incog[0] = h*eq(x, y)

	x_aux = x + 0.5*h
	y_aux = y + 0.5*incog[0]
	incog[1] = h*eq(x_aux, y_aux)

	x_aux = x + 0.5*h
	y_aux = y + 0.5*incog[1]
	incog[2] = h*eq(x_aux, y_aux)

	x_aux = x + h
	y_aux = y + incog[2]
	incog[3] = h*eq(x_aux, y_aux)

	total = incog[0]+2*incog[1]+2*incog[2]+incog[3]
	return y + (1/6.0)*total


def runge_kutta(x0, xn, y0, h):

	y = []
	y.append((x0, y0))

	x = x0+h
	while x <= xn+h:
		y.append((x, next_y(y[-1][0], y[-1][1], h)))
		x += h 

	return y


result = runge_kutta(1, 1.5, 1, 0.1)
print_res(result)
