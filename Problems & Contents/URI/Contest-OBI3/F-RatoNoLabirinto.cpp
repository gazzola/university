#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef vector<string> vs;
typedef pair<string, int> si;
typedef pair<string, string> ss;

const int INF = 9999999;


int bfs(map<string, vs> &arestas, string from, string to){

	queue<si> fila;
	set<string> vis;

	fila.push(si(from, 1));
	vis.insert(from);

	while(!fila.empty()){

		si u = fila.front();
		fila.pop();

		if(u.first == to)
			return u.second;

		for(int i=0; i<arestas[u.first].size(); i++){
			string v = arestas[u.first][i];
			if(vis.find(v) == vis.end()){
				vis.insert(v);
				fila.push(si(v, u.second+1));
			}
		}
	}

	return 0;
}




int main(){
	
	int n, m, x;
	scanf("%d %d\n", &n, &m);

	map<string, vs> arestas;
	vs vertices;

	string a, b;

	while(m--){
		cin >> a >> b;
		arestas[a].push_back(b);
		arestas[b].push_back(a);
	}


	x = bfs(arestas, "Entrada", "*");
	x += bfs(arestas, "*", "Saida");
	printf("%d\n", x-2);
	

}
