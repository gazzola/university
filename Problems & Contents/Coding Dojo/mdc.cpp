/*
* Resolucao exercicio do Coding Dojo 2014 - SACTA
* Complexidade do algoritmo: O(log(a+b))
*
* Compile: g++ -o mdc mdc.cpp -Wall -Wextra
* Run: ./mdc
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// algoritmo de euclides
int mdc(int a, int b){
	
	int temp;
	while (a != 0){
		temp = a; 
		a = b%a;  
		b = temp;
	}

	return temp;
}

int main(){

	int n1, n2;
	printf("digite dois numeros: ");
	scanf("%d %d", &n1, &n2);

	printf("Maximo divisor comum de %d e %d: %d\n", n1, n2, abs(mdc(n1, n2)));

	return 0;
}