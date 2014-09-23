/*
*
* File: Problema D - DonaMinhoca
* Author: Marcos V. Treviso
*
* Complexity: O(n)
*
* Description: 
*	- Voltas para o piloto mais veloz ultrapassar o mais lento
*
* Compile: g++ -o teste D-DonaMinhoca.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define TAM 10002
#define INF 999999

int matAdj[TAM][TAM];
int matAdjNova[TAM][TAM];



int extractMin(vector<int> &vertices, int *chave){
	
	int menor=vertices[0], pos=0;
	for(int i=0; i<(int) vertices.size(); i++){
		if(chave[vertices[i]] < chave[menor]){
			menor = vertices[i];
			pos = i;
		}
	}

	vertices.erase(vertices.begin()+pos);
	return menor;
}

void printPreds(int *preds, int n){
	for(int i=1; i<=n; i++)
		printf("%d ", preds[i]);
	printf("\n\n");
}


void printMatriz(int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d ", matAdjNova[i][j]);
		}
		printf("\n");
	}
}


void criaNovo(int n, int r){
	int novo = n+1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			matAdjNova[i][j] = matAdj[i][j];
			if(i == r){
				matAdjNova[novo][j] = matAdj[i][j];
			}
			else if(j == r){
				matAdjNova[i][novo] = matAdj[i][j];
				matAdjNova[i][j] = 0;
			}
		}
	}
}

int prim(int n, int r){

	int posicoes[TAM];
	int pi[TAM];
	int chave[TAM];


	for(int i=1; i<=n+1; i++){
		chave[i] = INF;
		pi[i] = -1;
		posicoes[i] = 0;
	}


	criaNovo(n, r);
	n++;

	chave[r] = 0;
	vector<int> vertices;
	vertices.push_back(r);


	while(vertices.size() > 0){
		int u = extractMin(vertices, chave);
		posicoes[u] = 1;

		for(int v=1; v<=n; v++){
			if(matAdjNova[u][v] > 0){
				if(!posicoes[v] && matAdjNova[u][v] < chave[v]){
					chave[v] = matAdjNova[u][v];
					pi[v] = u;
					vertices.push_back(v);
				}
			}
		}
	}

	printPreds(pi, n);
	//printPreds(chave, n);
	/*int k = r;
	int total = 0;
	while(pi[k] != r){
		int l = pi[k];
		total += matAdjNova[k][l];
		k = l;
	}*/
	int soma = 0;
	for(int i=1; i<=n; i++)
		soma += matAdjNova[i][pi[i]];
	return soma;
	return -1;

}

int dijkstra(int n, int r, int m){

	int predecessores[TAM];
	bool visitados[TAM];
	int distancias[TAM];
	
	for(int i=0; i<=n+1; i++){
		predecessores[i] = -1;
		distancias[i] = INF;
		visitados[i] = false;
	}

	vector<int> vertices;
	vertices.push_back(r);
	distancias[r] = 0;

	criaNovo(n, r);
	n++;

	while(!vertices.empty()){

		int u = extractMin(vertices, distancias);
		visitados[u] = true;

		for(int v=1; v<=n; v++){
			
			if(matAdjNova[u][v] > 0){
				int dist = distancias[u]+matAdjNova[u][v];
				if(!visitados[v] and dist < distancias[v]){
					distancias[v] = dist;
					predecessores[v] = u;
					vertices.push_back(v);
				}
			}

		}
	}

	printPreds(predecessores, n);
	printPreds(distancias, n);
	/*if(ok){

		int k = r;
		int total = 0;
		while(predecessores[k] != r){
			int l = predecessores[k];
			total += matAdj[k][l];
			k = l;
		}

		if(total >= m)
			return total;
	}*/

	return -1;
}


bool ehAdjacente(vector<int> &adjacentes, int v){
	for(int i=0; i<(int) adjacentes.size(); i++)
		if(adjacentes[i] == v)
			return true;
	return false;
}

