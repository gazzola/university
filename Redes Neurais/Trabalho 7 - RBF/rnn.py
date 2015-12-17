# run: python3 rnn.py
# ---
# dependencies: 
# sudo pip3 install numpy, scipy, matplotlib
# or
# sudo apt-get install python3-numpy, python3-scipy, python3-matplotlib

import numpy as np
from matplotlib import pyplot
from scipy.linalg import norm, pinv
import math
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

def gaussian(self, c, d, beta):
	return np.exp(-beta * norm(c-d) ** 2)

def reached_precision(cost, precision):
	if len(cost) < 2:
		return False
	return abs(cost[-1] - cost[-2]) < precision


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
		# see: xavier initialization (Glorot, Bengio. 2010)
		nb_in, nb_out = self.weights[1].shape
		epsilon = get_epsilon(nb_in, nb_out-1)
		self.weights[1] = np.random.randn(nb_in, nb_out) * 2 * epsilon - epsilon


	def predict(self, X, beta, normalize=False):
		# TODO: vectorize this
		(m, n), k = X.shape, self.nb_hidden

		# activation in a pythonic way
		A = np.array([np.exp(-beta * np.sum(np.power(self.weights[0] - x, 2), axis=1)) for x in X]).reshape(m, k)

		# feature scaling
		if normalize:
			A = A / np.sum(A, axis=1)[:,None]

		# for bias
		A = add_column_with_ones(A)

		# return the predicted values
		return A.dot(self.weights[1].T)


	def get_activation(self, sample, betas):
		diff = self.weights[0] - sample
		dist = np.sum(np.power(diff, 2), axis=1).reshape(self.nb_hidden, 1)
		return np.exp(np.multiply(-betas,  dist))


	def gradient_descent(self, X, Y, beta, alpha):
		# for a better reading
		old_gradients = self.weights[1]

		# evaluate the prediction
		A = X.T.dot(X.dot(old_gradients.T) - Y)

		# return the new gradients
		new_gradients = old_gradients.T - (alpha*A) / Y.shape[0]

		return new_gradients.T


	def train(self, X, Y, beta, nb_epochs=5, normalize=False, gradients=True, alpha=1e-3):
		
		# m = nb_examples
		# n = nb_features
		# k = nb_hidden (nb of neurons in hidden layer)
		(m, n), k = X.shape, self.nb_hidden

		# K-Means for input layer:
		self.km = KMeans(nb_cluster=k)

		# select k centroids from training set:
		self.km.train(X, nb_iters=100, init_from_train=True)
		
		# set the centroids as ours weights from of the layer:
		self.weights[0] = self.km.get_centroids()


		# calcule the activation of rbf:
		# in pythonic way:
		A = np.array([np.exp(-beta * np.sum(np.power(self.weights[0] - x, 2), axis=1)) for x in X]).reshape(m, k)
		
		# in noob way:
		# A, betas = np.zeros((m, k)), np.ones((k, 1)) * beta
		# for i in range(m):
		# 	A[i] = self.get_activation(X[i, :], betas).T

		# speed up the convergence and its necessary 
		# for pseudo-inverse method
		if normalize:
			# divide each row by its sum
			A = A / np.sum(A, axis=1)[:,None]

		# for bias
		A = add_column_with_ones(A)
		
		if gradients:
			errors = []
			while not reached_precision(errors, precision=1e-7):
				# the same process as used in linear regression, i.e.
				# use the gradient descent for minimize the loss function
				self.weights[1] = self.gradient_descent(A, Y, beta, alpha)

				# calculate the errors with the trained weights:
				errors.append(np.sum(np.power(self.predict(X, beta, normalize=normalize) - Y, 2)) / m)
		else:
			# learn the weights using pseudo-inverse function:
			self.weights[1] = pinv(A.T.dot(A)).dot(A.T.dot(Y))
		
			# calculate the errors with the trained weights:
			errors = [0, np.sum(np.power(self.predict(X, beta, normalize=normalize) - Y, 2)) / m]

		return errors






if __name__ == '__main__':

	X, Y = read_data('dados/dados.txt', ignore_line_number=True)
	X_test, Y_test = read_data('dados/testes.txt', ignore_line_number=True)

	# m = nb_examples
	# n = nb_features
	m, n = X.shape

	# neurons for the input layer
	nb_input = n

	# one output because we are trying to approximate a function
	nb_output = 1

	# set the sigma for the gaussian length
	sigma = 10
	beta = 1.0 / (2 * sigma**2)
	normalize = False

	# hyperparameters for this homework
	nb_trains = 3
	hidden_units = [5, 10, 15]
	plot_errors = True


	for r, nb_hidden in enumerate(hidden_units):
		for e in range(nb_trains):
			# new model
			rbf = RBFNetwork(nb_input, nb_hidden, nb_output)

			# train the given model and get the errors with the 
			# specified beta calculated from sigma
			errors = rbf.train(X, Y, beta, normalize=normalize)

			print('Network %d - T%d:' % (r+1, e+1,))
			print('Last error: %.12f' % abs(errors[-1] - errors[-2]))
			print('Epochs: %d' % len(errors))

			if plot_errors:
				pyplot.plot(list(range(len(errors))), errors)
				pyplot.show()

			# predict new values with beta
			y_test_hat = rbf.predict(X_test, beta, normalize=normalize)
			print('Predictions: ')
			print(y_test_hat)
			print('---')


	# if the data is 2d, then we can print the gaussian using:

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

