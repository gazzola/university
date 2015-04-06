#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef unsigned int ui;

int ctoi(char c){
	return (int) c - '0';
}

ui mdc(ui a, ui b){
	ui temp;
	while (a != 0){
		temp = a; 
		a = b%a;  
		b = temp;
	}
	return temp;
}

ui binToDec(char *bin, int n){
	
	const int base = 2;
	ui total = 0;
	ui p = 1;

	for(int i=n-1; i>=0; i--){
		total += ctoi(bin[i])*p;
		p *= base;
	}

	return total;
}


int main(){

	int t, n;
	char x[32], y[32];
	ui a, b;

	scanf("%d\n", &t);
	for(int i=1; i<=t; i++){
		scanf("%s%n\n", x, &n);
		a = binToDec(x, n);

		scanf("%s%n\n", y, &n);
		b = binToDec(y, n);

		printf("Pair #%d: ", i);
		if(mdc(a, b) > 1)
			printf("All you need is love!\n");
		else
			printf("Love is not all you need!\n");
	}



	return 0;
}