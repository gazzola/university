/*
*
* File: Problema G - Letras
* Author: Marcos V. Treviso
*
* Complexity: O(m log n)
*
* Description: 
*	- 
*
* Compile: g++ -o teste G-Letras.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef pair<float, ii> fi;
char mat[100][100];


float distancia(ii p1, ii p2){
	float x = p2.first - p1.first;
	float y = p2.second - p1.second;
	return sqrt((x*x) + (y*y));
}


char mudaCase(char k){

	int c = (int) k;
	int a = (int) 'a';
	int j = (int) 'j';
	int A = (int) 'A';

	int diff = a-A;
 
	if(c >= a and c <= j)
		return c-diff;
	
	return c+diff;
}

int getPos(char k){
	int c = (int) k;
	int a = (int) 'a';
	int A = (int) 'A';
	int J = (int) 'J';

	int pos;
	int diff = J-A+1;

	if(c >= a)
		pos = c-a+diff;
	else
		pos = c-A;

	return pos;
}

void setVisitado(bool *visitados, char c){
	int pos = getPos(c);
	visitados[pos] = true;
}

void printVisitados(bool *visitados){
	for(int i=0; i<=20; i++){
		if(i==10)
			printf("| ");
		printf("%d ", (int) visitados[i]);
	}

	printf("\n");
}

bool getVisitado(int *visitados, char c){
	int pos = getPos(c);
	return visitados[pos];
}


bool ehConsistente(bool *visitados, char c){
	
	char k = mudaCase(c);
	int posC = getPos(c);
	int posK = getPos(k);

	if(visitados[posC] == true and visitados[posK] == false)
		return true;
	
	if(visitados[posC] == false and visitados[posK] == false)
		return true;

	return false;

}

struct lessAdj
{
  bool operator()(const fi& lhs, const fi& rhs) const
  {
    return lhs.first > rhs.first;
  }
};

void setAdjacentes(priority_queue<fi, vector<fi>, lessAdj> &adjacentes, ii no, int tam, ii final){
	if(no.first+1 < tam){
		ii novo = ii(no.first+1, no.second);
		adjacentes.push(fi(distancia(novo, final), novo));
	}

	if(no.second+1 < tam){
		ii novo = ii(no.first, no.second+1);
		adjacentes.push(fi(distancia(novo, final), novo));
	}

	if(no.first-1 >= 0){
		ii novo = ii(no.first-1, no.second);
		adjacentes.push(fi(distancia(novo, final), novo));
	}

	if(no.second-1 >= 0){
		ii novo = ii(no.first, no.second-1);
		adjacentes.push(fi(distancia(novo, final), novo));
	}
}


fi popFront(priority_queue<fi> &nodos){
	fi u = nodos.top();
	nodos.pop();
	return u;
}


void printPreds(ii pred[101][101], int tam){
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam; j++){

			char c = '.';
			if(pred[i][j].first != -1)
				c = mat[pred[i][j].first][pred[i][j].second];

			printf("%c", c);
		}
		printf("\n");
	}
	printf("\n");
}



int dijkstra(priority_queue<fi> &nodos, int tam){	//ta quase um a*

	bool visitados[22];
	ii pred[101][101];
	bool posicoes[101][101];
	float chave[101][101];


	ii inicial = ii(0, 0);
	ii final = ii(tam-1, tam-1);
	nodos.push(fi(distancia(inicial, final), inicial));

	for(int i=0; i<tam; i++){
		for(int j=0; j<tam; j++){
			pred[i][j] = ii(-1, -1);
			posicoes[i][j] = false;
			chave[i][j] = 999999.0;
		}
		visitados[i] = false;
	}

	while(!nodos.empty()){
		
		fi u = popFront(nodos);

		float peso = u.first;
		ii no = u.second;

		if(no == final)
			break;

		char c = mat[no.first][no.second];
		setVisitado(visitados, c);
		posicoes[no.first][no.second] = true;

		priority_queue<fi, vector<fi>, lessAdj> adjacentes;
		setAdjacentes(adjacentes, no, tam, final);
		bool ads = false;
		while(!adjacentes.empty()){
			
			//fi v = popFront(adjacentes);
			fi v = adjacentes.top();
			adjacentes.pop();

			ii adj = v.second;
			char c2 = mat[adj.first][adj.second];
			


			if(!posicoes[adj.first][adj.second]){

				if(ehConsistente(visitados, c2)){//se eh um caminho consistente


					float dist = v.first+peso;

					if(dist < chave[adj.first][adj.second]){
						pred[adj.first][adj.second] = no;
						chave[adj.first][adj.second] = dist;
						nodos.push(fi(dist, adj));
					}

				}
			}
		}

		if(ads)
			break;
	}

	printPreds(pred, tam);

	

	int count = 1;
	while(final != inicial){
		ii p = pred[final.first][final.second];
		if(!posicoes[p.first][p.second]){
			count = 0;
			break;
		}
		else{
			final = p;
			count++;
		}
	}

	return count;

	return 0;

}



int main(){

	int n;

	while(scanf("%d", &n) != EOF){

		priority_queue<fi> nodos;	// <peso, nodo>
		char c;

		for(int i=0; i<n; i++){
			scanf("%c", &c); // newline
			for(int j=0; j<n; j++)
				scanf("%c", &mat[i][j]);
		}



		int total = dijkstra(nodos, n);
		
		printf("%d\n", (total<=0) ? -1 : total);
		

	}

	return 0;
}