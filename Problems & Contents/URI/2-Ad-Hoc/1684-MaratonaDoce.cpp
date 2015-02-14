#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;




int main(){
	
	
	int t, n, m, a, b;
	int arestas[10001];

	scanf("%d", &t);
	while(t--){

		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
			arestas[i] = 0;

		for(int i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			arestas[a] += 1;
			arestas[b] += 1;
		}

		// se tem circuito disjunto, quer dizer 
		// que tem um caminho euleriano:
		// http://pt.wikipedia.org/wiki/Caminho_euleriano

		// Um grafo G conexo possui caminho euleriano se 
		// e somente se ele tem exatamente zero ou dois 
		// vértices de grau impar.

		int qtdImpar = 0;
		for(int i=0; i<n; i++){
			if(arestas[i]%2 != 0){
				qtdImpar++;
				break;
			}
		}

		if(qtdImpar == 0)
			printf("Yes\n");
		else
			printf("No\n");

	}

	
	return 0;
}