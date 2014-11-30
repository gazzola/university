/*
* Trabalho 3.
* Implementar o método de Newton Raphson para resolver uma equação formada 
* por expressões que envolvam senos, cossenos, além de eventuais x e constante.
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
* Compile: g++ -o trab Trabalho3.cpp -Wall -Wextra
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
const double PRECISAO = 0.0001;
const bool DEBUG = false;


double funcao(double x){
	return x*x + x - 6;
}

double fDerivada(double x){
	return 2*x + 1;
}


double phi(double x){
	return x - funcao(x)/fDerivada(x);
}


double newtonRaphson(double x){

	int k = 1;
	double y = funcao(x);

	if(DEBUG)
		printf("    Xk(phi)\tY(f(x))\n");


	while(abs(y) > PRECISAO){
		x = phi(x);
		y = funcao(x);

		if(DEBUG)
			printf("%d: %.8lf %.8lf\n", k++, x, abs(y));
	}

	return x;
}




int main(){

	double result, x0;

	while(true){
		cout << "Informe a aproximacao inicial ou CTRL-C para parar:" << endl;
		cin >> x0;

		result = newtonRaphson(x0);

		cout << fixed << setprecision(4);
		cout << "raiz: " << result << endl << endl;
	}

	return 0;
}