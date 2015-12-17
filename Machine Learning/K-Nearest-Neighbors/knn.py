import numpy as np
import scipy.io, math, sys, time
from matplotlib import pyplot

from utils import Utils
from statistics import Statistics
from features import Features
from reader import Reader
from plots import Plots

from keras.datasets import cifar10


# http://machinelearningmastery.com/tutorial-to-implement-k-nearest-neighbors-in-python-from-scratch/

class KNN:
	"""
	Simple K-Nearest Neighbors
	"""

	def __init__(self, nb_cluster):
		self.nb_cluster = nb_cluster


	def find_neighbors(self, X, Z):
		distances = Utils.euclidian_distance(X, Z)
		neighbors = np.argsort(distances, axis=0)
		return neighbors[:self.nb_cluster]
		# return X[neighbors][:self.nb_cluster].flatten()


	def compute_response(self, X):
		votes = np.zeros(np.max(X)+1)
		for x in X:
			votes[x] += 1
		return np.argmax(votes)


	def get_class(self, major, Y):
		return Y[major]


	def train(self, X, Y1, Z, Y2, verbose=True):
		
		m, n = Z.shape
		predictions = np.zeros(m)

		for i in range(m):

			sys.stdout.write("Iter: %6d of %d\r" % (i+1, m))
			sys.stdout.flush()

			neighbors = self.find_neighbors(X, Z[i])
			major = self.compute_response(neighbors)
			predictions[i] = self.get_class(major, Y1)

		# calculate accuracy with predictions and Y2

		print("\n")



if __name__ == '__main__':


	# x,y = Reader.read_data('dados/data.dat', False)
	# X = np.hstack((x,y))
	# mat = {'X':X}
	# Reader.save_mat('dados/data.mat', mat)

	# mat = Reader.load_mat('dados/data.mat')
	# X = np.matrix(mat['X'])

	K = 10
	knn = KNN(K)


	X = np.random.rand(200, 2)
	Z = np.random.rand(1, 2) # query
	neighbors = knn.find_neighbors(X, Z)

	pyplot.plot(X[:,0], X[:,1], 'bo')
	pyplot.plot(Z[:,0], Z[:,1], 'ro')


	N = X[neighbors]
	pyplot.plot(N[:,0], N[:,1], 'o', markeredgecolor='r', markerfacecolor='None', markersize=15, markeredgewidth=1)

	pyplot.show()

	# km.train(X)
