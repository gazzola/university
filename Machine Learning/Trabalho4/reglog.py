import numpy as np
import scipy.io, math, sys, time
from matplotlib import pyplot

from utils import Utils
from statistics import Statistics
from features import Features
from reader import Reader
from plots import Plots



class LogisticRegression:
	"""
	Simple Logistic Regression with OneVsAll methods
	"""

	def __init__(self, nb_input, nb_output, nb_features):
		"""
		:param nb_input: number of input samples
		:param nb_output: number of classes
		:param nb_features: number of features
		"""

		self.nb_input = nb_input
		self.nb_output = nb_output
		self.nb_features = nb_features

		# Weights:
		self.weights = np.zeros((nb_features, 1))
		self.all_weights = np.zeros((nb_output, nb_features))

		# Gradients:
		self.gradients = np.zeros((nb_features, 1))



	def initialize_weights(self):
		epsilon = Utils.get_epsilon(self.nb_features, 1)
		self.weights = np.random.randn(self.nb_features, 1) * 2 * epsilon - epsilon


	def set_weights(self, w):
		self.weights = w


	def get_weights(self):
		return self.weights


	def predict_classes(self, X):
		return np.argmax(X.dot(self.all_weights.T), axis=1)

	
	def predict_binary(self, X):
		return Utils.sigmoid(X.dot(self.weights)) >= Utils.sigmoid(0)


	def predict(self, X):
		if self.nb_output > 2:
			return self.predict_classes(X_norm)
		else:
			return self.predict_binary(X_norm)


	def cost(self, X, Y, lbda):


		m, n = X.shape
		
		Z = Utils.sigmoid(X.dot(self.weights))
		
		A = np.log(Z).T.dot(Y)
		B = np.log(1 - Z).T.dot(1 - Y)
		J = -(A+B)/m


		# regularization (not for bias):
		J += (lbda * np.sum(np.power(self.weights[1:], 2)))/(2.0*m)

		
		# get gradients
		grad = np.zeros(self.weights.shape)
		grad[0]  = X[:,0].T.dot(Z - Y)/m
		grad[1:] = (X[:, 1:].T.dot(Z - Y)/m) + (lbda*self.weights[1:])/m

		return np.sum(J), grad


	def update_weights(self, grad, alpha):
		self.weights = self.weights - alpha*grad



	
	def train_binary(self, X, Y, alpha, lbda, precision, nb_iters, verbose=True):

		def reached_precision(cost, precision):
			if len(cost) < 2:
				return True
			return abs(cost[-1] - cost[-2]) > precision

		cost_history = []
		i = 0



		while i < nb_iters and reached_precision(cost_history, precision):
			J, G = self.cost(X, Y, lbda)
			self.update_weights(G, alpha)
			cost_history.append(J)

			if verbose:
				sys.stdout.write("Iteration %4d - Cost %.4f \r" % (i+1, J))
				sys.stdout.flush()

			i += 1

		if verbose:
			print("\n"+"-"*30)
		return cost_history


	def train_classes(self, X, Y, alpha, lbda, precision, nb_iters, verbose=True):

		m, n = X.shape
		cost_history = []

		for k in range(self.nb_output):

			self.initialize_weights()
			J = self.train_binary(X, Y == k, alpha, lbda, precision, nb_iters, verbose)

			self.all_weights[k] = self.weights[:,0]
			cost_history.append(J)
			

		return cost_history


	def train(self, X, Y, alpha=0.3, lbda=0.5, precision=1e-6, nb_iters=10000, verbose=True):
		if self.nb_output > 2:
			return self.train_classes(X, Y, alpha, lbda, precision, nb_iters, verbose)
		else:
			return self.train_binary(X, Y, alpha, lbda, precision, nb_iters, verbose)



