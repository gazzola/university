#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;


bool todasTocadas(bool *vis, int m){
	for(int i=1; i<=m; i++)
		if(!vis[i])
			return false;
	return true;
}


int main(){
	
	int m, k, x;
	int musicas[101];
	bool vis[101];

	while(scanf("%d %d", &m, &k) != EOF){

		memset(vis, false, sizeof(vis));
		for(int i=1; i<=m; i++)
			scanf("%d", &musicas[i]);

		int s = 0;
		int qtd = 0;

		while(k--){
			scanf("%d", &x);
			
			if(!vis[x]){
				qtd++;
				vis[x] = true;
			}

			if(qtd < m)
				s += musicas[x];
			else if(qtd == m){
				s += musicas[x];
				qtd++;
			}
		}

		if(todasTocadas(vis, m))
			printf("%d\n", s);
		else
			printf("-1\n");

	}
	
	return 0;
}