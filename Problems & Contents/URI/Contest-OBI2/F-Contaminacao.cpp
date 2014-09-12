#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> ii;


bool posicoesValidas(ii posicao, int n, int m){
	int x = posicao.first;
	int y = posicao.second;

	if(x >= 0 and x < n and y >= 0 and y < m)
		return true;

	return false;
}


int main(){

	int n, m;

	while(true){

		scanf("%d %d", &n, &m);

		if(n == 0 and m == 0)
			break;

		char mapa[51][51], c;
		bool visitados[51][51];
		stack<ii> contaminados; // fizemos um dfs 

		for(int i=0; i<n; i++){
			
			scanf("%c", &c); // le o \n 

			for(int j=0; j<m; j++){
				
				scanf("%c", &c);
				mapa[i][j] = c;
				visitados[i][j] = false;

				if(c == 'T'){
					contaminados.push(ii(i, j));
					visitados[i][j] = true;
				}
			}			
		}


		while(!contaminados.empty()){
			ii proximo = contaminados.top();
			contaminados.pop();

			int x = proximo.first;
			int y = proximo.second;

			mapa[x][y] = 'T';
			visitados[x][y] = true;

			ii norte = ii(x-1, y);
			ii sul = ii(x+1, y);
			ii oeste = ii(x, y-1);
			ii leste = ii(x, y+1);

			if(posicoesValidas(norte, n, m)){
				int xx = norte.first;
				int yy = norte.second;
				if(!visitados[xx][yy] and mapa[xx][yy] == 'A')
					contaminados.push(norte);
			}

			if(posicoesValidas(sul, n, m)){
				int xx = sul.first;
				int yy = sul.second;
				if(!visitados[xx][yy] and mapa[xx][yy] == 'A')
					contaminados.push(sul);
			}

			if(posicoesValidas(oeste, n, m)){
				int xx = oeste.first;
				int yy = oeste.second;
				if(!visitados[xx][yy] and mapa[xx][yy] == 'A')
					contaminados.push(oeste);
			}

			if(posicoesValidas(leste, n, m)){
				int xx = leste.first;
				int yy = leste.second;
				if(!visitados[xx][yy] and mapa[xx][yy] == 'A')
					contaminados.push(leste);
			}

		}

	
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				printf("%c", mapa[i][j]);
			}
			printf("\n");
		}

		printf("\n");



	}

	return 0;
}