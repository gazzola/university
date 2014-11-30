/*
* Trabalho 12.
* Implemente a Fatoração LU
*
* Calculo Numerico
* Claudio Schepke
* ---
* Ciencia da Computacao
* Universidade Federal do Pampa
* 
*
* Integrantes:
* ---
* Marcos V. Treviso, 121150107, marcosvtreviso@gmail.com
*
*
* Instrucoes:
* ---
* Compile: g++ -o trab Trabalho12.cpp -Wall -Wextra
* Run: ./trab
*
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;




const bool DEBUG = false;
const int N = 6;


double *solve_by_y(double L[N][N], double *b){

	double *y = (double*) calloc(N, sizeof(double));
	double s;

	for(int i=0; i<N; i++){
		s = 0;
		for(int j=0; j<i; j++)
			s += L[i][j]*y[j];
		y[i] = b[i] - s;
	}

	return y;
}


double *solve_by_x(double U[N][N], double *b){

	double *x = (double*) calloc(N, sizeof(double));
	double s;

	for(int i=N-1; i>=0; i--){
		s = 0;
		for(int j=N-1; j>i; j--)
			s += U[i][j]*x[j];
		x[i] = (b[i] - s)/U[i][i];
	}

	return x;
}


double *lu_decomposition(double A[N][N], double *b){

	double L[N][N];
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			L[i][j] = (double)(i==j);

	double r;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){

			r = -A[j][i]/A[i][i];
			L[j][i] = -r;
			for(int k=0; k<N; k++)
				A[j][k] += r*A[i][k];
		}
	}


	double *y = solve_by_y(L, b);
	return solve_by_x(A, y);
}


void printArray(double *arr){
	for(int i=0; i<N; i++)
		cout << arr[i] << " ";
	cout << endl;
}



int main(){

	double mat[N][N] = {{10,  1  , 1 ,  2 ,  3 ,  -2 },
					{4 ,  -20, 3 ,  2 ,  -1,  7  },
					{5 ,  -3 , 15,  -1,  -4,  1  },
					{-1,  1  , 2 ,  8 ,  -1,  2  },
					{1 ,  2  , 1 ,  3 ,  9 ,  -1 },
					{-4,  3  , 1 ,  2 ,  -1,  12 }};

	double vet[N] = {6.57, -68.448, -112.05, -3.98, -2.18, 10.882};


	double *x = lu_decomposition(mat, vet);
	printArray(x);

	return 0;
}