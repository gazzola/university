/*
* Trabalho 7.
* Implemente o Método de Lagrange.
*
* Interpole para um conjunto (xi,yi) de 
* valores que contenha ao menos 4 pares.
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
* Compile: g++ -o trab Trabalho7.cpp -Wall -Wextra
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

const int N = 4;
double x[N] = {1, 2, 3, 4};
double y[N] = {1, 4, 9, 16};


double lagrange(double val_x){

	double total = 0;
	for(int k=0; k<N; k++){
		
		double prod = 1;
		for(int i=0; i<N; i++){
			if(i != k){
				prod *= ((val_x-x[i])/(x[k]-x[i]));
				if(DEBUG)
					cout << prod << " ";
			}
		}

		total += prod*y[k];
		
		if(DEBUG){
			cout << endl;
			cout << "L" << k << " :" << prod*y[k] << endl;
		}
	}

	return total;
}



int main(){

	double val_x, result;

	while(true){
			
		cout << "Informe o valor de X ou CTRL-C para parar:" << endl;
		cin >> val_x;

		result = lagrange(val_x);
		cout << "Result:" << result << endl << endl;
	}

	

	return 0;
}