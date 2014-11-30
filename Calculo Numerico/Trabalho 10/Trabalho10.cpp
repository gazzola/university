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
double c1, c2, c3, c4; //a, b, c


double f(double x){
	return log((c1*x) + (c2*powf(x, (1/2.0))) + (c3*powf(x, (1/3.0))) + (c4*powf(x, (1/4.0))));
}


double metodoSimpsonComposto(int a, int b, int n){

	double h = (b-a)/(double) n;
	double soma = f(a) + f(b);
	
	for(int i=1; i<n; i++){
		if(i % 2 == 0)
			soma += 2 * f(a + i*h);
		else
			soma += 4 * f(a + i*h);
	}

	return  soma * h/3.0;
}




int main(){

	cout << fixed << setprecision(8);

	int a, b, n;
	while(true){
			
		cout << "Informe os valores dos coeficientes c1, c2, c3, c4:" << endl;
		cin >> c1 >> c2 >> c3 >> c4;

		cout << "Informe os intervalos de integracao a, b:" << endl;
		cin >> a >> b;

		cout << "Informe o numero de divisoes n:" << endl;
		cin >> n;

		cout << "Metodo de Simpson Composto: " << 
		metodoSimpsonComposto(a, b, n) << endl << endl;

	}

	return 0;
}