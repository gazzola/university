import numpy as np
from matplotlib import pyplot
from random import random

def load(fname, ignore_line_number=True):

	dirname = 'dados/'
	X, Y = [], []
	i = int(ignore_line_number)

	with open(dirname+fname, 'r') as f:
		for line in f:
			temp = map(float, line.strip().split())[i:]
			X.append(temp[:-1])
			Y.append(temp[-1])


	X = np.matrix(X)
	Y = np.matrix(Y).T
	return (X, Y)


def scatterplot(x, y):
	t = np.squeeze(np.asarray(y))
	pos = t == 1
	neg = t == 0
	pyplot.plot(x[pos,0], x[pos,1], 'b.', label='y = 1')
	pyplot.plot(x[neg,0], x[neg,1], 'r+', label='y = 0')
	pyplot.legend(loc='upper right', numpoints=1)


def lineplot(x, y):
	pyplot.plot(x, y, 'b-')
	pyplot.xlim(min(x)-1,max(x)+1)
	pyplot.ylim(min(y)-1,max(y)+1)
	pyplot.show()




def feature_normalize(X):

	mu = np.zeros(X.shape[1])
	sigma = np.zeros(X.shape[1])

	for i in range(X.shape[1]):
		F = X[:,i]
		mu = np.mean(F)
		sigma = np.std(F)
		X[:,i] = (F - mu) / sigma

	return X, mu, sigma



def get_feature(x, mu, sigma):
	return (x-mu)/sigma



def sigmoid(X):
	return 1.0 / (1.0 + np.exp(-X))



def map_features(x, degree=7):

	if degree > 0:
		n = (degree*(degree+1))/2
		v = np.matrix(np.zeros((x.shape[0], n-1)))
		x1 = x[:, 0]
		x2 = x[:, 1]
		k = 0

		for i in range(1, degree):
			for j in range(i+1):
				v[:, k] = np.multiply(np.power(x1, (i-j)), np.power(x2, j))
				k += 1

		return v
	return x



def predict(x, theta, mu=0, sigma=1):
	x = get_feature(x, mu, sigma)
	return sigmoid(x.dot(theta))




def cost(X, Y, theta, lbda=1):

	m, n = float(len(Y)), len(theta)
	Z = sigmoid(X.dot(theta))

	A = np.log(Z).T.dot(Y)
	B = np.log(1 - Z).T.dot(1 - Y)
	J = -(A+B)/m


	# regularization:
	J += (lbda * np.sum(np.power(theta[1:], 2)))/(2.0*m)

	grad = np.zeros((n, 1))


	grad[0] = X[:,0].T.dot(Z - Y)/m
	grad[1:] = (X[:, 1:].T.dot(Z - Y)/m) + (lbda*theta[1:])/m

	return J[0,0], grad





def gradient_descent(X ,Y, theta, alpha, lbda, num_iters):

	J_history = []

	for i in xrange(num_iters):

		# with vectorization:
		J, grad = cost(X, Y, theta, lbda)
		theta = theta - (alpha * grad)

		J_history.append(J)

		# print "Iteration %4d - Cost %.4f \r" % (i+1, J), 

	print ""
	return theta, J_history



def draw_boundary(X, theta, degree=1):

	if degree > 1:

		def map_f(x, y, degree=7):

			n = (degree*(degree+1))/2
			v = np.ones((x.shape[0], n))
			k = 1

			for i in range(1, degree):
				for j in range(i+1):
					v[:, k] = np.multiply(np.power(x, (i-j)), np.power(y, j))
					k += 1

			return v

		dim = np.linspace(min(X[:,0])[0,0], max(X[:,0])[0,0], 50)
		dx, dy = np.meshgrid(dim, dim)
		v = map_f(dx.flatten(), dy.flatten(), degree)
		z = (np.dot(v, theta)).reshape(50, 50)
		CS = pyplot.contour(dx, dy, z, levels=[0], colors=['g'])

	else:

		plot_x = [min(X[:,0])[0,0]-2,  max(X[:,0])[0,0]+2]

		plot_y = [0, 0]
		plot_y[0] = (-1/theta[2]) * (theta[1]*plot_x[0] + theta[0])
		plot_y[1] = (-1/theta[2]) * (theta[1]*plot_x[1] + theta[0])

		pyplot.plot(plot_x, plot_y, 'g-')
		pyplot.xlim(min(plot_x)+2, max(plot_x)-2)
		pyplot.ylim(min(X[:,1])[0,0], max(X[:,1])[0,0])



def one_vs_all(X, Y, num_labels, alpha, lbda, num_iters, plot_all=False):

	m, n = X.shape
	all_thetas = np.zeros((num_labels, n))
	ini_theta = np.zeros((n, 1))

	pyplot.xlabel('iterations')
	pyplot.ylabel('J(theta)')
	pyplot.title('Cost function over iterations')

	for i in range(num_labels):
		theta, j_hist = gradient_descent(X, Y == i, ini_theta, alpha, lbda, num_iters)
		all_thetas[i] = theta[:,0]
		
		if plot_all:
			lineplot(range(num_iters), j_hist)
		elif i == 0:
			lineplot(range(num_iters), j_hist)


	return all_thetas



def predict_one_vs_all(X, all_thetas):
	A = X.dot(all_thetas.T)
	return np.argmax(A, axis=1)


def load_mat(filename):
	import scipy.io
	dirname = 'dados/'
	return scipy.io.loadmat(dirname+filename)



if __name__ == '__main__':

	mat = load_mat('mnist.mat')
	X_orig, Y = np.matrix(mat['X']), mat['y']
	Y = Y - 1

	n = X_orig.shape[1]+1
	m = Y.shape[0]

	# mu,sigma = 0, 1
	# X_norm, mu, sigma = feature_normalize(X_orig)

	num_iters = 1000
	alpha = 3.0
	lbda = 0.1
	degree = 0
	num_labels = 10

	X = map_features(X_orig, degree)
	X = np.c_[np.ones(m), X_orig]
	theta = np.zeros((X.shape[1], 1))
	
	all_thetas = one_vs_all(X, Y, num_labels, alpha, lbda, num_iters)
	p = predict_one_vs_all(X, all_thetas)
	acc = np.mean(p == Y) * 100.0
	print "Accuracy:", acc


	



