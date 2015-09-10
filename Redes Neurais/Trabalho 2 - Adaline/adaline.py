import numpy as np
from matplotlib import pyplot


def unitstep(X):
	return (1 + np.sign(X))/2
	# X[X>=0], X[X<0] = 1.0, 0.0
	# return X


def sigmoid(X):
	return 1.0 / (1.0 + np.exp(-1 * X))


def activation(X):
	# return unitstep(X)
	# return sigmoid(X)
	return np.sign(X) # for fun
	# return np.tanh(X) # for fun


def scatterplot(x,y):
	pyplot.plot(x, y, 'b-', linewidth=1.0)
	pyplot.xlim(min(x)-1, max(x)+1)
	pyplot.ylim(min(y)-1, max(y)+1)
	pyplot.show()



'''
mean squarred error
---
obs: with perceptron use activation function,
     but with adaline we should get the real diff value
'''
def cost(X, Y, W, use_activation=False):
	if use_activation:
		return np.sum(np.power(Y - activation(X.dot(W)), 2)) / float(X.shape[0])
		# return np.sum(Y - activation(X.dot(W))) / float(X.shape[0])
	return np.sum(np.power(Y - X.dot(W), 2)) / float(X.shape[0])




'''
compute the gradient and update weights
'''
def gradient(X, Y, A, W, alpha):
	D = Y - A				# (m x 1)
	W += alpha * X.T.dot(D) # (n x 1) + (m x n)' x (m x 1) 




'''
see if the precision was reached
'''
def target(cost, err, only_last=True):
	if only_last:
		return abs(cost[-1]) > err
	return abs(cost[-1] - cost[-2]) > err



'''
train weights W in max_iters iterations
return a history array with errors
'''
def train(X, Y, W, alpha, max_iters=10, err=1e-6):
	
	weight_history = np.array([W])
	cost_history = np.array([0, cost(X, Y, W)])
	i = 1

	while i < max_iters and target(cost_history, err, False):
		
		Z = X.dot(W) 		# (m x n) x (n x 1) -> (m x 1)
		A = activation(Z)	# (m x 1)
		gradient(X, Y, A, W, alpha)
		
		weight_history = np.vstack((weight_history, [W]))
		cost_history = np.append(cost_history, cost(X,Y,W))
		
		i += 1


	return (weight_history, cost_history[1:])



'''
convert the y to a binary output (1 or 0), 
be carefull with activation function
'''
def categorize(y):
	return (y == 1)
	# return y # change the activation function!


'''
read data in file (must be in format x0, x1, x2, ..., xn, y)
and return a numpy array of X and Y (bias included)
'''
def read_data(file_name, bias=-1, ignore_line_number=True):
	X, Y = [], []
	i = int(ignore_line_number)

	with open(file_name, 'r') as f:
		for line in f:
			temp = list(map(float, line.strip().split()))[i:]
			temp.insert(0, bias) # bias term
			X.append(temp[:-1])
			Y.append(temp[-1]) 

	y = np.array(Y).reshape(len(Y), 1)
	if bias == 1:
		return (np.array(X), categorize(y))
	return (np.array(X), y)




'''
return weights as a column vector of length n
'''
def initialize_weights(n, random=True):
	if random:
		return np.random.random((n, 1))
	return np.zeros((n, 1))


'''
plot cost_history, the graph should be constant over iterations
'''
def plot_error(cost_history):
	pyplot.xlabel('iterations')
	pyplot.ylabel('cost(W)')
	pyplot.title('Cost function over iterations')
	scatterplot(list(range(cost_history.shape[0])), cost_history)



'''
auxiliar function to predict new values
'''
def predict(X_new, W):
	return activation(X_new.dot(W))



if __name__ == '__main__':
	
	err = 1e-6
	bias = -1
	alpha = 0.0025
	max_iters = 2000
	epochs = 5
	all_weights = []

	X, Y = read_data('dados.txt', bias)

	for e in range(epochs):
		
		W = initialize_weights(X.shape[1])
		weight_history, cost_history = train(X, Y, W, alpha, max_iters, err)
		print("-"*25)
		print("Num iters:", cost_history.shape[0])
		print("-"*25)

		if e <= epochs:
			plot_error(cost_history)
		
		print(weight_history[-1,:].T)
		all_weights.append(weight_history)

	
	
	X_new, Y_new = read_data('prever.txt', bias)
	X_new = np.hstack((X_new, Y_new))

	for e, w in enumerate(all_weights):
		print("Previsao da epoca %d" % (e+1))
		for i, x in enumerate(X_new):
			print("%.2d: %2d" % (i+1, predict(x, w[-1])[0]))
		print("")
