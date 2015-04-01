#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;



int main(){
	
	int t, n;
	int vet[100005];

	scanf("%d", &t);
	for(int j=1; j<=t; j++){

		scanf("%d", &n);
		

		int maior = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &vet[i]);
			maior = max(maior, vet[i]);
		}

		int c = 1;
		int last = vet[0];
		int d = 1;

		for(int i=1; i<n; i++){
			if(vet[i] == maior and vet[i] == last)
				c++;
			else{
				d = max(d, c);
				c = 1;
			}

			last = vet[i];
		}

		d = max(d, c);
		printf("Caso #%d: %d\n", j, d);


	}

	
	return 0;
}