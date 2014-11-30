/*
* Trabalho 10.
* Implemente o Método dos Retângulos e dos Trapézios 
* para equações do formato:
* f(x) = a.sen(x) + b.cos(x) + c.x
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
* Compile: g++ -o trab Trabalho10.cpp -Wall -Wextra
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
double c1, c2, c3; //a, b, c


double f(double x){
	return c1*sin(x) + c2*cos(x) + c3*x;
}


double metodoRetangulos(int a, int b, int n){

	double h = (b-a)/(double) n;
	double hh = h/2;
	
	double soma=0, x;
	for(int i=a; i<b; i++){
		x = (a + i*h) + hh;
		soma += f(x)*h;
	}

	return soma;
}

double metodoTrapezios(int a, int b, int n){

	double h = (b-a)/(double) n;
	
	double soma=0, x;
	for(int i=a; i<b; i++){
		x = (f(i) + f(i+1))/2.0;
		soma += x*h;
	}

	return soma;
}



int main(){

	cout << fixed << setprecision(8);

	int a, b, n;
	while(true){
			
		cout << "Informe os valores dos coeficientes c1, c2, c3:" << endl;
		cin >> c1 >> c2 >> c3;

		cout << "Informe os intervalos de integracao a, b:" << endl;
		cin >> a >> b;

		cout << "Informe o numero de divisoes n:" << endl;
		cin >> n;

		cout << "Metodo dos Retangulos: " << 
		metodoRetangulos(a, b, n) << endl;

		cout << "Metodo dos Trapezios: " << 
		metodoTrapezios(a, b, n) << endl << endl;

	}

	return 0;
}