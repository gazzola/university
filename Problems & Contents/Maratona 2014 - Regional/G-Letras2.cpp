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
#include <stack>


#define INF 999999

using namespace std;

typedef pair<int, int> ii;
typedef pair<bool, ii> bi;

typedef pair< vector<bool>, ii > vbi;
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




bool ehConsistente(vector<bool> &visitados, char c){
	


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

/*
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
}*/

void setAdjacentes(queue<vbi> &adjacentes, ii no, int tam, vector<bool> visitados){
	if(no.first+1 < tam){
		ii novo = ii(no.first+1, no.second);
		vbi vis = vbi(visitados, novo);
		adjacentes.push(vis);
	}

	if(no.second+1 < tam){
		ii novo = ii(no.first, no.second+1);
		vbi vis = vbi(visitados, novo);
		adjacentes.push(vis);
	}

	if(no.first-1 >= 0){
		ii novo = ii(no.first-1, no.second);
		vbi vis = vbi(visitados, novo);
		adjacentes.push(vis);
	}

	if(no.second-1 >= 0){
		ii novo = ii(no.first, no.second-1);
		vbi vis = vbi(visitados, novo);
		adjacentes.push(vis);
	}
}


db popFront(priority_queue<db, vector<db>, lessAdj> &nodos){
	db u = nodos.top();
	nodos.pop();
	return u;
}

typedef pair< vector<ii>, ii > vci;

struct lessNode{
	bool operator()(const vci &lhs, const vci &rhs) const{
		return distancia(lhs.second, ii(0, 0)) > distancia(rhs.second, ii(0, 0));
	}
};

void setAdjacentesStar(queue<vci> &adjacentes, ii no, int tam, vector<ii> visitados){
	if(no.first+1 < tam){
		ii novo = ii(no.first+1, no.second);
		adjacentes.push(vci(visitados, novo));
	}

	if(no.second+1 < tam){
		ii novo = ii(no.first, no.second+1);
		adjacentes.push(vci(visitados, novo));
	}

	if(no.first-1 >= 0){
		ii novo = ii(no.first-1, no.second);
		adjacentes.push(vci(visitados, novo));
	}

	if(no.second-1 >= 0){
		ii novo = ii(no.first, no.second-1);
		adjacentes.push(vci(visitados, novo));
	}
}

bool ehConsistenteStar(vector<ii> &visitados, ii no){

	char c = mudaCase(mat[no.first][no.second]);
	int tam = visitados.size();

	for(int i=0; i<tam; i++)
		if(mat[visitados[i].first][visitados[i].second] == c)
			return false;

	return true;

}

bool foiVisitado(vector<ii> &visitados, ii no){
	for(int i=0; i<(int) visitados.size(); i++)
		if(visitados[i] == no)
			return true;
	return false;
}


int aStar(int n){

	priority_queue<vci, vector<vci>, lessNode> fila;

	
	ii predecessores[101][101];
	int distancia[101][101];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			predecessores[i][j] = ii(-1, -1);
			distancia[i][j] = INF;
		}
	}

	vector<ii> visitados;
	
	
	distancia[0][0] = 0;

	ii inicial = ii(0, 0);
	ii final = ii(n-1, n-1);


	visitados.push_back(inicial);
	fila.push(vci(visitados, inicial));

	vector<ii> finais;

	while(!fila.empty()){

		vci aux = fila.top();
		fila.pop();

		ii u = aux.second;
		if(u == final){
			finais = aux.first;
			break;
		}

		queue<vci> adjacentes;
		setAdjacentesStar(adjacentes, u, n, aux.first);


		while(!adjacentes.empty()){

			vci aux2 = adjacentes.front();
			adjacentes.pop();
			ii v = aux2.second;

			if(ehConsistenteStar(aux2.first, v) and !foiVisitado(aux2.first, v)){
				int dist = distancia[u.first][u.second]+1;
				if(dist < distancia[v.first][v.second]){
					
					distancia[v.first][v.second] = dist;
					aux2.first.push_back(v);
					fila.push(aux2);
					predecessores[v.first][v.second] = u;
				}
			}
			else{
				distancia[v.first][v.second] = INF;

				ii p = predecessores[v.first][v.second];
				if(distancia[p.first][p.second] != INF)
					predecessores[v.first][v.second] = ii(-1,-1);
			}

		}

	}

	//printPreds(predecessores, n);

	//printf("\n\nxxxx:%d\n\n",(int) finais.size());

	if(finais.size() > 0)
		return finais.size();

	int count = 1;
	while(final != inicial){
		ii p = predecessores[final.first][final.second];
		
		

		if(p.first == -1 or p.second == -1){
			count = 0;
			break;
		}
		else{
			final = p;
			count++;
		}

	}

	return count;
}


int bfs(int n){

	stack<vbi> fila;
	vector<bool> visitados(22);
	ii predecessores[101][101];
	bool posicoes[101][101];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			predecessores[i][j] = ii(-1, -1);
			posicoes[i][j] = false;
		}
	}
	
	for(int i=0; i<22; i++)
		visitados[i] = false;

	ii final = ii(n-1, n-1);
	ii inicial = ii(0, 0);
	fila.push(vbi(visitados, inicial));

	while(!fila.empty()){

		vbi aux = fila.top();
		fila.pop();

		ii u = aux.second;
		if(u == final)
			break;

		int pos = getPos(mat[u.first][u.second]);
		aux.first[pos] = true;

		queue<vbi> adjacentes;
		setAdjacentes(adjacentes, u, n, aux.first);

		while(!adjacentes.empty()){

			vbi aux2 = adjacentes.front();
			adjacentes.pop();
			ii v = aux2.second;

			if(ehConsistente(aux2.first, mat[v.first][v.second])){
				predecessores[v.first][v.second] = u;
				posicoes[v.first][v.second] = true;
				fila.push(aux2);
			}
		}

	}

	printPreds(predecessores, n);

	int count = 1;
	while(final != inicial){
		ii p = predecessores[final.first][final.second];
		
		if(p.first == -1 or p.second == -1){
			count = 0;
			break;
		}
		else{
			final = p;
			count++;
		}
	}

	return count;

}



int main(){

	int n, k=1, total;

	while(scanf("%d", &n) != EOF){

		
		char c;

		for(int i=0; i<n; i++){
			scanf("%c", &c); // newline
			for(int j=0; j<n; j++)
				scanf("%c", &mat[i][j]);
		}

		
		//priority_queue<db, vector<db>, lessAdj> nodos;	// <peso, nodo>
		//total = bfs(n);
		//printf("%d: %d\n", k, (total<=0) ? -1 : total);
		total = aStar(n);
		printf("%d: %d\n", k++, (total<=0) ? -1 : total);
	}



	return 0;
}