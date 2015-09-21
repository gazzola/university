import numpy as np
import scipy.io, math, sys, time
from matplotlib import pyplot
from scipy import optimize


# Utils:
def load_mat(filename):
	return scipy.io.loadmat('dados/'+filename)


def save_mat(filename, mat):
	scipy.io.savemat('dados/'+filename, mat)


def sigmoid(X):
	return 1.0 / (1.0 + np.exp(-X))


def dsigmoid(X):
	return np.multiply(sigmoid(X), (1 - sigmoid(X)))


def add_column_with_ones(X):
	return np.c_[np.ones(len(X)), X]


def get_epsilon(l_in, l_out):
	return math.sqrt(6)/math.sqrt(l_in + l_out)


def mean_relative_error(x, y):
	return sum([(i-j)/j for i,j in zip(x, y)])/len(y)


def vectorize_output(Y, nb_labels):
	Y_vec = np.zeros((Y.shape[0], nb_labels))
	for i in xrange(nb_labels):
		Y_vec[:, i] = (Y == i)[:,0]
	return Y_vec


def lineplot(x, y):
	pyplot.plot(x, y, 'b-')
	pyplot.xlim(min(x)-1, max(x)+1)
	pyplot.show()


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



class NeuralNetwork:

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

		epsilon = get_epsilon(self.nb_hidden, self.nb_input)
		self.weights[0] = np.random.randn(self.nb_hidden, self.nb_input+1) * 2 * epsilon - epsilon

		epsilon = get_epsilon(self.nb_output, self.nb_hidden)
		self.weights[1] = np.random.randn(self.nb_output, self.nb_hidden+1) * 2 * epsilon - epsilon


		# Deltas:
		self.deltas = list(range(2))
		self.deltas[0] = np.zeros((self.nb_input, self.nb_hidden))
		self.deltas[1] = np.zeros((self.nb_hidden, self.nb_output))


		# Gradients:
		self.gradients = list(range(len(self.weights)))



	def activation(self, X):
		return sigmoid(X)


	def dactivation(self, X):
		return dsigmoid(X)
	

	def initialize_weights(self):
		for i, w in enumerate(self.weights):
			nb_in, nb_out = w.shape
			epsilon = get_epsilon(nb_in, nb_out-1)
			self.weights[i] = np.random.randn(nb_in, nb_out) * 2 * epsilon - epsilon


	def set_weights(self, layer, w):
		self.weights[layer] = w


	def get_weights(self, layer=None):
		if layer == None:
			return self.weights
		return self.weights[layer]


	def predict_classes(self, X):
		return np.argmax(self.forward_propagation(X), axis=1)


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
		self.neurons[0] = add_column_with_ones(X)

		self.params[1] = self.neurons[0].dot(self.weights[0].T)
		self.neurons[1] = add_column_with_ones(self.activation(self.params[1]))

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
		for i in xrange(len(grad)):
			self.weights[i] = self.weights[i] - alpha * grad[i]



	def train(self, X, Y, alpha=0.3, lbda=1.0, momentum=0.5, precision=1e-6, nb_iters=100):

		def reached_precision(cost, precision):
			if len(cost) < 2:
				return True
			return abs(cost[-1] - cost[-2]) > precision


		cost_history = [0]

		i = 0
		while i < nb_iters and reached_precision(cost_history, precision):

			R = self.forward_propagation(X)
			J = self.cost(R, Y, lbda)
			G = self.back_propagation(Y, lbda, momentum)
			self.update_weights(G, alpha)
			cost_history.append(J)

			sys.stdout.write("Iteration %4d - Cost %.4f \r" % (i+1, J))
			sys.stdout.flush()

			i += 1

		print("\n"+"-"*30)
		return cost_history[1:]



if __name__ == '__main__':


	# X, Y = read_data('dados/dados.txt', ignore_line_number=True)
	# data = {'X':X, 'Y':Y}
	# save_mat('train.mat', data)

	# X_test, Y_test = read_data('dados/testes.txt', ignore_line_number=True)
	# data = {'X_test':X_test, 'Y_test':Y_test}
	# save_mat('test.mat', data)


	mat = load_mat('train.mat')
	X, Y = np.matrix(mat['X']), mat['Y']

	mat_test = load_mat('test.mat')
	X_test, Y_test = np.matrix(mat_test['X_test']), mat_test['Y_test']


	nb_input  = 3 
	nb_hidden = 10
	nb_labels = 1

	nb_iters  = 10000
	nb_epochs = 5

	alpha	  = 0.1
	lbda	  = 0.0
	momentum  = 0.0
	precision = 1e-6

	timer 	  = time.clock if (sys.platform == 'win32') else time.time
	# Y_vec	  = vectorize_output(Y, nb_labels)

	nn = NeuralNetwork(nb_input, nb_hidden, nb_labels, cost_function='mean_squared_error')

	for i in range(nb_epochs):
		
		nn.initialize_weights()

		start_time = timer()
		j_history = nn.train(X, Y, alpha, lbda, momentum, precision, nb_iters)	
		total_time = timer() - start_time

		predictions = nn.predict(X_test)

		print('Iterations:\t %d' % len(j_history))
		print('Time:\t\t %.9f seconds' % total_time)
		print('Mean Rel. Error: %.4f' %  mean_relative_error(predictions, Y_test))
		print('Variance:\t %.4f' %  np.var(predictions))
		print('Predictions:')
		for i, p in enumerate(predictions):
			print('  sample %2d: %.4f' % (i+1, p))
		print('\n')

		lineplot(list(range(len(j_history))), j_history)
		
		

