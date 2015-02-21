#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>


using namespace std;




bool bfs(vector<int> *arestas, vector<int> *chave, int n){

	deque<int> fila;
	
	bool visitado[1001];
	bool target[1001];

	memset(visitado, false, sizeof(visitado));
	memset(target, false, sizeof(target));

	for(int i=0; i<(int) arestas[1].size(); i++)
		fila.push_back(arestas[1][i]);
	
	visitado[1] = true;

	

	for(int i=0; i<(int) chave[1].size(); i++)
		target[chave[1][i]] = true;
	
	int count = 0;

	while(!fila.empty()){

		bool ok = false;
		for(int i=0; i<(int) fila.size(); i++){

			int u = fila[i];
			visitado[u] = true;

			if(target[u]){

				ok = true;
				target[u] = false;
				
				for(int j=0; j<(int) chave[u].size(); j++)
					target[chave[u][j]] = true;
				
				fila.erase(fila.begin()+i);
				count++;
			
				for(int j=0; j<(int) arestas[u].size(); j++){
					int v = arestas[u][j];
					if(!visitado[v])
						fila.push_back(v);
				}

				break;
			}
		}

		if(!ok)
			break;
	}


	if(count == n-1)
		return true;

	return false;
	
}




int main(){
	
	
	int n, m, a, b, k;
	

	while(scanf("%d %d", &n, &m) != EOF){

		vector<int> arestas[1001];
		vector<int> chave[1001];
		
		for(int i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			arestas[a].push_back(b);
			arestas[b].push_back(a);
		}

		

		for(int i=2; i<=n; i++){
			scanf("%d", &k);
			chave[k].push_back(i);
		}

		bool res = bfs(arestas, chave, n);
		
		if(res)
			printf("sim\n");
		else
			printf("nao\n");

	}




	return 0;
}