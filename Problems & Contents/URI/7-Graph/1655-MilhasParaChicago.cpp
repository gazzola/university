#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;


typedef pair<int, double> id;


const int INF = 9999999;
double matAdj[101][101];


void floydWarshall(int n){
	int i, j, k;
	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				if(matAdj[i][k]*matAdj[k][j] > matAdj[i][j])
					matAdj[i][j] = matAdj[i][k]*matAdj[k][j];
}



struct lessOrder{
	bool operator()(const id &l, const id &r) const{
		return (l.second > r.second);
	}
};


double dijkstra(int s, int n){

	double dist[101];
	//bool visit[101];
	queue<int> fila;
	
	
	for(int v=0; v<n; v++){
		dist[v] = 0;
		//visit[v] = false;
	}

	dist[s] = 1;
	fila.push(s);

	while(!fila.empty()){

		int u = fila.front(); 
		fila.pop();

		//visit[u] = true;

		for(int v=0; v<n; v++){
			if(matAdj[u][v] > 0 /*and !visit[v]*/){
				double aux = matAdj[u][v]*dist[u];
				if(aux > dist[v]){
					dist[v] = aux;
					fila.push(v);
				}
			}
		}
	}

	return dist[n-1];

}


int main(){

	int n, m, a, b, p;

	while(scanf("%d", &n) and n > 0){

		if(n == 0)
			break;

		memset(matAdj, 0, 101*n*sizeof(matAdj[0][0]));

		scanf("%d", &m);
		for(int i=0; i<m; i++){
			scanf("%d %d %d", &a, &b, &p);
			matAdj[a-1][b-1] = matAdj[b-1][a-1] = p/100.0;
		}

		// floydWarshall(n);
		// printf("%.6lf percent\n", matAdj[0][n-1]*100);
		printf("%.6lf percent\n", dijkstra(0,n)*100);
	}



	return 0;
}