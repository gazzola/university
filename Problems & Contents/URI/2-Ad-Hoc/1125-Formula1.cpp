#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;



int main(){
	
	int g, p, s, k, x;
	int pontos[100];

	while(scanf("%d %d", &g, &p) and g > 0){

		vector<int> ordens[100];

		for(int i=0; i<g; i++){
			for(int j=0; j<p; j++){
				scanf("%d", &x);
				ordens[j].push_back(x-1);
			}
		}

		scanf("%d", &s);
		int n;


		while(s--){

			scanf("%d", &k);

			vector<int> maiores;
			int maior = 0;
			memset(pontos, 0, sizeof(pontos));

			for(int i=0; i<k; i++)
				scanf("%d", &pontos[i]);

			for(int i=0; i<p; i++){
				n = ordens[i].size();
				int m = 0;
				for(int j=0; j<n; j++)
					m += pontos[ordens[i][j]];
				
				if(m > maior){
					maior = m;
					maiores.clear();
					maiores.push_back(i);
				}
				else if(m == maior){
					maiores.push_back(i);
				}
			}
		
			sort(maiores.begin(), maiores.end());
		
			printf("%d", maiores[0]+1);
			for(int i=1; i<(int) maiores.size(); i++)
				printf(" %d", maiores[i]+1);
			printf("\n");
		}

	}
	
	return 0;
}