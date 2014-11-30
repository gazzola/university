/*
* Trabalho 5.
* Ajuste de Funções.
*
* Implemente uma rotina/programa que permita fazer o ajuste linear 
* (regressão linear) para um conjunto de entradas m (x e y).
* Caso preferir defina este m previamente, desde que m seja >=5
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
* Compile: g++ -o trab Trabalho5.cpp -Wall -Wextra
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


// only quadratic (2x2) matrix
template <class T>
class LinearEquation{

	private:
		vector<vector<T>> mat;
		vector<T> vec;

	public:

		LinearEquation(int n){
			this->mat.resize(n);
			this->vec.resize(n);
			for(int i=0; i<n; i++)
				this->mat[i].resize(n);
		}

		virtual ~LinearEquation(){
			int n = this->mat.size();
			for(int i=0; i<n; i++)
				this->mat[i].clear();
			this->vec.clear();
		}


		void setMatrix(vector<vector<T>> &m){
			this->mat = m;
		}

		void setVector(vector<T> &v){
			this->vec = v;
		}


		void solveByGauss(T *x1, T *x2){

			int n = this->mat.size();
			T a, b, x;

			// zerar L1 com L2
			a = this->mat[0][0];
			b = this->mat[1][0];
			x = (-b)/a;

			for(int i=0; i<n; i++)
				this->mat[1][i] += this->mat[0][i]*x;
			this->vec[1] += this->vec[0]*x;


			// resultados finais
			*x2 = this->vec[1]/this->mat[1][1];
			*x1 = (this->vec[0] - this->mat[0][1]*(*x2))/this->mat[0][0];  
		}

		void solveByLU();
};






void resizeMat(vector<vector<double>> &m, int n){
	m.resize(n);
	for(int i=0; i<n; i++)
		m[i].resize(n);
}

void resizeVet(vector<double> &v, int n){
	v.resize(n);
}



double sumVet(double *x, int n, int p){
	double s = 0;
	for(int i=0; i<n; i++)
		s += pow(x[i], p);
	return s;
}


double sumTwoVets(double *x, double *y, int n, int p){
	double s = 0;
	for(int i=0; i<n; i++)
		s += pow(x[i], p)*y[i];
	return s;
}


double f2(double a, double b, double x){
	return a + b*x;
}


void applySolution(double *x, double *y, double a, double b, int n){
	for(int i=0; i<n; i++){
		cout << "y[" << i << "] = ";
		y[i] = f2(a, b, x[i]);
		cout << y[i] << endl;
	}
}


void printEquation(double a, double b){
	cout << a << " ";
	cout << ((b > 0) ? "+ " : "- ");
	cout << abs(b) << "x" << endl;
}



int main(){

	LinearEquation<double> *le = new LinearEquation<double>(2);

	const int m = 6;
	double x[m] = {-2, -1.5, 0, 1, 2.2, 3.1};
	double y[m] = {-30.5, -20.2, -3.3, 8.9, 16.8, 21.3};
	
	vector<vector<double>> mat;	
	vector<double> vet;

	resizeMat(mat, 2);
	resizeVet(vet, 2);

	mat[0][0] = m;
	mat[0][1] = sumVet(x, m, 1);
	mat[1][0] = mat[0][1];
	mat[1][1] = sumVet(x, m, 2);
	vet[0] = sumVet(y, m, 1);
	vet[1] = sumTwoVets(x, y, m, 1);

	cout << mat[0][0] << "\t";
	cout << mat[0][1] << "\t=  ";
	cout << vet[0] << endl;

	cout << mat[1][0] << "\t";
	cout << mat[1][1] << "\t=  ";
	cout << vet[1] << endl << endl;


	double a, b;
	le->setMatrix(mat);
	le->setVector(vet);
	le->solveByGauss(&a, &b);

	printEquation(a, b);
	applySolution(x, y, a, b, m);

	return 0;
}