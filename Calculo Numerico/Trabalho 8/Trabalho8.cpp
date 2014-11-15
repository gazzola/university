/*
* Trabalho 8.
* Implemente o Método de Newton.
*
* Resolva o método para um conjunto 
* de pelo menos 5 pares de dados (xi,yi).
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
* Compile: g++ -o trab Trabalho8.cpp -Wall -Wextra
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
const int N = 5;
double x[N] = {0.2, 0.4, 0.6, 0.8, 1.0};
double y[N] = {1.22, 1.49, 1.82, 2.23, 2.72};
double tabela[N][N];

void newton(){

	// caso base
	for(int i=0; i<N; i++)
		tabela[i][0] = y[i];


	for(int i=1; i<N; i++){
		for(int j=i; j<N; j++){
			tabela[j][i] = (tabela[j][i-1]-tabela[j-1][i-1])/(x[j]-x[j-i]);
			if(DEBUG)
				printf("(%.2f - %.2f)/(%.2f - %.2f) = %.2f\n", tabela[j][i-1], tabela[j-1][i-1], x[j], x[j-i], tabela[j][i]);
		}
		if(DEBUG)
			printf("\n");
	}
	

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(j > i)
				printf("  ~  ");
			else
				printf("%.2f ", tabela[i][j]);
		}
		printf("\n");
	}
}


double phi(double val_x){

	double total, prod;	
	total = y[0];
	for(int i=1; i<N; i++){

		prod = 1;

		if(DEBUG)
			printf("(%.2lf)", tabela[i][i]);
	

		for(int j=0; j<i; j++){	
			prod *= (val_x - x[j]);
			
			if(DEBUG)
				printf(".(%.2lf - %.2lf)", val_x, x[j]);
		}

		if(DEBUG)
			printf("\n");

		total += (prod*tabela[i][i]);
	}

	return total;
}


void printVet(double *v){
	for(int i=0; i<N; i++)
		printf("%4.2f ", v[i]);
}



int main(){

	double val_x;


	cout << "Metodo de Newton para valores: " << endl;
	cout << "X: "; printVet(x);
	cout << endl;
	cout << "Y: "; printVet(y);
	cout << endl << endl;

	cout << "Tabela de solucao: " << endl;
	newton();
	cout << endl;

	while(true){
			
		cout << "Informe o valor de X ou CTRL-C para parar:" << endl;
		cin >> val_x;

		cout << "Phi(X): " << endl;
		cout << phi(val_x) << endl << endl;
	}

	return 0;
}