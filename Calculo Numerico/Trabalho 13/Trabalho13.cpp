/*
* Trabalho 13.
* Implemente os métodos iterativos de Jacobi e de Gauss-Seidel
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
* Compile: g++ -o trab Trabalho13.cpp -Wall -Wextra
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
const int N = 3;
const double PRECISION = 0.05;




void printArray(double *arr){
	for(int i=0; i<N; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void printMatrix(double arr[N][N]){
	for(int i=0; i<N; i++)
		printArray(arr[i]);
	cout << endl;
}


bool convergeGJ(double A[N][N]){

	double s, alp;
	for(int i=0; i<N; i++){

		s = 0;
		for(int j=0; j<N; j++)
			if(i != j)
				s += A[i][j];
		alp = s/A[i][i];
		if(alp > 1)
			return false;
	}

	return true;
}

bool convergeGS(double A[N][N]){

	double bts[N], s;
	memset(bts, 0.0, sizeof(bts));

	for(int i=1; i<N; i++)
		s += A[0][i];

	bts[0] = s/A[0][0];
	if(bts[0] > 1)
		return false;

	for(int i=1; i<N; i++){

		s = 0;
		for(int j=0; j<i; j++)
			s += A[i][j]*bts[j];
		bts[i] = s/A[i][i];

		if(bts[i] > 1)
			return false;
	}

	return true;
}



void swapVectors(double *vB, double *vC){
	for(int i=0; i<=N; ++i){
		double t = vB[i];
		vB[i] = vC[i];
		vC[i] = t;
	}
}

void setPermutation(double A[N][N], bool byGJ){
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if(byGJ){
				if(!convergeGJ(A)){
					swapVectors(A[i], A[j]);
					setPermutation(A, byGJ);
				}
			}
			else{
				if(!convergeGS(A)){
					swapVectors(A[i], A[j]);
					setPermutation(A, byGJ);
				}
			}
		}
	}
}

bool precisionAchieved(double *x, double *y){
	for(int i=0; i<N; i++)
		if(abs(y[i]-x[i]) > PRECISION)
			return false;
	return true;
}


double *gaussJacobi(double A[N][N], double *b, double *xs){

	setPermutation(A, true);

	double *ys = (double*) calloc(N, sizeof(double));
	double s;

	while(true){
		for(int i=0; i<N; i++){
			s = 0;
			for(int j=0; j<N; j++)
				if(i != j)
					s += A[i][j]*xs[j];
			ys[i] = (b[i] - s)/A[i][i];
		}

		if(precisionAchieved(xs, ys))
			return ys;

		for(int i=0; i<N; i++)
			xs[i] = ys[i];
	}

	return ys;
}


double *gaussSeidell(double A[N][N], double *b, double *xs){

	setPermutation(A, false);

	double *ys = (double*) calloc(N, sizeof(double));
	double s;

	while(true){

		for(int i=0; i<N; i++)
			ys[i] = xs[i];

		for(int i=0; i<N; i++){
			s = 0;
			for(int j=0; j<N; j++)
				if(i != j)
					s += A[i][j]*xs[j];
			xs[i] = (b[i] - s)/A[i][i];
		}

		if(precisionAchieved(ys, xs))
			return xs;
	}

	return ys;
}



int main(){

	double mat[N][N] = {{10, 2, 1},
						{1,  5, 1},
						{2,  3, 10}};

	double vet[N] = {7, -8, 6};
	double xini[N] = {0.7, -1.6, 0.6};
	double xini2[N] = {0.7, -1.6, 0.6};
	double *res;

	res = gaussJacobi(mat, vet, xini);
	printArray(res);


	res = gaussSeidell(mat, vet, xini2);
	printArray(res);

	return 0;
}