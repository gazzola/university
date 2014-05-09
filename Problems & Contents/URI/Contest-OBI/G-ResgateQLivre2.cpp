#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


#define INF 9999999;


typedef pair<int, int> ii;
double matAdj[10001][10001];


double distancia(ii p1, ii p2){
	double x = p2.first-p1.first;
	double y = p2.second-p1.second;
	return sqrt((x*x) + (y*y));
}

template <class T>
void printVector(const vector<T> &v){
	for(int i=0; i<v.size(); i++)
		printf("(%d, %d)  ", v[i].first, v[i].second);
 	printf("\n");
}


void showVector(vector<int> &v){
	for(int i=0; i<v.size(); i++)
		printf("%d ", v[i]);
 	printf("\n");
}


template <class T>
bool orderBy(const pair<T, T> &i, const pair<T, T> &j){
	ii temp = ii(0, 0);
	return (distancia(temp, i) < distancia(temp, j));
}


//bsearch
int isSet(vector<int> &vertices, int v){
	for(int i=0; i<vertices.size(); i++)
		if(vertices[i] == v)
			return true;
	return false;
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


void *prim(vector<int> &vertices, int r, double *chave, int *pi){

	for(int i=0; i<vertices.size(); i++){
		chave[i] = INF;
		pi[i] = -1;
	}

	chave[r] = 0;
	int tam = vertices.size();
	vector<int> arvore;

	while(vertices.size() > 0){
		int u = extractMin(vertices, chave);

		for(int v=0; v<tam; v++){
			if(matAdj[u][v] > 0){
				if(isSet(vertices, v) && matAdj[u][v] < chave[v]){
					chave[v] = matAdj[u][v];
					pi[v] = u;
				}
			}
		}
	}

}




int main(){

	int c, n;
	double x, y;

	scanf("%d", &c);
	while(c--){

		vector<ii> pessoas;
		vector<int> vertices;

		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%lf %lf", &x, &y);
			pessoas.push_back(ii(x, y));
			vertices.push_back(i);

			for(int j=0; j<n; j++)
				matAdj[i][j] = 0;

			for(int j=i; j>=0; j--)
				matAdj[i][j] = matAdj[j][i] = distancia(pessoas[i], pessoas[j]);
		}


		double soma = 0;
		double chave[10001];
		int pi[10001];

		prim(vertices, 0, chave, pi);
		for(int i=1; i<n; i++)
			soma += matAdj[i][pi[i]];

		printf("%.2lf\n", soma/100); //em metros


		/*
		printVector(pessoas);
		sort(pessoas.begin(), pessoas.end(), orderBy<int>);
		printVector(pessoas);

		int tam = pessoas.size();
		double soma = 0;
		ii last = pessoas[0];
 
		for(int i=1; i<tam; i++){
 			soma += distancia(last, pessoas[i]);
			last = pessoas[i];
		}

		printf("%.2lf\n", soma/100.0); //em metros
		*/


		/*int i=0;
		double menor, soma=0;

		while(pessoas.size() > 0){

			ii atual = pessoas[i]; 
			pessoas.erase(pessoas.begin()+i); //remove(v[i]);
			menor = INF;

			for(int j=0; j<pessoas.size(); j++){
				double dist = distancia(atual, pessoas[j]);
				if(dist < menor){
					menor = dist;
					i = j;
				}
			}
			
			soma += distancia(atual, pessoas[i]);

		}

		printf("%.2lf\n", soma/100.0); //em metros
		*/


	}


	return 0;
}
