#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main(){


	
	double a, b, c;
	cin >> a >> b >> c;

	/*
	condicao de existencia de um trinagulo:
	|b-c| < a < b+c
	|a-c| < b < a+c
	|a-b| < c < a+b 
	*/
	
	if((abs(b-c) < a && a < b+c) && (abs(a-c) < b && b < a+c) && (abs(a-b) < c && c < a+b))
		cout << fixed << setprecision(1) << "Perimetro = " << a + b + c << endl;
	else
		cout << fixed << setprecision(1) << "Area = " << (a+b)*c / 2 << endl;


	return 0;
}