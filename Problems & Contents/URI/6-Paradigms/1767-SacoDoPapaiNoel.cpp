#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const int M = 50;



void binaryKnapsack(int n, int *weight, int *rank){
	
	int mat[101][51];

	for(int i=0; i<101; i++)
		for(int j=0; j<51; j++)
			mat[i][j] = 0;


	int x, i, a, b, vi, pi, pos, k;

	for(x=0; x<=M; ++x){
		for(i=1; i<=n; ++i){
			pos = i-1;
			a = mat[pos][x];

			vi = rank[pos];
			pi = weight[pos];

			if(x-pi >= 0){
				b = vi + mat[pos][x-pi];
				if(a < b)
					a = b;
			}

			mat[i][x] = a;
		}
	}

	
	// http://cse.unl.edu/~goddard/Courses/CSCE310J/Lectures/Lecture8-DynamicProgramming.pdf
	// slide 7
	i = n;
	k = M;

	int peso = 0;
	int items = 0;

	while(i > 0 and k > 0){
		if(mat[i][k] != mat[i-1][k]){
			peso += weight[i-1];
			k = k-weight[i-1];
			items++;
		}
		
		i = i-1;
	}

	printf("%d brinquedos\n", mat[n][M]);
	printf("Peso: %d kg\n", peso);
	printf("sobra(m) %d pacote(s)\n", n-items);
	printf("\n");
}


int main(){

	int n, pac;
	scanf("%d", &n);

	int peso[101];
	int qtd[101];

	while(n--){

		scanf("%d", &pac);
		for(int i=0; i<pac; i++)
			scanf("%d %d", &qtd[i], &peso[i]);

		binaryKnapsack(pac, peso, qtd);

	}


	return 0;
}