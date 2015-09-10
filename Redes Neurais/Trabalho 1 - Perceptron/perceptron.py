import numpy as np
from matplotlib import pyplot


def unitstep(X):
	return (1 + np.sign(X))/2
	# X[X>=0], X[X<0] = 1.0, 0.0
	# return X


def activation(X):
	return unitstep(X)
	# return np.sign(X) # for fun
	# return np.tanh(X) # for fun


def scatterplot(x,y):
	pyplot.plot(x, y, 'b-', linewidth=1.0)
	pyplot.xlim(min(x)-1, max(x)+1)
	pyplot.ylim(min(y)-1, max(y)+1)
	pyplot.show()



'''
mean squarred error
'''
def cost(X, Y, W):
	# return np.sum(np.power(activation(X.dot(W)) - Y, 2)) / float(X.shape[0])
	return np.sum(Y - activation(X.dot(W))) / float(X.shape[0])



'''
compute the gradient and update weights
'''
def gradient(X, Y, A, W, alpha):
	D = Y - A				# (m x 1)
	W += alpha * X.T.dot(D) # (n x 1) + (m x n)' x (m x 1) 


'''
train weights W in max_iters iterations
return a history array with errors
'''
def train(X, Y, W, alpha, max_iters=10, err=1e-6):
	
	weight_history = np.array([W])
	cost_history = np.array([cost(X, Y, W)])
	i = 1


	while i < max_iters and abs(cost_history[-1]) > err:
		
		Z = X.dot(W) 		# (m x n) x (n x 1) -> (m x 1)
		A = activation(Z)	# (m x 1)
		gradient(X, Y, A, W, alpha)
		
		weight_history = np.vstack((weight_history, [W]))
		cost_history = np.append(cost_history, cost(X,Y,W))
		
		i += 1


	return (weight_history, cost_history)



'''
convert the y to a binary output (1 or 0)
'''
def categorize(y):
	return (y == 1)
	# return y # change the activation function!


'''
read data in file (must be in format x0, x1, x2, ..., xn, y)
and return a numpy array of X and Y (bias included)
'''
def read_data(file_name, ignore_line_number=True):
	X, Y = [], []
	i = int(ignore_line_number)

	with open(file_name, 'r') as f:
		for line in f:
			temp = list(map(float, line.strip().split()))[i:]
			temp.insert(0, 1.0) # bias term
			X.append(temp[:-1])
			Y.append(temp[-1]) 

	y = np.array(Y).reshape(len(Y), 1)
	return (np.array(X), categorize(y))




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
	
	X, Y = read_data('dados.txt')

	alpha = 0.01
	max_iters = 2000
	epochs = 5
	all_weights = []

	for e in range(epochs):
		
		W = initialize_weights(X.shape[1])
		weight_history, cost_history = train(X, Y, W, alpha, max_iters)
		print("-"*25)
		print("Num iters:", cost_history.shape[0])
		print("-"*25)

		if e == 0:
			plot_error(cost_history)
		
		# for h in weight_history:
		# 	print(h.T)
		print(weight_history[-1,:].T)

		all_weights.append(weight_history)
			


	a = [-0.3565, -0.7842, 0.3012, 0.7757, 0.157, -0.7014, 0.3748, -0.692, -1.397, -1.8842]
	b = [0.062, 1.1267, 0.5611, 1.0648, 0.8028, 1.0316, 0.1536, 0.9404, 0.7141, -0.2805]
	c = [5.9891, 5.5912, 5.8234, 8.0677, 6.304, 3.6005, 6.1537, 4.4058, 4.9263, 1.2548]
	d = [1.0]*len(a)
	
	X_new = zip(d, a, b, c)
	e = 0

	for x in X_new:
		print(predict(np.array(x), all_weights[e][-1]))
