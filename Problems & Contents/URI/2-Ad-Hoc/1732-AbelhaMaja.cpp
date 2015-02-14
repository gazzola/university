#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


typedef pair<int, int> ii;
const int TAM = 100001;



int main(){
	
	ii vet[TAM];
	vet[1] = ii(0, 0);

	
	int baixo, esq, dir, cima;
	baixo = cima = 1;
	esq = dir = 2;

	int x = 0, y = 0;
	int i = 2;

	while(i < TAM){


		// BAIXO:
		y++;
		vet[i++] = ii(x, y);

		for(int j=1; j<baixo and i<TAM; j++){
			if(x > 0)
				y++;
			x--;
			vet[i++] = ii(x, y);
		}



		// ESQUERDA:
		x--;
		vet[i++] = ii(x, y);

		for(int j=1; j<esq and i<TAM; j++){
			y--;
			vet[i++] = ii(x, y);
		}


		
		// CIMA:
		for(int j=0; j<cima and i<TAM; j++){
			if(x < 0)
				y--;
			x++;
			vet[i++] = ii(x, y);
		}


		x++;
		vet[i++] = ii(x, y);
		for(int j=1; j<dir and i<TAM; j++){
			y++;
			vet[i++] = ii(x, y);
		}


		baixo += 2;
		cima += 2;
		esq += 1;
		dir += 1;
	}

	// for(int i=1; i<=10; i++)
		// printf("%d: %d,%d\n", i, vet[i].first, vet[i].second);
	// printf("\n---------\n");


	int n;
	while(scanf("%d", &n) != EOF){
		printf("%d %d\n", vet[n].first, vet[n].second);
	}

	
	return 0;
}