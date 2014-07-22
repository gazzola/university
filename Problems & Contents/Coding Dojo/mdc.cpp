#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int mdc(int a, int b){
	
	a = abs(a);
	b = abs(b);

	int temp;
	while (a != 0){
		temp = a; 
		a = b%a;  
		b = temp;
	}

	return temp;
}

int main(){

	int n1=27, n2=3;
	printf("Maximo divisor comum de %d e %d: %d\n", n1, n2, mdc(n1, n2));

	return 0;
}