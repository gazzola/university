#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>


using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}


void inverterForcaBruta(int *genes, int *posicoes, int i, int j){
	while(i < j){
		posicoes[genes[i]] = j;
		posicoes[genes[j]] = i;
		swap(&genes[i], &genes[j]);
		i++;
		j--;
	}
}



int main(){
	
	int n, r, q, p, t=1;
	int i;
	// int genes[50005];
	// int posicoes[50005];
	int esq[1001];
	int dir[1001];

	while(scanf("%d", &n) and n > 0){

		// for(int i=1; i<=n; i++)
		// 	genes[i] = posicoes[i] = i;


		scanf("%d", &r);
		for(i=0; i<r; i++){
			scanf("%d %d", &esq[i], &dir[i]);
			// inverterForcaBruta(genes, posicoes, x, y);
		}


		printf("Genome %d\n", t++);

		scanf("%d", &q);
		while(q--){
			scanf("%d", &p);
			
			for(i=0; i<r; i++)
				if(p >= esq[i] and p <= dir[i])
					p = esq[i]+dir[i]-p;

			printf("%d\n", p);
		}
	}	

	
	return 0;
}