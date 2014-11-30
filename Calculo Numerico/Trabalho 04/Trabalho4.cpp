/*
* Trabalho 4.
* Implemente o algoritmo de Briot-Ruffini (Briot-Ruffini-Horner ou Birge-Vieta, 
* ou seja, a técnica iterativa que vimos) para polinômios de grau 5.
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
* Compile: g++ -o trab Trabalho4.cpp -Wall -Wextra
* Run: ./trab
*
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

const double INF = 999999;
const double PRECISAO = 0.00001;
const bool DEBUG = false;
const int MAX = 6;

double valores[MAX]; // A, B, C, D, E, F

void printVet(double *vet){
	for(int i=0; i<MAX; i++)
		printf("%.4lf ", vet[i]);
	printf("\n");
}



double briotRuffini(double x){

	while(true){

		double resultados1[MAX], resultados2[MAX];
		double resto1, resto2, restoFinal;

		resultados1[0] = valores[0];
		for(int i=1; i<MAX; i++)
			resultados1[i] = x*resultados1[i-1] + valores[i];

		resto1 = resultados1[MAX-1];
		if(DEBUG)
			printVet(resultados1);
		

		resultados2[0] = resultados1[0];
		for(int i=1; i<MAX; i++)
			resultados2[i] = x*resultados2[i-1] + resultados1[i];

		resto2 = resultados2[MAX-2];
		if(DEBUG)
			printVet(resultados2);


		restoFinal = resto1/resto2;
		x = x - restoFinal;

		if(restoFinal < PRECISAO)
			break;
	}

	return x;
}



int main(){

	double result, x0;

	cout << "Informe os valores dos coeficientes A..F: " << endl;
	for(int i=0; i<MAX; i++)
		cin >> valores[i];

	while(true){
			
		cout << "Informe um chute inicial ou CTRL-C para parar:" << endl;
		cin >> x0;

		result = briotRuffini(x0);

		cout << fixed << setprecision(8);
		cout << "raiz: " << result << endl << endl;
	}

	return 0;
}