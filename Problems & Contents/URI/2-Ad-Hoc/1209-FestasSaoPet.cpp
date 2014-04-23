#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, k, x1, x2;
int amigos[1002], relacoes[1002][1002];

void remover(int i){
	amigos[i] = 0;
	for(int j=1; j<=n; j++){
		if(relacoes[i][j]){
			relacoes[i][j] = 0;
			relacoes[j][i] = 0;
			amigos[j]--;
			if(amigos[j] > 0 && amigos[j] < k)
				remover(j);
		}
	}
}


int main(){
	
	

	while(scanf("%d %d %d ", &n, &m, &k) != EOF){
		
		memset(amigos, 0, sizeof(amigos));
		memset(relacoes, 0, sizeof(relacoes));

		for(int i=0; i<m; i++){
			//cin >> x1 >> x2;
			scanf("%d %d ", &x1, &x2);

			relacoes[x1][x2] = 1;
			relacoes[x2][x1] = 1;
			amigos[x1]++;
			amigos[x2]++;
		}

		
		for(int i=1; i<=n; i++)
			if(amigos[i] > 0 && amigos[i] < k)
				remover(i);

		bool zero=true;
		for(int i=1; i<=n; i++){
			if(amigos[i] >= k){
				if(zero)
					printf("%d", i);	
				else
					printf(" %d", i);

				zero = false;
			}
		}

		if(zero)
			printf("0");
	
		printf("\n");
	}



	return 0;
}