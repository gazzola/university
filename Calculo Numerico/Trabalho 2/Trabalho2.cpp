/*
* Trabalho 2.
* Implementar o metodo da Bissecao para resolver uma equacao de 3o grau. 
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
* Compile: g++ -o trab Trabalho2.cpp -Wall -Wextra
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
const double PRECISAO = 0.000000001;
const bool DEBUG = true;
double a, b, c, d;


double equacao(double x){
	return a*powf(x,3) + b*powf(x, 2) + c*x + d;
}

/*double equacao(double x){
	return sin(x) - 0.5*x;
}*/


double metodoBissecao(double ini, double fim){

	double erro = fim-ini;
	double fx, meio;
	double fa;
	int k = 1;

	while(erro > PRECISAO){

		meio = (ini+fim)/2;

		fa = equacao(ini);
		fx = equacao(meio);

		if(fa*fx > 0)
			ini = meio;
		else
			fim = meio;

		erro = fim - ini;

		if(DEBUG)
			printf("%d \t\t %.4lf \t\t %.4lf \t\t %.4lf\n", k++, meio, fx, erro);
	}

	return meio;
}


void acharRaizesAuto(){

	double rx = metodoBissecao(-INF, INF);
	double r1 = metodoBissecao(-INF, rx);
	double r3 = metodoBissecao(rx, INF);
	double r2;
	if(PRECISAO > 0.0001)
		r2 = metodoBissecao(r1+PRECISAO, r3-PRECISAO);
	else
		r2 = metodoBissecao(ceil(r1), floor(r3));

	cout << fixed << setprecision(8);
	
	// caso tenha so uma raiz, considerar apenas RX
	cout << "Raiz X: " << rx << endl;
	cout << "Raiz 1: " << r1 << endl;
	cout << "Raiz 2: " << r2 << endl;
	cout << "Raiz 3: " << r3 << endl;
}


void acharRaizesManual(){

	double x, y, r;
	int i = 1;

	cout << fixed << setprecision(8);

	while(i <= 3){
		cout << "Informe o limite inferior e superior para a raiz " << i++ << ":" << endl;
		cin >> x >> y;
		r = metodoBissecao(x, y);
		cout << "Raiz " << i << ": " << r << endl;
	}

}


int main(){

	cout << "Digite os valores para A, B, C e D:" << endl;
	cin >> a >> b >> c >> d;

	string k = "yes";
	cout << "Digite `yes` para processo automatico e `no` para manual" << endl;
	cin >> k;
	cout << endl;

	if(k == "yes")
		acharRaizesAuto();
	else
		acharRaizesManual();

	return 0;
}