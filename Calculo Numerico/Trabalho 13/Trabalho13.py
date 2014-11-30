import math



mat = [[10., 2., 1.],
       [1., 5., 1.],
       [2., 3., 10.]]

vet = [7, -8, 6]
xini = [0.7, -1.6, 0.6]


'''
mat = [[5., 1., 1.],
       [3., 4., 1.],
       [3., 3., 6.]]

vet = [5, 6, 0]
xini = [0.0, 0.0, 0.0]
'''

precision = 0.05



# helpers
def print_matrix(A):
	for i in A:
		print(i)

def mult_matrix(A, B):
	return [[sum(a*b for a,b in zip(x, y)) for y in zip(*B)] for x in A]


# COMPLEXITY: N!   ->  WARNING!
def set_permutation(A, conv_method):

	n = len(A)
	for i in range(n):
		for j in range(i+1, n):
			if not conv_method(A):
				A[i], A[j] = A[j], A[i]
				set_permutation(A)



def conv_gauss_jacobi(A):

	n = len(A)
	for i in range(n):
		s = sum(A[i])-A[i][i]
		alpha = s/A[i][i]

		if alpha > 1:
			return False

	return True


def conv_gauss_seidell(A):

	n = len(A)
	betas = [0 for i in range(n)]

	betas[0] = sum(A[0][1:])/A[0][0]
	if betas[0] > 1:
		return False

	for i in range(1, n):
		s = sum([A[i][j]*betas[j] for j in range(i)])
		betas[i] = s/A[i][i]

		if betas[i] > 1:
			return False

	return True
				

def seePrecision(x0, x1):
	for x, y in zip(x0, x1):
		if abs(y-x) > precision:
			return False
	return True


def gauss_jacobi(A, b, xs):

	# USE THIS METHOD CAREFULLY
	set_permutation(A, conv_gauss_jacobi)

	n = len(A)
	ys = [0 for i in range(n)]

	while True:
		
		for i in range(n):
			s = sum([A[i][j]*xs[j] for j in range(n)]) - A[i][i] * xs[i]
			ys[i] = (b[i] - s)/A[i][i]

		if seePrecision(xs, ys):
			return ys

		xs = [v for v in ys]


	return None


def gauss_seidell(A, b, xs):

	# USE THIS METHOD CAREFULLY
	set_permutation(A, conv_gauss_seidell)

	n = len(A)
	ys = [0 for i in range(n)]

	while True:
		
		ys = [v for v in xs]

		for i in range(n):
			s = sum([A[i][j]*xs[j] for j in range(n)]) - A[i][i] * xs[i]
			xs[i] = (b[i] - s)/A[i][i]

		if seePrecision(ys, xs):
			return xs

	return None
	

print(gauss_jacobi(mat, vet, xini))
print(gauss_seidell(mat, vet, xini))
