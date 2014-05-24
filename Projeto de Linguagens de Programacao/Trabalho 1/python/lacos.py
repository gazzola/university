import os, sys


def multMatrix(matrix1, matrix2, n):
	mat = [[0 for y in range(n)] for x in range(n)]
	for i in range(n):
		for j in range(n):
			for k in range(n):
				mat[i][j] += matrix1[i][k]*matrix2[k][j]
	return mat


n = int(sys.argv[1])
mat1 = [[x+y for y in range(1, n+1)] for x in range(1, n+1)]
mat2 = [[x*y for y in range(1, n+1)] for x in range(1, n+1)]
print(str(multMatrix(mat1, mat2, n)))
