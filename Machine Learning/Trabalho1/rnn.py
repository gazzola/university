import numpy as np
import pylab as pl
import scipy.io, math, sys, time
from matplotlib import pyplot
from scipy import optimize


from utils import Utils
from statistics import Statistics
from features import Features
from reader import Reader
from plots import Plots




class NeuralNetwork:
	"""
	Simple Multi Layer Perceptron with 1 hidden layer
	"""


	def __init__(self, nb_input, nb_hidden, nb_output, cost_function='cross_entropy'):
		"""
		:param nb_input: number of input neurons
		:param nb_hidden: number of hidden neurons
		:param nb_output: number of output neurons
		"""

		self.nb_input = nb_input
		self.nb_hidden = nb_hidden
		self.nb_output = nb_output
		self.cost_function = cost_function


		# Neurons/Activation nodes:
		self.neurons = list(range(3))
		self.neurons[0] = np.ones((self.nb_input, 1))
		self.neurons[1] = np.ones((self.nb_hidden, 1))
		self.neurons[2] = np.ones((self.nb_output, 1))


		# Activations nodes params:
		self.params = list(range(3))
		self.params[0] = np.ones((self.nb_input, 1))
		self.params[1] = np.ones((self.nb_hidden, 1))
		self.params[2] = np.ones((self.nb_output, 1))


		# Weights:
		self.weights = list(range(2))
		self.weights[0] = np.zeros((self.nb_hidden, self.nb_input+1))
		self.weights[1] = np.zeros((self.nb_output, self.nb_hidden+1))
		self.initialize_weights()


		# Deltas:
		self.deltas = list(range(2))
		self.deltas[0] = np.zeros((self.nb_input, self.nb_hidden))
		self.deltas[1] = np.zeros((self.nb_hidden, self.nb_output))


		# Gradients:
		self.gradients = list(range(len(self.weights)))



	def activation(self, X):
		return Utils.sigmoid(X)


	def dactivation(self, X):
		return Utils.dsigmoid(X)
	

	def initialize_weights(self):
		for i, w in enumerate(self.weights):
			nb_in, nb_out = w.shape
			epsilon = Utils.get_epsilon(nb_in, nb_out-1)
			self.weights[i] = np.random.randn(nb_in, nb_out) * 2 * epsilon - epsilon


	def set_weights(self, layer, w):
		self.weights[layer] = w


	def get_weights(self, layer=None):
		if layer == None:
			return self.weights
		return self.weights[layer]


	def predict_classes(self, X):
		return np.argmax(self.forward_propagation(X), axis=1)


	def predict_classes_vectors(self, X):
		v = self.predict_classes(X)
		z = np.zeros((v.shape[0], self.nb_output))
		for c in v:
			z[c] = 1
		return z

	
	def predict(self, X):
		return self.forward_propagation(X)


	def set_cost_function(self, c):
		self.cost_function = c


	def cost(self, X, Y, lbda):
		if self.cost_function == 'mean_squared_error':
			return self.mean_squared_error(X, Y,lbda)
		elif self.cost_function == 'cross_entropy':
			return self.cross_entropy(X, Y, lbda)
		raise Exception("No cost function with that name was implemented!")



	def cross_entropy(self, X, Y, lbda):

		m = float(X.shape[0])

		# evaluate cost function
		a = np.multiply(Y, np.log(X))
		b = np.multiply((1 - Y), np.log(1 - X))
		J = -(np.sum(np.sum(a + b, axis=1)))/m
		
		# add regularization:
		s0 = np.sum(np.power(self.weights[0][:,1:], 2))
		s1 = np.sum(np.power(self.weights[1][:,1:], 2))
		J += lbda*(s0 + s1)/(2*m) 

		return J


	def mean_squared_error(self, X, Y, lbda):

		m = float(X.shape[0])

		# evaluate cost function
		A  = (X - Y);
		J = np.sum(A.T * A)/(2*m);
		
		# add regularization:
		s0 = np.sum(np.power(self.weights[0][:,1:], 2))
		s1 = np.sum(np.power(self.weights[1][:,1:], 2))
		J += lbda*(s0 + s1)/(2*m) 

		return J



	def forward_propagation(self, X):

		self.params[0] = 0
		self.neurons[0] = Utils.add_column_with_ones(X)

		self.params[1] = self.neurons[0].dot(self.weights[0].T)
		self.neurons[1] = Utils.add_column_with_ones(self.activation(self.params[1]))

		self.params[2] = self.neurons[1].dot(self.weights[1].T)
		self.neurons[2] = self.activation(self.params[2])

		return self.neurons[2]



	def back_propagation(self, Y, lbda, momentum):

		grad = list(range(len(self.weights)))

		self.deltas[1] = self.neurons[2] - Y
		grad[1] = self.deltas[1].T.dot(self.neurons[1])

		self.deltas[0] = np.multiply(self.deltas[1].dot(self.weights[1])[:,1:], self.dactivation(self.params[1]))
		grad[0] = self.deltas[0].T.dot(self.neurons[0])


		# add regularization (not for bias):
		grad[1][:, 1:] = grad[1][:, 1:] + lbda * self.weights[1][:, 1:]
		grad[0][:, 1:] = grad[0][:, 1:] + lbda * self.weights[0][:, 1:]
		
		# add momentum:
		grad[1] = (grad[1] + momentum * self.gradients[1]) / float(Y.shape[0])
		grad[0] = (grad[0] + momentum * self.gradients[0]) / float(Y.shape[0])

		# save gradients
		self.gradients[1] = grad[1]
		self.gradients[0] = grad[0]

		return grad



	def update_weights(self, grad, alpha):
		for i in range(len(grad)):
			self.weights[i] = self.weights[i] - alpha * grad[i]



	def train(self, X, Y, alpha=0.3, lbda=1.0, momentum=0.5, precision=1e-6, nb_iters=100, verbose=True):

		def reached_precision(cost, precision):
			if len(cost) < 2:
				return True
			return abs(cost[-1] - cost[-2]) > precision


		cost_history = []
		i = 0

		while i < nb_iters and reached_precision(cost_history, precision):

			R = self.forward_propagation(X)
			J = self.cost(R, Y, lbda)
			G = self.back_propagation(Y, lbda, momentum)
			self.update_weights(G, alpha)
			cost_history.append(J)

			if verbose:
				sys.stdout.write("Iteration %4d - Cost %.4f \r" % (i+1, J))
				sys.stdout.flush()

			i += 1

		if verbose:
			print("\n"+"-"*30)
		return cost_history


