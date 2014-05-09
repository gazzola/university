#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


const double INF = 9999999;
typedef pair<int, int> ii;
double matAdj[510][510];


double distancia(ii p1, ii p2){
	double x = p2.first-p1.first;
	double y = p2.second-p1.second;
	return sqrt((x*x) + (y*y));
}

bool isSet(vector<int> &vertices, int v){
	return binary_search(vertices.begin(), vertices.end(), v);
}


int extractMin(vector<int> &vertices, double *chave){
	
	int menor=vertices[0], pos=0;
	for(int i=0; i<vertices.size(); i++){
		if(chave[vertices[i]] < chave[menor]){
			menor = vertices[i];
			pos = i;
		}
	}

	vertices.erase(vertices.begin()+pos); //remove(v[i]);
	return menor;
}


void prim(vector<int> &vertices, int r, double *chave, int *pi){

	for(int i=0; i<vertices.size(); i++){
		chave[i] = INF;
		pi[i] = -1;
	}

	chave[r] = 0;
	int tam = vertices.size();
	map<int, int> posicao;

	while(vertices.size() > 0){
		int u = extractMin(vertices, chave);
		posicao[u] = 1;

		for(int v=0; v<tam; v++){
			if(matAdj[u][v] > 0){
				if(!posicao.count(v) && matAdj[u][v] < chave[v]){
					chave[v] = matAdj[u][v];
					pi[v] = u;
				}
			}
		}
	}

}


int main(){

	int c, n, x, y;

	scanf("%d", &c);
	while(c--){

		vector<ii> pessoas;
		vector<int> vertices;

		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%d %d", &x, &y);
			pessoas.push_back(ii(x, y));
			vertices.push_back(i);

			for(int j=0; j<n; j++)
				matAdj[i][j] = 0;

			for(int j=i; j>=0; j--)
				matAdj[i][j] = matAdj[j][i] = distancia(pessoas[i], pessoas[j]);
		}


		double chave[10001], soma=0;
		int pi[10001];

		prim(vertices, 0, chave, pi);
		for(int i=1; i<n; i++)
			soma += matAdj[i][pi[i]];

		printf("%.2lf\n", soma/100.0); //em metros

	}


	return 0;
}
