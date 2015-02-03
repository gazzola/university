/*
* Trabalho 14.
* Implemente o Método de Euler
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
* Compile: g++ -o trab Trabalho14.cpp -Wall -Wextra
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

typedef pair<double, double> dd;
typedef vector<dd> vd;


void printResult(vd &v){
	int n = v.size();
	for(int i=0; i<n; i++)
		printf("y(%.2f) = %.4f\n", v[i].first, v[i].second);
}

double f(double x, double y){
	return 2*x*y;
}


double next_ele(double x, double y, double h){
	return y + h*f(x, y);
}

double nextY(double x, double y, double h){
	return y + h*(f(x, y)+f(x+h, next_ele(x, y, h)))/2.0;
}


vd euler(double x0, double xn, double y0, double h){
	
	vector<dd> y;
	y.push_back(dd(x0, y0));

	int m;
	double x = x0+h;
	while(x <= xn+h){
		m = y.size()-1;
		y.push_back(dd(x, nextY(y[m].first, y[m].second, h)));
		x += h;
	}

	return y;
}


int main(){

	vd result = euler(1.0, 1.5, 1, 0.1);
	printResult(result);

	return 0;
}