if __name__ == '__main__':


	# X, Y = Reader.read_data('dados/xor.txt', ignore_line_number=False)

	# data = {'X':X, 'Y':Y}
	# Reader.save_mat('dados/xor.mat', data)

	mat = Reader.load_mat('dados/xor.mat')
	X_orig, Y = np.matrix(mat['X']), mat['Y']

	# X, mu, sigma = Features.normalize(X)
	Plots.scatterplot(X_orig, Y)
	pyplot.show()

	max_degree = 60
	iters, times, accs, alphas = [], [], [], []


	result_times = open("reg_result_times.txt", "w")
	result_times.write("alpha tempo\n")

	result_iters = open("reg_result_iters.txt", "w")
	result_iters.write("alpha iters\n")

	result_accs = open("reg_result_accs.txt", "w")
	result_accs.write("alpha acc\n")

	result_alphas = open("reg_result_alphas.txt", "w")
	result_alphas.write("alpha custo\n")

	lalphas = [0.01, 0.03, 0.1, 0.3, 1.0, 3.0, 6.0, 12.0, 24.0, 48.0]

	for nb_degree in range(1, max_degree+1):
		for k, alpha in enumerate(lalphas):

			X = Utils.add_column_with_ones(Features.map(X_orig, degree=nb_degree))

			validation_split = 0.2
			use_shuffle = False
			use_validation = False

			nb_input  = X.shape[0]
			nb_features = X.shape[1]
			nb_labels = len(set(np.squeeze(np.asarray(Y))))

			nb_iters  = 50000
			nb_epochs = 1

			# alpha	  = 3.0
			lbda	  = 0.0
			momentum  = 0.9
			precision = 1e-6

			timer 	  = time.clock if (sys.platform == 'win32') else time.time



			lg = LogisticRegression(nb_input, nb_labels, nb_features)

			a,b,c,d = [],[],[],[]
			for i in range(nb_epochs):
				

				# print('Epoch %d' % (i+1))
				# print("-"*30)

				sys.stdout.write("Degree %2d - Alpha %2.2lf - Epoch %2d \r" % (nb_degree, alpha, i+1))
				sys.stdout.flush()

				start_time = timer()
				lg.initialize_weights()
				j_history = lg.train(X, Y, alpha, lbda, precision, nb_iters, verbose=False)	
				total_time = timer() - start_time
				
				a.append(len(j_history))
				b.append(total_time)
				c.append(Statistics.accuracy(lg.predict_binary(X), Y))
				d = j_history

				# print('Iterations:\t %d' % a[-1])
				# print('Time:\t\t %.2f seconds' % b[-1])
				# print('Accuracy:\t %.2f' %  c[-1])

				# f1, precision, recall, acc = Statistics.f_score(lg.predict_binary(X), Y)
				# print('F1:\t %.2f' % f1)
				# print('Prec:\t %.2f' % precision)
				# print('Rec:\t %.2f' % recall)
				# print('Acc:\t %.2f' % acc)

				# print('\n')

				# if nb_degree == 2:
				# 	colors = "gbrcmyk"*2
				# 	Plots.lineplot(list(range(len(d))), d, color=colors[k], label='Alpha {}'.format(alpha))
				# Plots.draw_boundary(X[:, 1:], lg.get_weights(), degree=nb_degree)

			ma, da = np.mean(np.array(a)), np.std(np.array(a))
			mb, db = np.mean(np.array(b)), np.std(np.array(b))
			mc, dc = np.mean(np.array(c)), np.std(np.array(c))
			md, dd = np.mean(np.array(d)), np.std(np.array(d))

			iters.append(ma)
			times.append(mb)
			accs.append(mc)
			alphas.append(md)

			result_iters.write("%.2f %.4f\n" % (alpha, ma))
			result_times.write("%.2f %.4f\n" % (alpha, mb))
			result_accs.write("%.2f %.4f\n" % (alpha, mc))
			result_alphas.write("%.2f %.4f\n" % (alpha, md))



			print('Degree %d - %d' % (nb_degree, nb_features))
			print("-"*30)
			print('Iterations:\t media:%.2lf \t desvio:%.2f' % (ma, da))
			print('Time:\t\t media:%.2lf \t desvio:%.2f seconds' % (mb, db))
			print('Accuracy:\t media:%.2lf \t desvio:%.2f' % (mc, dc))
			print('\n')


	pyplot.legend(loc='upper right', numpoints=1, shadow=True, fancybox=True)
	pyplot.show()

	pyplot.xlabel('Taxa de aprendizagem')
	pyplot.ylabel('J(W)')
	Plots.lineplot(lalphas, alphas, color='g', label='Custo')
	pyplot.legend(loc='upper right', numpoints=1, shadow=True, fancybox=True)
	pyplot.show()

	Plots.lineplot(lalphas, times, color='g', label='Times')
	pyplot.legend(loc='upper right', numpoints=1, shadow=True, fancybox=True)
	pyplot.show()

	Plots.lineplot(lalphas, iters, color='b', label='Iterations')
	pyplot.legend(loc='upper right', numpoints=1, shadow=True, fancybox=True)
	pyplot.show()
	

