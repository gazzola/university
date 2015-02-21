#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


int main(){

	int n, d;
	while(scanf("%d %d", &n, &d) != EOF){

		int *maquina = new int[n];
		for(int i=0; i<n; i++)
			maquina[i] = i+1;

		int i = d-1;
		int j = d;

		while(i >= 0 and j < n){
			maquina[j] = maquina[i]+maquina[j];
			i--;
			j++; 
		}

		for(int k=n-1; k>=d; k--){
			printf("%d", maquina[k]);
		}

		printf("\n");
	}

	return 0;
}