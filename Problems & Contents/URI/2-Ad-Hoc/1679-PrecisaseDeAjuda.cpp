#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
const int LIM_K = 3001;
const int LIM = 100000/2;


void calcular(int *vet, int *pos){
	int k = 2;
	for(int i=1; i<=LIM; i++)
		vet[i] = k++;

	k = 1;
	for(int i=1; i<=LIM; i++){
		if(vet[i] > 0){
			int x = vet[i];
			int t = 0;
			for(int j=i+1; j<=LIM; j++){
				if(vet[j] > 0)
					t++;
				if(t % x == 0)
					vet[j] = 0;
			}

			pos[k++] = vet[i];
		}
	}
}



int main(){

	int vet[LIM], pos[LIM_K];
	calcular(vet, pos);

	int n;
	while(scanf("%d", &n) and n > 0)
		printf("%d\n", pos[n]);
	

	
	return 0;
}