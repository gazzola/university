#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
int numDigits(int n){
	return (int) log10(n) + 1;
}


void printMatrix(int n){
 
	
	int val;
	val = pow(2, n+n-2);
	int nd = numDigits(val);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			 
			val = pow(2, i+j);
			printf("%*d", nd, val);
			 
			if(j < n-1)
				printf(" ");
		}
		printf("\n");
	}
}
 
 
int main(){
 
	int n;
	while(true){
 
		scanf("%d", &n);
 
		if(n == 0)
			break;
 
		printMatrix(n);
		printf("\n");
	}
 
 
	return 0;
}