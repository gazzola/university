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


def vectorize_output(Y, nb_labels):
	Y_vec = np.zeros((Y.shape[0], nb_labels))
	for i in xrange(nb_labels):
		Y_vec[:, i] = (Y == i)[:,0]
	return Y_vec


def lineplot(x, y):
	pyplot.plot(x, y, 'b-')
	pyplot.show()



class NeuralNetwork:

	def __init__(self, nb_input, nb_hidden, nb_output):
		"""
		:param nb_input: number of input neurons
        :param nb_hidden: number of hidden neurons
        :param nb_output: number of output neurons
		"""

		self.nb_input = nb_input
		self.nb_hidden = nb_hidden
		self.nb_output = nb_output


		# Neurons/Activation nodes:
		self.neurons = list(range(5))
		self.neurons[0] = np.ones((self.nb_input, 1))
		self.neurons[1] = np.ones((self.nb_hidden, 1))
		self.neurons[2] = np.ones((self.nb_output, 1))
		self.neurons[3] = np.ones((self.nb_output, 1))
		self.neurons[4] = np.ones((self.nb_output, 1))


		# Activations nodes params:
		self.params = list(range(5))
		self.params[0] = np.ones((self.nb_input, 1))
		self.params[1] = np.ones((self.nb_hidden, 1))
		self.params[2] = np.ones((self.nb_output, 1))
		self.params[3] = np.ones((self.nb_output, 1))
		self.params[4] = np.ones((self.nb_output, 1))


		# Weights:
		self.weights = list(range(3))

		epsilon = get_epsilon(self.nb_hidden, self.nb_input)
		self.weights[0] = np.random.randn(self.nb_hidden, self.nb_input+1) * 2 * epsilon - epsilon

		epsilon = get_epsilon(self.nb_output, self.nb_hidden)
		self.weights[1] = np.random.randn(self.nb_output, self.nb_hidden+1) * 2 * epsilon - epsilon

		epsilon = get_epsilon(self.nb_output, self.nb_input)
		self.weights[2] = np.random.randn(self.nb_output, self.nb_input+1) * 2 * epsilon - epsilon


		# Deltas:
		self.deltas = list(range(2))
		self.deltas[0] = np.zeros((self.nb_input, self.nb_hidden))
		self.deltas[1] = np.zeros((self.nb_hidden, self.nb_output)) 



	def activation(self, X):
		return sigmoid(X)


	def dactivation(self, X):
		return dsigmoid(X)
	

	def set_weights(self, layer, w):
		self.weights[layer] = w


	def predict(self, X):
		return np.argmax(self.forward_propagation(X), axis=1)


	def cost(self, X, Y, lbda):

		m = float(X.shape[0])

		# evaluate cost function
		a = np.multiply(Y, np.log(X))
		b = np.multiply((1 - Y), np.log(1 - X))
		J = -(np.sum(np.sum(a + b, axis=1)))/m
		
		# add regularization:
		s0 = np.sum(np.power(self.weights[0][:,1:], 2))
		s1 = np.sum(np.power(self.weights[1][:,1:], 2))
		s2 = np.sum(np.power(self.weights[2][:,1:], 2))
		J += lbda*(s0 + s1 + s2)/(2*m) 

		return J



	def forward_propagation(self, X):

		self.params[0] = 0
		self.neurons[0] = add_column_with_ones(X)

		self.params[1] = self.neurons[0].dot(self.weights[0].T)
		self.neurons[1] = add_column_with_ones(self.activation(self.params[1]))

		self.params[2] = self.neurons[1].dot(self.weights[1].T)
		self.neurons[2] = self.activation(self.params[2])

		self.params[3] = self.neurons[0].dot(self.weights[2].T)
		self.neurons[3] = self.activation(self.params[3])

		self.params[4] = self.params[2] + self.params[3]
		self.neurons[4] = self.activation(self.params[4])

		return self.neurons[4]



	def back_propagation(self, Y, lbda):

		gradient = list(range(len(self.weights)))

		self.deltas[1] = np.multiply(self.neurons[4] - Y, self.dactivation(self.params[4]))
		gradient[2] = self.deltas[1].T.dot(self.neurons[0])

		gradient[1] = self.deltas[1].T.dot(self.neurons[1])

		self.deltas[0] = np.multiply(self.deltas[1].dot(self.weights[1])[:,1:], self.dactivation(self.params[1]))
		gradient[0] = self.deltas[0].T.dot(self.neurons[0])


		# add regularization (not for bias):
		gradient[2][:, 1:] = gradient[2][:, 1:] + lbda * self.weights[2][:, 1:]
		gradient[1][:, 1:] = gradient[1][:, 1:] + lbda * self.weights[1][:, 1:]
		gradient[0][:, 1:] = gradient[0][:, 1:] + lbda * self.weights[0][:, 1:]
		
		gradient[2] = gradient[2] / float(Y.shape[0])
		gradient[1] = gradient[1] / float(Y.shape[0])
		gradient[0] = gradient[0] / float(Y.shape[0])

		return gradient



	def update_weights(self, grad, alpha):
		for i in xrange(len(grad)):
			self.weights[i] = self.weights[i] - alpha * grad[i]



	def train(self, X, Y, alpha=0.3, lbda=1.0, nb_iters=100):

		cost_history = []
		for i in xrange(nb_iters):

			R = self.forward_propagation(X)
			J = self.cost(R, Y, lbda)
			G = self.back_propagation(Y, lbda)
			self.update_weights(G, alpha)
			cost_history.append(J)

			sys.stdout.write("Iteration %4d - Cost %.4f \r" % (i+1, J))
			sys.stdout.flush()
			# time.sleep(1e-3)

		print("\n")
		return cost_history



if __name__ == '__main__':

	mat = load_mat('mnist.mat')
	# wei = load_mat('weights.mat')

	X, Y = np.matrix(mat['X']), mat['y'] - 1
	# Theta1, Theta2 = wei['Theta1'], wei['Theta2']

	nb_input  = 400  # 20x20 Input Images of Digits
	nb_hidden = 25 
	nb_labels = 10
	nb_iters  = 500
	alpha	  = 6.0	 # test 0.01, 0.03, 0.1, 0.3, 1.0, 3.0, 6.0, 9.0
	lbda	  = 1.0
	
	Y_vec = vectorize_output(Y, nb_labels)

	nn = NeuralNetwork(nb_input, nb_hidden, nb_labels)
	j_history = nn.train(X, Y_vec, alpha, lbda, nb_iters)	
	
	lineplot(list(range(nb_iters)), j_history)

	p = nn.predict(X)
	print('Acc: ', np.mean(p == Y) * 100.0)
	



