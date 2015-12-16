import numpy as np
import scipy.io, math, sys, time
from matplotlib import pyplot
from random import randint, random

from utils import Utils
from statistics import Statistics
from features import Features
from reader import Reader
from plots import Plots

from keras.datasets import cifar10, mnist
from pprint import pprint

np.random.seed(42)  # for reproducibility



class Pairwise:
	"""
	Simple Pairwise clustering
	"""

	def __init__(self, X, nb_cluster, dissimilarity_type=3, threshold=0.5):

		self.X = X
		self.nb_elements = X.shape[0]
		self.nb_cluster = nb_cluster
		self.threshold = threshold
		self.population = None
		self.idx = None

		print("nb_samples: %d" % self.nb_elements)
		print("nb_cluster: %d" % self.nb_cluster)

		self.dissimilarity = np.zeros((self.nb_elements, self.nb_elements))
		for i in range(self.nb_elements):
			for j in range(self.nb_elements):
				self.dissimilarity[i][j] = self.distance(X[i], X[j], d=dissimilarity_type)
				self.dissimilarity[j][i] = self.dissimilarity[i][j]

	def distance(self, a, b, d=2):
		if d <= 2:
			return np.nan_to_num(np.power(np.sum(np.power(a-b, d)), 1/d))
		return np.nan_to_num(self.kullback_leibler(a, b))

	def kullback_leibler(self, p, q):
		return np.sum(np.where(p != 0, (p) * np.log10(p / q), 0))

	def generate_population(self, count):
		self.population = np.zeros((count, self.nb_elements, self.nb_cluster))
		for i in range(count):
			indixes = np.random.randint(0, self.nb_cluster, (self.nb_elements,))
			membership = np.zeros((self.nb_cluster, self.nb_elements))
			membership[indixes, np.arange(self.nb_elements)] = 1 
			self.population[i] = membership.T

	def fitness(self, M):
		# FIXME: vectorize this!
		N, K, D = self.nb_elements, self.nb_cluster, self.dissimilarity
		total = 0
		for v in range(K):
			s, s2 = 0, 0
			for k in range(N):
				for t in range(N):
					s += M[k, v]*M[t, v]*D[k, t]
				s2 += M[k, v]
			total += s/(2*s2*N)
		return total

	def grade(self, P):
		return np.array(list(map(self.fitness, P)))

	def evolve(self, population, retain=0.5, random_select=0.05, mutate=0.01):
		graded = self.grade(population)
		graded_indexes = np.argsort(graded)
		graded_population = np.array([population[i] for i in graded_indexes])

		retain_length = int(len(graded_population)*retain)
		parents = list(graded_population[:retain_length])

		# randomly add other individuals to promote genetic diversity
		r = random_select > np.random.random(graded_population.shape[0])
		parents.extend(graded_population[r])

		# mutate some individuals
		for individual in parents:
			if mutate > np.random.random():
				pos_to_mutate = np.random.randint(0, len(individual))
				individual[pos_to_mutate] = np.random.randint(0, self.nb_cluster)

		# crossover parents to create children
		parents_length = len(parents)
		desired_length = len(population) - parents_length
		children = []
		while len(children) < desired_length:
			male, female = np.random.randint(0, len(parents), (2, ))
			if male != female:
				male, female, child = parents[male], parents[female], []
				child.extend(male[:len(male)//2])
				child.extend(female[len(male)//2:])
				children.append(child)

		parents.extend(np.array(children))
		return np.array(parents)
	
	def clusterize(self, nb_steps=100, nb_population=10):
		self.generate_population(nb_population)
		for i in range(nb_steps):
			self.population = self.evolve(self.population)
			self.idx = np.argmax(self.population[0], axis=1)



if __name__ == '__main__':

	(X_train, _), (X_test, _) = mnist.load_data()
	X_train = X_train.astype("float32")
	X_test = X_test.astype("float32")
	X_train = 1 + X_train/255
	X_test = 1 + X_test/255

	model = TSNE(n_components=2, random_state=0)
    tag_vectors = model.fit_transform(embeddings)
    x, y = tag_vectors[:, 0], tag_vectors[:, 1]

	X = X_test[:10]
	K = 3

	pw = Pairwise(X, K, dissimilarity_type=3)
	pw.clusterize(nb_steps=100)

	# PLOT
	for i in range(K):
		w = []
		for e in range(X.shape[0]):
			if pw.idx[e] == i:
				w.append(e)

		if len(w) > 0:
			a = len(w) // 2 
			fig, axs = pyplot.subplots(nrows=2, ncols=a+1, figsize=(3.2, 3.2))

			for k in range(2):
				for j in range(a+1):
					ax = axs[k, j]
					ax.axis('off')
					l = k*a + j
					if j == a and k == 0:
						continue
					if l < len(w):
						e = w[l]
						ax.set_title("K:%d | I:%d" % (i+1, e+1))
						# img = X[e].transpose(1,2,0)
						img = X[e]
						ax.imshow(img)
			pyplot.show()
