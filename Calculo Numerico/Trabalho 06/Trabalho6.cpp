/*
* Trabalho 6.
* Ajuste de Funções.
*
* Implemente uma rotina/programa que permita fazer o ajuste quadrático 
* (função de segundo grau) para um conjunto de entradas m (x e y).
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
* Compile: g++ -o trab Trabalho6.cpp -Wall -Wextra
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


// only quadratic (3x3) matrix
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


		void solveByGauss(T *x1, T *x2, T *x3){

			int n = this->mat.size();
			T a, b, x;


			// zerar L1 com L2
			a = this->mat[0][0];
			b = this->mat[1][0];
			x = -b/a;

			for(int i=0; i<n; i++)
				this->mat[1][i] += this->mat[0][i]*x;
			this->vec[1] += this->vec[0]*x;


			// zerar L1 com L3
			a = this->mat[0][0];
			b = this->mat[2][0];
			x = -b/a;

			for(int i=0; i<n; i++)
				this->mat[2][i] += this->mat[0][i]*x;
			this->vec[2] += this->vec[0]*x;


			// zerar L2 com L3
			a = this->mat[1][1];
			b = this->mat[2][1];
			x = -b/a;

			for(int i=1; i<n; i++)
				this->mat[2][i] += this->mat[1][i]*x;
			this->vec[2] += this->vec[1]*x;


			// resultados finais
			*x3 = this->vec[2]/this->mat[2][2];
			*x2 = (this->vec[1] - this->mat[1][2]*(*x3))/this->mat[1][1];
			*x1 = (this->vec[0] - this->mat[0][2]*(*x3) - this->mat[0][1]*(*x2))/this->mat[0][0];
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



double f3(double a, double b, double c, double x){
	return a + b*x + c*x*x;
}


void applySolution(double *x, double *y, double a, double b, double c, int n){
	for(int i=0; i<n; i++){
		cout << "y[" << i << "] = ";
		y[i] = f3(a, b, c, x[i]);
		cout << y[i] << endl;
	}
}


void printEquation(double a, double b, double c){
	cout << a << " ";
	cout << ((b > 0) ? "+ " : "- ");
	cout << abs(b) << "x ";
	cout << ((c > 0) ? "+ " : "- "); 
	cout << abs(c) << "x^2" << endl;
}




void printVals(vector<vector<double>> &mat, vector<double> &vet){
	int n = vet.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << mat[i][j] << "\t";
			cout << mat[i][j] << "\t";
			cout << mat[i][j] << "\t=  ";
		}
		cout << vet[i] << endl;
	}
}


int main(){

	LinearEquation<double> *le = new LinearEquation<double>(2);

	const int m = 6;
	double x[m] = {-2, -1.5, 0, 1, 2.2, 3.1};
	double y[m] = {-30.5, -20.2, -3.3, 8.9, 16.8, 21.3};
	
	vector<vector<double>> mat;	
	vector<double> vet;

	resizeMat(mat, 3);
	resizeVet(vet, 3);

	mat[0][0] = m;
	mat[0][1] = sumVet(x, m, 1);
	mat[0][2] = sumVet(x, m, 2);
	vet[0] = sumVet(y, m, 1);

	mat[1][0] = mat[0][1];
	mat[1][1] = mat[0][2];
	mat[1][2]= sumVet(x, m, 3);
	vet[1] = sumTwoVets(x, y, m, 1);

	mat[2][0] = mat[1][1];
	mat[2][1] = mat[1][2];
	mat[2][2]= sumVet(x, m, 4);
	vet[2] = sumTwoVets(x, y, m, 2);


	double a, b, c;
	le->setMatrix(mat);
	le->setVector(vet);
	le->solveByGauss(&a, &b, &c);

	printEquation(a, b, c);
	applySolution(x, y, a, b, c, m);

	return 0;
}