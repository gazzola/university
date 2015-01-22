import math



mat = [[10, 1, 1, 2, 3, -2],
       [4, -20, 3, 2, -1, 7],
       [5, -3, 15, -1, -4, 1],
       [-1, 1, 2, 8, -1, 2],
       [1, 2, 1, 3, 9, -1],
       [-4, 3, 1, 2, -1, 12]]

vet = [6.57, -68.448, -112.05, -3.98, -2.18, 10.882]

# vet = [1, 2, -5]
# mat = [[1,3,2], [1,4,1], [-3, 1, -10]]


# helpers
def print_matrix(A):
	for i in A:
		print(i)

def mult_matrix(A, B):
	return [[sum(a*b for a,b in zip(x, y)) for y in zip(*B)] for x in A]



# functions
def lu_decomposition(A):
	
	n = len(A)

	# id matrix
	L = [[float(i==j) for j in range(n)] for i in range(n)]
	
	for i in range(n-1):
		for j in range(i+1, n):
			pivo = -A[j][i]/A[i][i]
			L[j][i] = -pivo
			for k in range(i, n):
				A[j][k] += pivo*A[i][k]


	# L U
	return (L, A)


def solve_by_y(L, b):

	n = len(L)
	y = [0 for i in range(n)]
	for i in range(n):
		s = sum([L[i][j]*y[j] for j in range(i)])
		y[i] = b[i] - s

	return y


def solve_by_x(U, b):

	n = len(U)
	x = [0 for i in range(n)]
	for i in range(n-1, -1, -1):
		s = sum([U[i][j]*x[j] for j in range(n-1, i, -1)])
		x[i] = (b[i]-s)/U[i][i]

	return x



L, U = lu_decomposition(mat)
y = solve_by_y(L, vet)
x = solve_by_x(U, y)
print(x)

