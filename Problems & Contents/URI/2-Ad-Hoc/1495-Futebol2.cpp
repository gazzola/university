#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;


int funcaoDeComparacao(const void *e1, const void *e2) {
	int a = *((int *) e1);
	int b = *((int *) e2);
	return b - a;
}

int main(){
	
	int n, g, vet[100001];
	int s, r, pontos, ganhou, perdeu, menor;

	while(scanf("%d %d", &n, &g) != EOF){
		
		pontos=0; 
		ganhou=0; 
		perdeu=0; //ou empatou
		menor=-9999999;

		for(int i=0; i<n; i++){
			scanf("%d %d", &s, &r);
			
			if(s <= r){
				vet[perdeu] = s-r;
				perdeu++;
				if(vet[perdeu] < menor)
					menor = vet[perdeu];
			}
			else
				ganhou++;
		}

		qsort(vet, perdeu, sizeof(int), funcaoDeComparacao);

		pontos = ganhou*3;
		menor = abs(menor)+1;
		if(menor > g)
			menor = 1;

		int count=0, i=0;
		while(g > 0){
			if(vet[i] < 1){
				vet[i] += menor;
				g -= menor;
				
				if(g < 1)
					break;

				if(vet[i] > 0){
					count++;
					i++;
				}
			}

			if(count == perdeu)
				break;
		}
		
		
		for(int i=0; i<perdeu; i++){
			if(vet[i] > 0)
				pontos += 3;
			else if(vet[i] == 0)
				pontos += 1;
		}
	

		printf("%d\n", pontos);

	}

	return 0;
}