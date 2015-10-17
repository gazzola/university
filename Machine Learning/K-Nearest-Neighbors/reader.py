import numpy as np
import scipy.io

class Reader:

	@staticmethod
	def read_data(file_name, ignore_line_number=True):
		X, Y = [], []
		i = int(ignore_line_number)

		with open(file_name, 'r') as f:
			for line in f:
				temp = list(map(float, line.strip().split()))[i:]
				X.append(temp[:-1])
				Y.append(temp[-1]) 

		return (np.matrix(X), np.matrix(Y).T)


	@staticmethod
	def load_mat(filename):
		return scipy.io.loadmat(filename)

	
	@staticmethod
	def save_mat(filename, mat):
		scipy.io.savemat(filename, mat)