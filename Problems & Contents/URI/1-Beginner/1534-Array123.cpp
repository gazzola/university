#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int printMatrix(int n){

	//dependencies
	int count = 0;
	int val = 1;
	int at = n-1;


	//set matrix
	int** mat = new int*[n];
	for(int i = 0; i < n; ++i)
	    mat[i] = new int[n];


	//draw matrix
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			
			if(i+j == at)
				val = 2;
			else if(i == j)
				val = 1;
			else
				val = 3;

			printf("%d", val);

		}
		printf("\n");
	}


	//clear matrix
	for(int i=0; i<n; ++i)
	    delete [] mat[i];
	delete [] mat;
}


int main(){

	int n;

	while(cin >> n)
		printMatrix(n);

	return 0;
}