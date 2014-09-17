/*
*
* File: Problema F - Teletransporte
* Author: Marcos V. Treviso
*
* Complexity: O(n!)
* Algoritmo de forca bruta
*
* Description: 
*	- 
*
* Compile: g++ -o teste F-Teletransporte.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <cstring>

using namespace std;


// node: quem ele eh, e pra quem aponta
typedef pair< int, int > ii;
typedef pair< ii , int > pi;
typedef pair< int, char > ci;

typedef struct _nodo{

	vector<ci> naveAnt;
	int naveProx;

	int naveAtual;
	char botao;

	int nivel;

}nodo;





nodo popFront(deque<nodo> &nodos){
	nodo front = nodos.front();
	nodos.pop_front();
	return front;
}


void printNodos(deque<nodo> &nodos){
	
	printf("\n");

	int count = 1;
	int tamd = nodos.size();
	for(int i=0; i<tamd; i++){
		nodo aux = nodos[i];
			

		int tam = aux.naveAnt.size();
		printf("[");
		for(int i=0; i<tam; i++)
			printf("%c%d->", aux.naveAnt[i].second, aux.naveAnt[i].first);	

		printf("%c%d, ", aux.botao, aux.naveProx);
		printf("%d]  ", aux.nivel);

		if(count % 4 == 0)
			printf("\n");

		count++;
	}

	printf("\n");

}

int main(){

	
	
	int n, l, s, t, x;

	while(scanf("%d %d %d %d", &n, &l, &s, &t) != EOF){

		if(l > 4){
			printf("ALGORITMO DE FORCA BRUTA\nVAI DEMORAR MTO TEMPO PARA ESSE VALOR DE l\n");
			return 1;
		}
		
		vector<nodo> botoes(4);
		vector< vector<nodo> > naves;
		naves.push_back(botoes);

		for(int i=1; i<=n; i++){
			for(int j=0; j<4; j++){
				scanf("%d", &x);

				nodo aux;
				aux.naveAnt.push_back(ci(s, 'X'));
				aux.naveProx = x;
				aux.naveAtual = i;
				aux.botao = 'A'+j;
				aux.nivel = 0;

				botoes[j] = aux;
			}
			naves.push_back(botoes);
		}


		// fazer um BFS e contar os niveis
		deque<nodo> nodos;

		for(int i=0; i<4; i++)
			nodos.push_back(naves[s][i]);


		int niveis = 0;
		int count = 0;
		while(true){

			if(nodos.front().nivel == l-1)
				break;

			nodo aux = popFront(nodos);
			int q = aux.naveProx;

			for(int i=0; i<4; i++){
				nodo novo = naves[q][i];
				novo.naveAnt.push_back(ci(aux.naveAtual, aux.botao));
				novo.nivel = aux.nivel + 1;
				nodos.push_back(novo);

				if(aux.nivel+1 == l-1)
					if(novo.naveProx == t and novo.naveAnt[0].first == s)
						count++;

			}

			niveis++;
		}

		//printf("%d\n", niveis);

		//map<string, bool> visitado;


		//int tamd = nodos.size();
		//for(int i=0; i<tamd; i++){
		//}

		printNodos(nodos);

		printf("\n\n%d\n\n", count);



	}





	return 0;
}