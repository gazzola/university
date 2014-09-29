#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


typedef pair<int, double> id;
const double INF = 999999;


double menorCusto(vector<int> &lista, vector<id> &produtos, int m, int n){

	double minCustoAnt[105];
	double minCusto[105];
	

	minCusto[0] = 0;
	for(int i=1; i<=m; i++){
		minCustoAnt[i] = INF;
		minCusto[i] = INF;
	}


	for(int i=0; i<n; i++){

		int eleProd = produtos[i].first;
		double custo = produtos[i].second;

		for(int j=1; j<=m; j++){

			int eleList = lista[j-1];
			if(eleList == eleProd)
				minCusto[j] = min(minCustoAnt[j], minCustoAnt[j-1]+custo);
			else
				minCusto[j] = minCustoAnt[j];

		}

		for(int j=0; j<=m; j++)
			minCustoAnt[j] = minCusto[j];
	}


	return minCusto[m];

}




int main(){
	

	int m, n, x;
	double y;
	

	while(scanf("%d %d", &m, &n) and n > 0){

		vector<int> itensLista;
		vector<id> produtos;

		for(int i=0; i<m; i++){
			scanf("%d", &x);
			itensLista.push_back(x);
		}

		for(int i=0; i<n; i++){
			scanf("%d %lf", &x, &y);
			produtos.push_back(id(x,y));
		}

		double custo = menorCusto(itensLista, produtos, m, n);
		if(custo == INF)
			printf("Impossible\n");
		else
			printf("%.2lf\n", custo);
	}
	
	
	return 0;
}