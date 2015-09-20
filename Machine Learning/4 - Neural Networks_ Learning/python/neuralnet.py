import numpy as np
from matplotlib import pyplot
from random import random

def load(fname):

	dirname = 'dados/'
	X, Y = [], []

	with open(dirname+fname, 'r') as f:
		for line in f:
			temp = map(float, line.strip().split())[1:]
			X.append(temp[:-1])
			Y.append(temp[-1])


	X = np.matrix(X)
	Y = np.matrix(Y).T
	return (X, Y)



def scatterplot(x,y):
    pyplot.plot(x,y,'b.')
    pyplot.xlim(min(x)-1,max(x)+1)
    pyplot.ylim(min(y)-1,max(y)+1)
    pyplot.show()


def feature_normalize(X):
	mu = np.mean(X)
	sigma = np.std(X)
	X = (X - mu) / sigma
	return X, mu, sigma



def get_feature(x, mu, sigma):
	return (x-mu)/sigma



def cost(X, Y, theta):

	for k in range(len(Y[0])):
		Y[:,k] = ()		




def predict(x, theta, mu, sigma):
	x = get_feature(x, mu, sigma)
	return x.dot(theta)



def forward(X, theta1, theta2):

	m = len(X)

	z2 = X.dot(theta1.T)
	a2 = np.c_[np.ones(m), np.tanh(z2)]

	z3 = a2.dot(theta2.T)
	a3 = np.tanh(z3)




def gradient_descent(X ,Y, theta, alpha, num_iters):

	m = len(Y)
	n = len(theta)
	J_history = []


	for i in xrange(num_iters):

		# s = [0]*n
		# for k in xrange(m):
		# 	for l in xrange(n):
		# 		h = predict(X[k], theta, 0, 1)
		# 		s[l] += (h - Y[k])* X[k,l]

		# for k in range(n):
		# 	theta[k,0] -= (alpha*s[k])/m


		# with vectorization:
		A = np.dot(X.T, np.dot(X, theta) - Y)
		theta = theta - (alpha*A)/m


		J_history.append(cost(X, Y, theta)[0,0])

	return theta, J_history




def normal_equation(X, Y):

	A = X.T.dot(X)
	B = np.linalg.pinv(A)
	C = X.T.dot(Y)
	return B.dot(C)





if __name__ == '__main__':

	X, Y = load('x01.txt')
	n = X.shape[1]+1
	m = len(Y) 

	# plot dataset only if is 2D
	if n == 2:
		pyplot.xlabel('brain weight')
		pyplot.ylabel('body weight')
		pyplot.title('Data of Brain x Body Weight')
		scatterplot(X, Y)


	# feature normalization speed up the gradient descent convergence  
	mu,sigma = 0, 1
	# X, mu, sigma = feature_normalize(X)
	theta = np.zeros((n, 1))
	num_iters = 150
	alpha = 0.0000001


	m = len()

	# add 1 column to x
	X = np.c_[np.ones(len(X)), X]
	

	# find theta that minimizes cost(X,Y)
	theta1, J_history = gradient_descent(X, Y, theta, alpha, num_iters)
	
	
	# plot J_history, the graph should be decrescent over iterations
	pyplot.xlabel('iterations')
	pyplot.ylabel('J(theta)')
	pyplot.title('Cost function over iterations')
	scatterplot(range(num_iters), J_history)
	

	
	# another way to calculate theta is using normal equation
	# theta2 = normal_equation(X, Y)


	# print predictions for some value
	x_new = np.random.random(n)
	print "\nPredict for "+str(x_new)+":", predict(x_new, theta1, mu, sigma)
	print "\nPredict for "+str(x_new)+":", predict(x_new, theta2, mu, sigma)

	print ""
	
	# print theta's values
	print "Theta with Gradient Desc.:", theta1.T
	print "Theta with Normal Eq.", theta2.T

	
	# plot a line that generalize the dataset only if is 2D
	if n == 2:
		minX, maxX = X.min(), X.max()
		minY, maxY = Y.min(), Y.max()
		xx = np.arange(minX-1, maxX+1, 0.1)
		
		yy = np.zeros(len(xx))
		for i in range(len(xx)):
			# try change for theta2, just for fun :-)
			yy[i] = predict(np.c_[1, xx[i]], theta1, 0, 1)


		pyplot.plot(X[:,1], Y, 'b.')
		pyplot.plot(xx, yy, 'r')
		pyplot.xlim(minX-1, maxX+1)
		pyplot.ylim(minY-1, maxY+1)

		pyplot.show()



