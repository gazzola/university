#include <iostream>

using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortThreeValues(int *v){
	if(v[0] < v[1])
		swap(v[0], v[1]);

	if(v[1] < v[2])
		swap(v[1], v[2]);

	if(v[0] < v[1])
		swap(v[0], v[1]);
}


int main(){

	double v[3];
	cin >> v[0] >> v[1] >> v[2];

	if(v[0] >= v[1]+v[2])
		cout << "NAO FORMA TRIANGULO" << endl;
	else if(v[0]*v[0] == v[1]*v[1] + v[2]*v[2])
		cout << "TRIANGULO RETANGULO" << endl;
	else if(v[0]*v[0] > v[1]*v[1] + v[2]*v[2])
		cout << "TRIANGULO OBTUSANGULO" << endl;
	else if(v[0]*v[0] < v[1]*v[1] + v[2]*v[2])
		cout << "TRIANGULO ACUTANGULO" << endl;
	
	if(v[0] == v[1] && v[1] == v[2])
		cout << "TRIANGULO EQUILATERO" << endl;
	else if(v[0] == v[1] || v[0] == v[2] || v[1] == v[2])
		cout << "TRIANGULO ISOSCELES" << endl;


	return 0;
}