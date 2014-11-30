/*
* Trabalho 10.
* Implemente o método de Simpson composto, 
* para calcular a integral de uma função do tipo:
* ln (a*x + (b*x)^(1/2) + (c*x)^(1/3) + (d*x)^(1/4))
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
* Compile: g++ -o trab Trabalho11.cpp -Wall -Wextra
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



const double E = 2.718281828459045;
const bool DEBUG = false;
double c1; //a



double f(double x){
	return c1 * powf(E, x);
}



double calcule(double k, int m, double h){

	double s = 0;
	double x[m+1];

	for(int i=0; i<=m; i++)
		x[i] = k + i*h;

	if(m == 1){
		s += 1*f(x[0]);
		s += 1*f(x[1]);
		return s * (h/2.0);
	}
	else if(m == 2){
		s += 1*f(x[0]);
		s += 4*f(x[1]);
		s += 1*f(x[2]);
		return s * (h/3.0);
	}
	else if(m == 3){
		s += 1*f(x[0]);
		s += 3*f(x[1]);
		s += 3*f(x[2]);
		s += 1*f(x[3]);
		return s * (3*h/8.0);
	}
	else if(m == 4){
		s += 7*f(x[0]);
		s += 32*f(x[1]);
		s += 12*f(x[2]);
		s += 32*f(x[3]);
		s += 7*f(x[4]);
		return s * (2*h/45.0);
	}
	else if(m == 5){
		s += 19*f(x[0]);
		s += 75*f(x[1]);
		s += 50*f(x[2]);
		s += 50*f(x[3]);
		s += 75*f(x[4]);
		s += 19*f(x[5]);
		return s * (5*h/288.0);
	}

	return 0;
}



double newtonCotes(int a, int b, int m, int M){

	int n = m*M;
	double h = (b-a)/(double) n;
	
	double s = 0;


	for(int i=a; i<a+M; i++)
		s += calcule(i*m*h, m, h);
	
	return s;
}




int main(){

	cout << fixed << setprecision(8);

	int a, b, m, M;
	while(true){
			
		cout << "Informe o valor do coeficiente c1:" << endl;
		cin >> c1;

		cout << "Informe os intervalos de integracao a, b:" << endl;
		cin >> a >> b;

		cout << "Informe o grau m e o num de divisoes M:" << endl;
		cin >> m >> M;

		cout << "Metodo de Newton Cotes: " << 
		newtonCotes(a, b, m, M) << endl << endl;

	}

	return 0;
}