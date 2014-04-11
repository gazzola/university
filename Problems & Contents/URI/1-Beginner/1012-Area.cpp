#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14159


double triangleArea(double base, double height){
	return (base*height)/2;
}

double circleArea(double radius){
	return PI*(radius*radius);
}

double trapeziumArea(double base1, double base2, double height){
	return (height*(base1+base2))/2;
}

double squareArea(double height){
	return height*height;
}

double rectangleArea(double width, double height){
	return width*height;
}



int main(){

	double A, B, C;
	cin >> A >> B >> C;

	cout << "TRIANGULO: " << fixed << setprecision(3) << triangleArea(A, C) << endl;
	cout << "CIRCULO: " << fixed << setprecision(3) << circleArea(C) << endl;
	cout << "TRAPEZIO: " << fixed << setprecision(3) << trapeziumArea(A, B, C) << endl;
	cout << "QUADRADO: " << fixed << setprecision(3) << squareArea(B) << endl;
	cout << "RETANGULO: " << fixed << setprecision(3) << rectangleArea(A, B) << endl;


	return 0;
}