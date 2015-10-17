import numpy as np
import scipy.io, math, sys, time
from matplotlib import pyplot

from utils import Utils
from statistics import Statistics
from features import Features
from reader import Reader
from plots import Plots



def plot_scatter(X, idx, K):
	colors = "gbrcmykw"
	for i in range(K):
		v = idx == i
		pyplot.plot(X[v,0], X[v,1], colors[i]+'x', alpha=0.5, label='k = %d' % i)



def plot_centroids(centroids, previous):
	colors = "gbrcmykw"
	for i in range(centroids.shape[0]):
		pyplot.plot(centroids[i,0], centroids[i,1], colors[i]+'o')


class KMeans:
	"""
	Simple K-means
	"""

	def __init__(self, nb_cluster):
		self.nb_cluster = nb_cluster
		self.centroids = np.zeros((nb_cluster, 1), dtype=np.float64)
		self.previous_centroids = np.zeros((nb_cluster, 1))
		self.idx = None


	def initialize_centroids(self, X):
		self.centroids = np.random.permutation(X)[:self.nb_cluster]


	def find_closest_centroids(self, X):
		for i in range(X.shape[0]):
			y_star = float("inf")
			for k in range(self.nb_cluster):
				y = np.linalg.norm(X[i] - self.centroids[k])
				if y < y_star:
					y_star, self.idx[i] = y, k


	def compute_centroids(self, X):
		for i in range(self.nb_cluster):
			v = np.array(self.idx == i)
			self.centroids[i] = np.sum(X[v], axis=0) / np.sum(v)


	def train(self, X, nb_iters=10, verbose=True):
		
		m, n = X.shape
		self.initialize_centroids(X)
		self.idx = np.zeros(m)
		self.previous_centroids = self.centroids



		for i in range(nb_iters):

			sys.stdout.write("Iter: %6d of %d\r" % (i+1, nb_iters))
			sys.stdout.flush()

			self.find_closest_centroids(X)
			self.compute_centroids(X)

			if verbose:
				plot_centroids(self.centroids, self.previous_centroids)
				self.previous_centroids = self.centroids

		plot_scatter(X, self.idx, self.nb_cluster)
		pyplot.legend(loc='upper right', numpoints=1)
		pyplot.show()

		print("\n")



if __name__ == '__main__':


	# x,y = Reader.read_data('dados/data.dat', False)
	# X = np.hstack((x,y))
	# mat = {'X':X}
	# Reader.save_mat('dados/data.mat', mat)

	mat = Reader.load_mat('dados/data.mat')
	X = np.matrix(mat['X'])
	K = 3

	km = KMeans(K)
	km.train(X)