int dijkstra2(int n, int r, int m){

	//int predecessores[TAM];

	vector< vector<int> > predecessores(TAM);
	bool visitados[TAM];
	int distancias[TAM];
	
	for(int i=0; i<=n+1; i++){
		predecessores[i].push_back(-1);
		distancias[i] = INF;
		visitados[i] = false;
	}

	vector<int> vertices;
	vertices.push_back(r);
	distancias[r] = 0;

	while(!vertices.empty()){

		int u = extractMin(vertices, distancias);
		//distancias[u] = 0;

		int count = 0, count2=0;
		for(int v=1; v<=n; v++){
			
			if(matAdj[u][v] > 0){
				count2++;
			
				if(!ehAdjacente(predecessores[u], v)){
					int dist = distancias[u]+matAdj[u][v];
					if(dist < distancias[v]){
						distancias[v] = dist;
						
						vertices.push_back(v);
					}
					predecessores[v].push_back(u);
				}
				else
					count++;

			}

			if(count == count2 and count != 0){

				for(int i=1; i<=n; i++){
					if(predecessores[i] == predecessores[u] and i != u){
						predecessores[i].clear();
						predecessores[i].push_back(-1);
						distancias[i] = INF;
					}
				}
			}
		}
	}

	//printPreds(predecessores, n);
	for(int i=1; i<=n; i++){
		printf("%d: ", i);
		for(int j=1; j<(int) predecessores[i].size(); j++){
			printf("%d ", predecessores[i][j]);
		}
		printf("\n");
	}

	printPreds(distancias, n);
	/*if(ok){

		int k = r;
		int total = 0;
		while(predecessores[k] != r){
			int l = predecessores[k];
			total += matAdj[k][l];
			k = l;
		}

		if(total >= m)
			return total;
	}*/

	return -1;
}

int bfs(int n, int r, int m){

	int distancias[TAM];
	int predecessores[TAM];
	for(int i=0; i<=n+1; i++){
		distancias[i] = INF;
		predecessores[i] = -1;
	}

	queue<int> fila;
	fila.push(r);
	distancias[r] = 0;
	criaNovo(n, r);
	n++;

	while(!fila.empty()){

		int u = fila.front(); fila.pop();
		if(u == n)
			break;

		for(int v=1; v<=n; v++){
			if(matAdjNova[u][v] > 0){
				if(distancias[v] > distancias[u]+matAdjNova[u][v]){
					distancias[v] = distancias[u]+matAdjNova[u][v];
					predecessores[v] = u;
					fila.push(v);
				}
			}
		}
	}

	printPreds(predecessores, n);
	printPreds(distancias, n);
	return -1;

}

int dfs(int n, int r, int m){

	int distancias[TAM];
	int predecessores[TAM];
	for(int i=0; i<=n+1; i++){
		distancias[i] = INF;
		predecessores[i] = -1;
	}

	stack<int> fila;
	fila.push(r);
	distancias[r] = 0;
	criaNovo(n, r);
	n++;

	while(!fila.empty()){

		int u = fila.top(); fila.pop();
		if(u == n)
			break;

		for(int v=1; v<=n; v++){
			if(v != predecessores[u] and matAdjNova[u][v] > 0){
				if(distancias[v] > distancias[u]+matAdjNova[u][v]){
					distancias[v] = distancias[u]+matAdjNova[u][v];
					predecessores[v] = u;
					fila.push(v);
				}
			}
		}
	}

	printPreds(predecessores, n);
	printPreds(distancias, n);
	return -1;

}

int main(){

	int s, t, a, b, c, q, x, m;

	while(scanf("%d %d", &s, &t) != EOF){

		for(int i=0; i<=s; i++)
			for(int j=0; j<=s; j++)
				matAdj[i][j] = 0;

		while(t--){
			scanf("%d %d %d", &a, &b, &c);
			matAdj[a][b] = matAdj[b][a] = c;
		}

		scanf("%d", &q);
		while(q--){
			scanf("%d %d", &x, &m);
			//int total = dijkstra(s, x, m);
			//int total = prim(s, x);
			//int total = bfs(s, x, m);
			int total = dijkstra2(s, x, m);
			printf("%d\n", total);
		}

	}



	return 0;
}