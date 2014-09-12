#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;


#define MAX_TAM 2000002
#define MAX_JOGADORES 1275903
#define EPSILON 1e-9

int posA[MAX_JOGADORES], posB[MAX_JOGADORES];
int treeA[MAX_TAM], treeB[MAX_TAM];



// mais informacoes em: 
// http://marathoncode.blogspot.com.br/2012/02/v-behaviorurldefaultvmlo.html
void atualiza(int idx, int *tree, int val){
	while (idx < MAX_TAM){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}


void insere(int idx, int *tree){
	atualiza(idx, tree, 1);
}


void remove(int idx, int *tree){
	atualiza(idx, tree, -1);
}


int seleciona(int idx, int *tree){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}


int conta_menores(int idx, int *tree){
	return seleciona(idx-1, tree);	//do idx para tras
}


int selecao(int a, int b, int *tree){
	return seleciona(b, tree) - seleciona(a-1, tree);
}




int main(){

	int n, e, golsA, golsB;
	double minimo_jogadores;
	
	while(true){


		scanf("%d %d", &n, &e);
		if(n == 0 and e == 0)
			break;

		memset(treeA, 0, sizeof(treeA));
		memset(treeB, 0, sizeof(treeB));

		minimo_jogadores = (double) n / 11.0;
		golsA = golsB = 0;

		for(int i=1; i<=n/2; i++){
			scanf("%d", &posA[i]);
			insere(posA[i] + 1, treeA);
		}

		for(int i=1; i<=n/2; i++){
			scanf("%d", &posB[i]);
			insere(MAX_TAM - posB[i] - 1, treeB);
		}


		bool impedimento = false;
		char evento, tipo;
		int num, novaPos;

		while(e--){
			scanf("\n%c", &evento);
			
			if(evento == 'I' or evento == 'P'){
				scanf(" %c%d", &tipo, &num);
				if(!impedimento){
					int count;
					if(tipo == 'A')
						count = conta_menores(MAX_TAM - posA[num] - 1, treeB);
					else
						count = conta_menores(posB[num] + 1, treeA);

					if((double) count < minimo_jogadores)
						impedimento = true;
				}
			}
			else if(evento == 'M'){
				scanf(" %c%d %d", &tipo, &num, &novaPos);
				if (tipo == 'A') {
					remove(posA[num] + 1, treeA);
					posA[num] = novaPos;
					insere(posA[num] + 1, treeA);
				} 
				else {
					remove(MAX_TAM - posB[num] - 1, treeB);
					posB[num] = novaPos;
					insere(MAX_TAM - posB[num] - 1, treeB);
				}
			}
			else if(evento == 'G'){
				scanf(" %c", &tipo);
				if(impedimento) 
					impedimento = false;
				else{
					if(tipo == 'A') 
						golsB++;
					else 
						golsA++;
				}
			}
			else if(evento == 'S'){
				impedimento = false;
			}

		}

		printf("%d X %d\n", golsA, golsB);

	}
	

	return 0;
}