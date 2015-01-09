/*
* Trabalho 15.
* Implemente o método de Runge-Kutta de 4a Ordem
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
* Compile: g++ -o trab Trabalho15.cpp -Wall -Wextra
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
#include <limits>

using namespace std;

const double EPSILON = 1e-7;

typedef pair<double, double> dd;
typedef vector<dd> vd;



void printResult(vd &v){
	int n = v.size();
	printf("Xn:    Yn:\n");
	for(int i=0; i<n; i++)
		printf("%.2f   %.4f\n", v[i].first, v[i].second);
}


double eq(double x, double y){
	return 2*x*y;
}

double nextY(double h, double x0, double y0){

	double incog[4];
	double x_aux, y_aux, total;

	incog[0] = h*eq(x0, y0);

	x_aux = x0 + 0.5*h;
	y_aux = y0 + 0.5*incog[0];
	incog[1] = h*eq(x_aux, y_aux);

	x_aux = x0 + 0.5*h;
	y_aux = y0 + 0.5*incog[1];
	incog[2] = h*eq(x_aux, y_aux);

	x_aux = x0 + h;
	y_aux = y0 + incog[2];
	incog[3] = h*eq(x_aux, y_aux);

	total = incog[0]+2*incog[1]+2*incog[2]+incog[3];
	return y0 + (1/6.0)*total;
}


vd rungeKutta(double x0, double xn, double y0, double h){

	vd y;
	int m;

	y.push_back(dd(x0, y0));

	for(double x=x0+h; x<xn+EPSILON; x+=h){
		m = y.size()-1;
		y.push_back(dd(x, nextY(h, y[m].first, y[m].second)));
	}

	return y;
}



int main(){

	vd result = rungeKutta(1, 1.5, 1, 0.1);
	printResult(result);

	return 0;
}