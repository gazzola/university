#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define INF 9999999;


double mat[10001][10001];
typedef pair<double, double> dd;


double distancia(double x1, double y1, double x2, double y2){
	double x = x2-x1;
	double y = y2-y1;
	return sqrt((x*x) + (y*y));
}


void ligar(dd p1, dd p2, int i, int j){
	double d = distancia(p1.first, p1.second, p2.first, p2.second);
	mat[i][j] = d;
	mat[j][i] = d;
}




int main(){

	int c, n;
	double x, y;

	scanf("%d", &c);
	while(c--){

		vector <dd> pessoas;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%lf %lf", &x, &y);
			pessoas.push_back(dd(x, y));
		}



		memset(mat, 0, sizeof(mat));
		for(int i=0; i<n-1; i++)
			for(int j=0; j<n; j++)
				if(i != j)
					ligar(pessoas[i], pessoas[j], i, j);


		//prim ou kruskal
		//vai dar tle certamente
	

		/*sort(pessoas.begin(), pessoas.end(), myOrder<double>);

		int tam = pessoas.size();
		double total = 0;

		for(int i=1; i<tam; i++){
			int ca = pessoas[i].first - pessoas[i-1].first;
			int co = pessoas[i].second - pessoas[i-1].second;
			total += sqrt((ca*ca) + (co*co));
		}

		printf("%.2lf\n", total/100);*/
	}


	return 0;
}