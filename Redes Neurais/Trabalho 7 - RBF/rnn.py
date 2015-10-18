import numpy as np
import scipy.io, math, sys, time
from matplotlib import pyplot
from scipy import *
from scipy.linalg import norm, pinv
from kmeans import KMeans


# Utils:
def load_mat(filename):
	return scipy.io.loadmat('dados/'+filename)


def save_mat(filename, mat):
	scipy.io.savemat('dados/'+filename, mat)


def read_data(file_name, ignore_line_number=True):
	X, Y = [], []
	i = int(ignore_line_number)

	with open(file_name, 'r') as f:
		for line in f:
			temp = list(map(float, line.strip().split()))[i:]
			X.append(temp[:-1])
			Y.append(temp[-1]) 

	y = np.array(Y).reshape(len(Y), 1)
	return (np.matrix(X), y)


def get_epsilon(l_in, l_out):
	return math.sqrt(6)/math.sqrt(l_in + l_out)


def add_column_with_ones(X):
	return np.c_[np.ones(len(X)), X]




class RBFNetwork:
	"""
	Simple Radial Basis Function with 1 hidden layer
	"""


	def __init__(self, nb_input, nb_hidden, nb_output):
		"""
		:param nb_input: number of input neurons
		:param nb_hidden: number of hidden neurons
		:param nb_output: number of output neurons
		"""

		self.nb_input = nb_input
		self.nb_hidden = nb_hidden
		self.nb_output = nb_output

		# Weights:
		self.weights = [0, 0]
		self.idx = None
		self.var = None

		# centroids for hidden layer 
		self.weights[0] = np.zeros((self.nb_hidden, 1))

		# matrix for output layer
		self.weights[1] = np.zeros((self.nb_output, self.nb_hidden+1))

		self.initialize_weights()



	def initialize_weights(self):
		nb_in, nb_out = self.weights[1].shape
		epsilon = get_epsilon(nb_in, nb_out-1)
		self.weights[1] = np.random.randn(nb_in, nb_out) * 2 * epsilon - epsilon


	def gaussian(self, c, d, beta):
		return np.exp(-beta * norm(c-d) ** 2)


	def predict(self, X, beta):

		m, n = X.shape
		betas = np.ones((self.nb_hidden, 1)) * beta
		y = np.zeros(m)

		for i in range(m):
			sample = X[i, :]
			A = self.get_activation(sample, betas).T
			A = add_column_with_ones(A / np.sum(A))
			y[i] = A.dot(self.weights[1])
			# print(a.shape)

		return y


	def get_activation(self, sample, betas):
		diff = self.weights[0] - sample
		dist = np.sum(np.power(diff, 2), axis=1).reshape(self.nb_hidden, 1)
		return np.exp(np.multiply(-betas,  dist))



	def train(self, X, Y, beta):

		m, n = X.shape
		k = self.nb_hidden

		km = KMeans(k)
		km.train(X)
		
		self.weights[0] = km.get_centroids()
		self.idx = km.get_idx()

		betas = np.ones((k, 1)) * beta

		A = np.zeros((m, k))
		for i in range(m):
			sample = X[i, :]
			A[i] = self.get_activation(sample, betas).T

		s = np.sum(A, axis=1).reshape(m, 1)
		A = add_column_with_ones(np.divide(A, s))
		a = pinv(A.T.dot(A))
		b = A.T.dot(Y)
		self.weights[1] = a.dot(b) 






if __name__ == '__main__':


	X, Y = read_data('dados/dados.txt', ignore_line_number=True)
	X_test, Y_test = read_data('dados/testes.txt', ignore_line_number=True)

	m, n = X.shape
	sigma = 10
	beta = 1.0 / (2 * sigma**2)
	neurons = 5

	rbf = RBFNetwork(n, neurons, 1)
	rbf.train(X, Y, beta)
	z = rbf.predict(X_test, beta)


	# pyplot.plot(x, y_orig, 'bx', alpha=0.75)
	# pyplot.plot(x, y, 'y-')

	# pyplot.plot(x, z, 'r-')

	# pyplot.plot(rbf.weights[0], zeros(neurons), 'gs')

	
	# kernels = np.zeros((neurons+1, n))
	# betas = np.ones((neurons, 1)) * beta

	# for i in range(n):
	# 	a = add_column_with_ones(rbf.get_activation(x[i], betas).T).T * rbf.weights[1]
	# 	kernels[:, i] = a.flatten()

	# for i in range(neurons):
	# 	pyplot.plot(x, kernels[i,:], '-', color='gray', alpha=0.5)

	# pyplot.show()

