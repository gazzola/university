/*
* Complexidade:
* Pior Caso: 	O(n^2) com PD c.c O(2^n)
* Caso medio: 	O(n^2) com PD c.c O(2^n)
* Melhor Caso:	O(n^2) com PD c.c O(2^n)
*
* Memoria usada: 
* O(n) para vetor
* O(n) para auxiliar com PD c.c O(1)
*
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../utils.h"

using namespace std;
const int MAX = 8;
const int INF = 999999;


int **allocateMatrix(int m, int n){
	int i;
	int **matrix = (int**) calloc(m, sizeof(int*));
	for(i=0; i<m; ++i)
		matrix[i] = (int*) calloc(n, sizeof(int*));
	return matrix;
}


void matrixChainOrder(vi &prod, vvi &mat, vvi &sol){

	int n = prod.size();

	for(int i=0; i<n; i++)
		mat[i][i] = 0;

	for(int l=2; l<n; l++){

		printf("L: %d\n", l);
		for(int i=1; i<=n-l; i++){

			int j = i+l-1;
			mat[i][j] = INF;
			for(int k=i; k<j; k++){

				printf("%d %d %d\n", i, k, j);
				
				int p = prod[i-1]*prod[k]*prod[j];
				int q = mat[i][k] + mat[k+1][j] + p;
				if(q < mat[i][j]){
					mat[i][j] = q;
					sol[i][j] = k;
				} 
			}
		}

		printf("\n");
	}

	printMatrix(mat);
	printf("\n");
	printMatrix(sol);
}


void printOptimalParens(vvi &sol, int i, int j){
	if(i == j)
		printf("A%d", i);
	else{
		printf("(");
		printOptimalParens(sol, i, sol[i][j]);
		printf(".");
		printOptimalParens(sol, sol[i][j]+1, j);
		printf(")");
	}
}



vvi multiply(vvi &matA, vvi &matB){
		
	int n = matA.size();
	int m = matB[0].size();
	int l = matA[0].size();

	vi inner(m);
	vvi matR(n, inner);

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			matR[i][j] = 0;
			for(int k=0; k<l; k++)
				matR[i][j] += matA[i][k] * matB[k][j];
		}
	}

	return matR;
}



vvi matrixMultiply(vvvi &mats, vvi &sol, int i, int j){
	if(i == j)
		return mats[i-1];
	
	vvi X = matrixMultiply(mats, sol, i, sol[i][j]);
	vvi Y = matrixMultiply(mats, sol, sol[i][j]+1, j);
	return multiply(X, Y);
}

void matrixMultiplyAux(){

	int r[4] = {2, 3, 3, 4};
	int m1[2][3] = {{2,2,2},{2,2,2}};
	int m2[3][3] = {{2,2,2},{2,2,2},{2,2,2}};
	int m3[3][4] = {{2,2,2,2},{2,2,2,2},{2,2,2,2}};

	vi vet;
	for(int i=0; i<4; i++)
		vet.push_back(r[i]);

	vi inner1(3);
	vi inner2(4);
	vvi mat1(2, inner1), mat2(3, inner1), mat3(3, inner2);

	for(int i=0; i<2; i++)
		for(int j=0; j<3; j++)
			mat1[i][j] = m1[i][j];

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			mat2[i][j] = m2[i][j];

	for(int i=0; i<3; i++)
		for(int j=0; j<4; j++)
			mat3[i][j] = m3[i][j];

	vvvi mats;
	mats.push_back(mat1);
	mats.push_back(mat2);
	mats.push_back(mat3);

	vi inner(4);
	vvi mat(4, inner);
	vvi sol(4, inner);
	matrixChainOrder(vet, mat, sol);

	cout << endl << endl;

	vvi res = matrixMultiply(mats, sol, 1, 4-1);
	printMatrix(res);
}


int main(){

	srand(time(NULL));

	const int N = 7;
	int v[N] = {30, 35, 15, 5, 10, 20, 25};
	
	vi vet;
	for(int i=0; i<N; i++)
		vet.push_back(v[i]);

	vi inner(N);
	vvi mat(N, inner);
	vvi sol(N, inner);

	matrixChainOrder(vet, mat, sol);
	printOptimalParens(sol, 1, N-1);
	cout << endl << endl;

	matrixMultiplyAux();
	cout << endl;
	
	return 0;
}