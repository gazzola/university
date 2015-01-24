#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;
const int INF = 9999999;

int matAdj[1001][1001];



void imprimirCaminho(int *pred, int n){
	string s = "";
	int x = n-1;
	s += to_string(x);
	x = pred[x];

	while(x != -1){
		s += " >- "+to_string(x);
		x = pred[x];
	}

	reverse(s.begin(), s.end());
	cout << s << endl;
}



/*
* funciona para todos os casos
*/
int bfsPD(int n, int k, vector<int> *arestas){

	int dist[1005][1005];

	queue<ii> fila;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			dist[i][j] = INF;
	 

	dist[0][0] = 0;
	fila.push(ii(0, 0));
	int menor = INF;

	while(!fila.empty()){

		ii x = fila.front();
		fila.pop();
		
		int u = x.first;
		int p = x.second;

		if(p+2 > k)
			break;

		for(int i=0; i<(int) arestas[u].size(); i++){
			int v = arestas[u][i];
			if(dist[u][p] + matAdj[u][v] < dist[v][p+1]){

				if(dist[v][p+1] == INF)
					fila.push(ii(v, p+1));

				dist[v][p+1] = dist[u][p]+matAdj[u][v];

				if(p+1 < k and v == n-1)
					menor = min(menor, dist[v][p+1]);
			}
		}

	}

	return (menor == INF) ? -1 : menor;

}


/*
* funciona para a maioria dos casos e passa no URI
*/
int bfs(int n, int k, vector<int> *arestas){

	int dist[1001];
	int pred[1001];

	for(int i=0; i<n; i++){
		pred[i] = -1;
		dist[i] = INF;
	}

	queue<ii> fila;
	fila.push(ii(0, 0));
	dist[0] = 0;

	while(!fila.empty()){

		ii x = fila.front();
		fila.pop();

		int u = x.first;
		int p = x.second;

		if(p+1 >= k)
			break;

		for(int i=0; i<(int) arestas[u].size(); i++){
			int v = arestas[u][i];
			if(dist[u]+matAdj[u][v] < dist[v]){
				if(p+2 < k or v == n-1){
					pred[v] = u;
					fila.push(ii(v, p+1));
					dist[v] = dist[u]+matAdj[u][v];
				}
			}
		}
	}


	// for(int i=0; i<n; i++)
		// printf("%d ", dist[i]);
	// printf("\n");

	// imprimirCaminho(pred, n);

	return (dist[n-1]==INF) ? -1 : dist[n-1];

}




int main(){

	int t, n, m, k, a, b, c;

	scanf("%d", &t);
	while(t--){

		scanf("%d %d %d", &n, &m, &k);
		 
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				matAdj[i][j] = INF;

		 
		vector<int> arestas[1001];
		while(m--){
			scanf("%d %d %d", &a, &b, &c);
			if(matAdj[a][b] == INF)
				arestas[a].push_back(b);

			if(c < matAdj[a][b])
				matAdj[a][b] = c;
		}

		printf("%d\n", bfsPD(n, k, arestas));
		 
	}
	 



	return 0;
}