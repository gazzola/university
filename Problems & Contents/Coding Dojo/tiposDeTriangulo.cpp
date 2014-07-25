/*
* Resolucao exercicio do Coding Dojo 2014 - SACTA
* Complexidade do algoritmo: O(1)
*
* Compile: g++ -o tiposDeTriangulo tiposDeTriangulo.cpp -Wall -Wextra
* Run: ./tiposDeTriangulo
*/

#include <iostream>

using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void ordernaTresValores(double *v){
	if(v[0] < v[1])
		swap(v[0], v[1]);
	if(v[1] < v[2])
		swap(v[1], v[2]);
	if(v[0] < v[1])
		swap(v[0], v[1]);
}


int main(){
	
	double v[3];

	while(true){

		cout << "Digite os 3 lados: ";
		cin >> v[0] >> v[1] >> v[2];

		ordernaTresValores(v);

		if(v[0] >= v[1]+v[2]){
			cout << "NAO FORMA TRIANGULO" << endl;
		}
		else{
			
			if(v[0]*v[0] == v[1]*v[1] + v[2]*v[2])
				cout << "TRIANGULO RETANGULO" << endl;
			else if(v[0]*v[0] > v[1]*v[1] + v[2]*v[2])
				cout << "TRIANGULO OBTUSANGULO" << endl;
			else if(v[0]*v[0] < v[1]*v[1] + v[2]*v[2])
				cout << "TRIANGULO ACUTANGULO" << endl;
			
			if(v[0] == v[1] && v[1] == v[2])
				cout << "TRIANGULO EQUILATERO" << endl;
			else if(v[0] == v[1] || v[0] == v[2] || v[1] == v[2])
				cout << "TRIANGULO ISOSCELES" << endl;
			else if(v[0] != v[1] && v[1] != v[2] && v[0] != v[2])
				cout << "TRIANGULO ESCALENO" << endl;
		}

	}

	return 0;
}