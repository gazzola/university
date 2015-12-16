import numpy as np
import scipy.io, math, sys, time
from matplotlib import pyplot



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

	def __init__(self, nb_cluster=3):
		self.nb_cluster = nb_cluster
		self.centroids = np.zeros((nb_cluster, 1), dtype=np.float64)
		self.previous_centroids = np.zeros((nb_cluster, 1))
		self.idx = None


	def initialize_centroids(self, X, init_from_train=False):
		if init_from_train:
			self.centroids = np.random.permutation(X)[:self.nb_cluster]
		else:
			self.centroids = np.random.randn(self.nb_cluster, X.shape[1])

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


	def get_centroids(self):
		return self.centroids


	def get_idx(self):
		return self.idx


	def norm(self, A):
		return np.sum(np.power(A, 2))


	def variance_vector(self, X):
		var = np.zeros(self.nb_cluster)
		for k in range(self.nb_cluster):
			v = np.array(self.idx == k)
			var[k] = np.sum(self.norm(X[v] - self.centroids[k])) / float(np.sum(v))
		return var


	def train(self, X, nb_iters=100, verbose=False, init_from_train=False):
		
		m, n = X.shape
		self.initialize_centroids(X, init_from_train=init_from_train)
		self.idx = np.zeros(m)
		self.previous_idx = np.ones(m)
		self.previous_centroids = self.centroids
		i = 0

		while i < nb_iters and np.sum(self.idx == self.previous_idx) < m:

			self.find_closest_centroids(X)
			self.compute_centroids(X)

			if verbose:

				sys.stdout.write("Iter: %6d of %d\r" % (i+1, nb_iters))
				sys.stdout.flush()

				plot_centroids(self.centroids, self.previous_centroids)
				self.previous_centroids = self.centroids

			i += 1

		if verbose:
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

