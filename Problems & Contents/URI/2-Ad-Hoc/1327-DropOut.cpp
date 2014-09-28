#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

void remover(vector<char*> &jogadores, int pos){
	jogadores.erase(jogadores.begin()+pos);
}


int main(){
	

	int n;
	while(scanf("%d", &n) and n != 0){

		vector<char*> jogadores;
		for(int i=0; i<n; i++){
			char *nome = (char*) malloc (20*sizeof(char));
			scanf("%s", nome);
			jogadores.push_back(nome);
		}

		int baralho[52];
		for(int i=0; i<52; i++)
			scanf("%d", &baralho[i]);


		int ini = 0;
		int ate = (int) jogadores.size();
		int pos;

		while(ate <= 52){

			
			bool iguais = true;
			int menor = ini;

			for(int i=ini+1; i<ate; i++){
				if(baralho[i] < baralho[menor]){
					menor = i;
					iguais = false;
				}
				else if(baralho[i] > baralho[menor])
					iguais = false;
			}

			if(iguais){
				break;
			}
			else{
				for(int i=ate-1; i>=ini; i--){
					if(baralho[i] == baralho[menor]){
						pos = i-ini;
						remover(jogadores, pos);
					}
				}
			}

			ini = ate;
			ate += (int) jogadores.size();
		}
	

		for(int i=0; i<(int) jogadores.size(); i++)
			printf("%s ", jogadores[i]);

		printf("\n");
	}
	
	return 0;
}