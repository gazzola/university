#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;



typedef long long unsigned int llu;
typedef pair<int, int> ii;

const int MAX = 10001;
const int INF = 0x3f3f3f3f;
int dist[MAX];


int dijkstra(int ini, int fim, vector<ii> *G){

	int u, v, i, c, w;
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	
	memset(dist, INF, sizeof(dist));
	dist[ini] = 0;
	Q.push(ii(0, ini));


	while(!Q.empty()){
		u = Q.top().second;
		c = Q.top().first;
		Q.pop();

		if(dist[u] < c)
			continue;

		if(u == fim)
			return dist[u];


		for(i=0; i<(int) G[u].size(); i++){
			v = G[u][i].first;
			w = G[u][i].second;

			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				Q.push(ii(dist[v], v));
			}
		}

	}

	return dist[fim];
}




int main(){
	
	
	int n, c, s, b, x, y, d;
	int pos_ini, pos_fim;
	int posBan[MAX];
	vector<ii> G_POL[MAX], G_BAN[MAX];

	scanf("%d %d %d %d", &n, &c, &s, &b);


	for(int i=0; i<c; i++){
		scanf("%d %d %d", &x, &y, &d);
		G_POL[x-1].push_back(ii(y-1, d));
		G_POL[y-1].push_back(ii(x-1, d));

		G_BAN[x-1].push_back(ii(y-1, d));
		G_BAN[y-1].push_back(ii(x-1, d));
	}

	for(int i=0; i<s; i++){
		scanf("%d %d %d", &x, &y, &d);
		G_BAN[x-1].push_back(ii(y-1, d));
		G_BAN[y-1].push_back(ii(x-1, d));
	}


	for(int i=0; i<b; i++)
		scanf("%d", &posBan[i]);
	
	scanf("%d %d", &pos_ini, &pos_fim);

	int t, qtdBans = 0;
	int tempoBino = dijkstra(pos_ini-1, pos_fim-1, G_POL);
	t = dijkstra(pos_fim-1, -1, G_BAN);

	for(int i=0; i<b; i++){
		t = dist[posBan[i]-1];
		if(t <= tempoBino)
			qtdBans++;	
	}

	printf("%d\n", qtdBans);
}
