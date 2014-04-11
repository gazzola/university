#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;


int min(int *a, int *b){
	return (*a < *b) ? *a : *b;
}


int printMatrix(int n){

	int count = 0;
	int med = (n & 1 == 0) ? n/2 : n/2 + 1;
	int val = 1;
	int at = ((n+n)/2)-1;

	int** mat = new int*[n];
	for(int i = 0; i < n; ++i)
	    mat[i] = new int[n];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			
			val = min(&i, &j)+1;
			if(j+i > at)
				val = min(&mat[i-1][j], &mat[i][j-1]);

			mat[i][j] = val;

			printf("%3d", val);
			
			if(j < n-1)
				printf(" ");

		}
		printf("\n");
	}

	for(int i=0; i<n; ++i)
	    delete [] mat[i];
	delete [] mat;
}


int main(){

	int n;

	while(true){

		cin >> n;

		if(n == 0)
			break;

		printMatrix(n);
		printf("\n");
	}


	return 0;
}