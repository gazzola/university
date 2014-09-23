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


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>


#define INF 999999

using namespace std;

typedef pair<int, int> ii;
typedef pair< vector<bool>, ii > bi;
typedef pair< bool, ii > xi;
typedef pair<double, bi> db;
char mat[100][100];


void printVisitados(vector<bool> &visitados){
	printf("A B C D E F G H I J | a b c d e f g h i j\n");

	for(int i=0; i<20; i++){
		if(i==10)
			printf("| ");
		printf("%d ", (int) visitados[i]);
	}

	printf("\n");
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



double distancia(ii p1, ii p2){
	double x = p2.first - p1.first;
	double y = p2.second - p1.second;
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


void setVisitado(vector<bool> &visitados, char c){
	int pos = getPos(c);
	visitados[pos] = true;
}


bool getVisitado(vector<bool> &visitados, char c){
	int pos = getPos(c);
	return visitados[pos];
}




bool ehConsistente(vector<bool> &visitados, char c, char l){
	


	char k = mudaCase(c);
	int posC = getPos(c);
	int posK = getPos(k);

	/*printf("%c->%c:\n", l, c);
	printVisitados(visitados);
	printf("\n\n");
	getchar();*/


	if(visitados[posC] == true and visitados[posK] == false)
		return true;
	
	if(visitados[posC] == false and visitados[posK] == false)
		return true;

	return false;

}

struct lessAdj{
	bool operator()(const db &lhs, const db &rhs) const{
		return lhs.first > rhs.first;
	}
};


void setAdjacentes(priority_queue<db, vector<db>, lessAdj> &adjacentes, ii no, int tam, ii final, vector<bool> visitados){
	if(no.first+1 < tam){
		ii novo = ii(no.first+1, no.second);
		vector<bool> newvis = visitados;
		bi vis = bi(newvis, novo);
		adjacentes.push(db(distancia(novo, final), vis));
	}

	if(no.second+1 < tam){
		ii novo = ii(no.first, no.second+1);
		vector<bool> newvis = visitados;
		bi vis = bi(newvis, novo);
		adjacentes.push(db(distancia(novo, final), vis));
	}

	if(no.first-1 >= 0){
		ii novo = ii(no.first-1, no.second);
		vector<bool> newvis = visitados;
		bi vis = bi(newvis, novo);
		adjacentes.push(db(distancia(novo, final), vis));
	}

	if(no.second-1 >= 0){
		ii novo = ii(no.first, no.second-1);
		vector<bool> newvis = visitados;
		bi vis = bi(newvis, novo);
		adjacentes.push(db(distancia(novo, final), vis));
	}
}


db popFront(priority_queue<db, vector<db>, lessAdj> &nodos){
	db u = nodos.top();
	nodos.pop();
	return u;
}




int dijkstra(priority_queue<db, vector<db>, lessAdj> &nodos, int tam){	//ta quase um a*

	ii pred[101][101];
	xi posicoes[101][101];
	double chave[101][101];


	ii inicial = ii(0, 0);
	ii final = ii(tam-1, tam-1);

	vector<bool> visitados(22);
	for(int i=0; i<22; i++)
		visitados[i] = false;


	bi vis = bi(visitados, final);
	nodos.push(db(distancia(inicial, final), vis));

	for(int i=0; i<tam; i++){
		for(int j=0; j<tam; j++){
			pred[i][j] = ii(-1, -1);
			posicoes[i][j] = xi(false, ii(1, -1));
			chave[i][j] = INF;
		}
	}

	vector<char> seq;

	while(!nodos.empty()){
		
		db u = popFront(nodos);

		double peso = u.first;
		bi aux = u.second;
		ii no = aux.second;

		if(no == inicial)
			break;


		char c = mat[no.first][no.second];
		seq.push_back(c);
		setVisitado(aux.first, c);

		posicoes[no.first][no.second].first = true;
		
		priority_queue<db, vector<db>, lessAdj> adjacentes;
		setAdjacentes(adjacentes, no, tam, inicial, aux.first);

		while(!adjacentes.empty()){
			
			db v = popFront(adjacentes);
			
			ii adj = v.second.second;
			char c2 = mat[adj.first][adj.second];
			
			if(posicoes[adj.first][adj.second].second != no and !posicoes[adj.first][adj.second].first){

				posicoes[adj.first][adj.second] = xi(false, no);

				if(ehConsistente(v.second.first, c2, c)){//se eh um caminho consistente

					double dist = distancia(adj, inicial)+peso;
					if(dist < chave[adj.first][adj.second]){

						pred[adj.first][adj.second] = no;
						chave[adj.first][adj.second] = dist;
						bi xd = bi(v.second.first, adj);
						nodos.push(db(dist, xd));
					}
				
				}
			}
		}

	}

	/*for(int i=0; i<(int) seq.size(); i++)
		printf("%c-", seq[i]);
	
	printf("\n\n\n");

	printPreds(pred, tam);*/
	
	
	int count = 1;
	while(final != inicial){
		ii p = pred[inicial.first][inicial.second];
		
		if(p.first == -1){
			count = 0;
			break;
		}
		else{
			inicial = p;
			count++;
		}
	
	}

	return count;

}



int main(){

	int n;

	while(scanf("%d", &n) != EOF){

		
		char c;

		for(int i=0; i<n; i++){
			scanf("%c", &c); // newline
			for(int j=0; j<n; j++)
				scanf("%c", &mat[i][j]);
		}

		priority_queue<db, vector<db>, lessAdj> nodos;	// <peso, nodo>
		int total = dijkstra(nodos, n);
		printf("%d\n", (total<=0) ? -1 : total);
	}



	return 0;
}