/*
* Resolucao exercicio do Coding Dojo 2014 - SACTA
* Complexidade do algoritmo: O(N)
*
* Compile: g++ -o mergulhadores mergulhadores.cpp -Wall -Wextra
* Run: ./mergulhadores < texto_entrada
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){

	
	bool vet[10000];
	memset(vet, false, sizeof(vet));

	int n, r, x;
	int count = 0;

	while(scanf("%d ", &n) != EOF){
		scanf("%d", &r);

		for(int i=0; i<r; i++){
			scanf("%d", &x);
			x--;
			if(!vet[x]){
				vet[x] = true;
				count++;
			}
		}
		
		if(count == n){
			printf("* ");
		}
		else{
			for(int i=0; i<n; i++){
				if(!vet[i])
					printf("%d ", i+1);			
			}
		}

		printf("\n");
	}

	return 0;
}