if __name__ == '__main__':


	# X, Y = Reader.read_data('dados/dados.txt', ignore_line_number=True)

	# data = {'X':X, 'Y':Y}
	# Reader.save_mat('train.mat', data)

	mat = Reader.load_mat('dados/xor.mat')
	X, Y = np.matrix(mat['X']), mat['Y']



	iters, times, accs, alphas = [], [], [], []

	result_times = open("rnn_result_times_hidden.txt", "w")
	result_times.write("grau tempo\n")

	result_iters = open("rnn_result_iters_hidden.txt", "w")
	result_iters.write("grau iters\n")

	result_accs = open("rnn_result_accs_hidden.txt", "w")
	result_accs.write("grau acc\n")

	result_alphas = open("rnn_result_alphas_hidden.txt", "w")
	result_alphas.write("grau custo\n")


	lalphas = [0.01, 0.03, 0.1, 0.3, 1.0, 3.0, 6.0, 12.0, 24.0, 48.0]
	validation_split = 0.2
	use_shuffle = False
	use_validation = False

	nb_input  = 2
	nb_hidden = 10
	nb_labels = 2

	nb_iters  = 10000
	nb_epochs = 1

	alpha	  = 3.0
	lbda	  = 0.0
	momentum  = 0.0
	precision = 1e-6

	timer 	  = time.clock if (sys.platform == 'win32') else time.time
	Plots.scatterplot(X, Y)

	for nb_hidden in range(1, 7):

		nn = NeuralNetwork(nb_input, nb_hidden, nb_labels, cost_function='cross_entropy')

		a,b,c,d = [],[],[],[]
		for i in range(nb_epochs):
			
			X_train, Y_train = X, Y
			Y_vec = Utils.vectorize_output(Y_train, nb_labels)
			
			print('Epoch %d' % (i+1))
			print("-"*30)

			nn.initialize_weights()

			start_time = timer()
			j_history = nn.train(X_train, Y_vec, alpha, lbda, momentum, precision, nb_iters, verbose=False)	
			total_time = timer() - start_time

			a.append(len(j_history))
			b.append(total_time)
			c.append(Statistics.accuracy(nn.predict_classes(X_train), Y_train))
			d.append(np.mean(np.array(j_history)))


			# print('Iterations:\t %d' % len(j_history))
			# print('Time:\t\t %.9f seconds' % total_time)
			# print('Accuracy train:\t %.2f' %  Statistics.accuracy(nn.predict_classes(X_train), Y_train))
			# print('\n')

			# d.append(np.mean(np.array(j_history)))
			
			# colors = "gbrcmyk"*2
			# Plots.lineplot(list(range(len(j_history))), j_history, color=colors[k], label='Alpha {}'.format(alpha))

			Plots.draw_boundary_rnn(X, nn.predict_classes, nb_hidden=nb_hidden)

		
		ma, da = np.mean(np.array(a)), np.std(np.array(a))
		mb, db = np.mean(np.array(b)), np.std(np.array(b))
		mc, dc = np.mean(np.array(c)), np.std(np.array(c))
		md, dd = np.mean(np.array(d)), np.std(np.array(d))

		iters.append(ma)
		times.append(mb)
		accs.append(mc)
		alphas.append(md)

		result_iters.write("%d %.4f\n" % (nb_hidden, ma))
		result_times.write("%d %.4f\n" % (nb_hidden, mb))
		result_accs.write("%d %.4f\n" % (nb_hidden, mc))
		result_alphas.write("%d %.4f\n" % (nb_hidden, md))

		print('Alpha %.2f - %d' % (alpha, nb_labels))
		print("-"*30)
		print('Iterations:\t media:%.2lf \t desvio:%.2f' % (ma, da))
		print('Time:\t\t media:%.2lf \t desvio:%.2f seconds' % (mb, db))
		print('Accuracy:\t media:%.2lf \t desvio:%.2f' % (mc, dc))
		print('\n')



	pyplot.legend(loc='upper right', numpoints=1, shadow=True, fancybox=True)
	pyplot.show()

	# Plots.scatterplot(X, Y)
	# Plots.draw_boundary_rnn(X, nn.predict_classes)
	# pyplot.show()

	# pyplot.xlabel('Taxa de aprendizagem')
	# pyplot.ylabel('J(W)')
	# Plots.lineplot(lalphas, alphas, color='g', label='Custo')
	# pyplot.legend(loc='upper right', numpoints=1, shadow=True, fancybox=True)
	# pyplot.show()

	# pyplot.xlabel('Taxa de aprendizagem')
	# pyplot.ylabel('Tempo (s)')
	# Plots.lineplot(lalphas, times, color='g', label='Times')
	# pyplot.legend(loc='upper right', numpoints=1, shadow=True, fancybox=True)
	# pyplot.show()

	# pyplot.xlabel('Taxa de aprendizagem')
	# pyplot.ylabel('Iterações')
	# Plots.lineplot(lalphas, iters, color='b', label='Iterations')
	# pyplot.legend(loc='upper right', numpoints=1, shadow=True, fancybox=True)
	# pyplot.show()

	# pyplot.xlabel('Taxa de aprendizagem')
	# pyplot.ylabel('Acurácia')
	# Plots.lineplot(lalphas, accs, color='b', label='Acurácia')
	# pyplot.legend(loc='upper right', numpoints=1, shadow=True, fancybox=True)
	# pyplot.show()


