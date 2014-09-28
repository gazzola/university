#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>


using namespace std;


int getPos(int *vet, int dado){
	while(vet[dado] >= 0)
		dado = vet[dado];
	return dado;
}

int main(){

	
	int jogo[101];
	int n, a, b, c, x, y, z;

	scanf("%d", &n);
	while(n--){

		memset(jogo, -1, sizeof(jogo));
		scanf("%d %d %d", &a, &b, &c);


		while(b--){
			scanf("%d %d", &x, &y);
			jogo[x] = y;
		}

		bool ganhou = false;
		
		int jogadores[1000001];
		for(int i=0; i<=a; i++)
			jogadores[i] = 1;

		for(int i=0; i<c; i++){

			int j = (i%a);
			scanf("%d", &z);

			if(!ganhou){
				int pos = getPos(jogo, z+jogadores[j]);
				jogadores[j] = pos;
				if(pos == 100)
					ganhou = true;
			}

		}

		for(int i=0; i<a; i++){
			printf("Position of player %d is %d.\n", i+1, jogadores[i]);
		}

	}



	return 0;
}