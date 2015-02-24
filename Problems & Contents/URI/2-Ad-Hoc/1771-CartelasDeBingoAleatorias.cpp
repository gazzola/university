#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int, int> ii;


bool verifica(int *v, ii lim, int n){
	for(int i=0; i<n; i++)
		if(v[i] < lim.first or v[i] > lim.second)
			return false;
	return true;
}


int getLimit(int x){
	if(x >= 1 and x <= 15)
		return 0;

	if(x >= 16 and x <= 30)
		return 1;

	if(x >= 31 and x <= 45)
		return 2;

	if(x >= 46 and x <= 60)
		return 3;

	if(x >= 61 and x <= 75)
		return 4;

	return 5;
}



int main(){
	
	int b[5], i[5], n[5], g[5], o[5];
	ii lims[5];
	lims[0] = ii(1, 15);
	lims[1] = ii(16, 30);
	lims[2] = ii(31, 45);
	lims[3] = ii(46, 60);
	lims[4] = ii(61, 75);

	int count[6];

	while(scanf("%d", &b[0]) != EOF){

		int k = 0;
		scanf("%d %d %d %d", &i[k], &n[k], &g[k], &o[k]);

		k = 1;
		scanf("%d %d %d %d %d", &b[k], &i[k], &n[k], &g[k], &o[k]);

		k = 2;
		scanf("%d %d %d %d", &b[k], &i[k], &g[k], &o[k]);

		k = 3;
		scanf("%d %d %d %d %d", &b[k], &i[k], &n[2], &g[k], &o[k]);

		k = 4;
		scanf("%d %d %d %d %d", &b[k], &i[k], &n[3], &g[k], &o[k]);



		bool ok = true;
		ok = ok and verifica(b, lims[0], 5);
		ok = ok and verifica(i, lims[1], 5);
		ok = ok and verifica(n, lims[2], 4);
		ok = ok and verifica(g, lims[3], 5);
		ok = ok and verifica(o, lims[4], 5);


		if(!ok){

			for(int j=0; j<=5; j++)
				count[j] = 0;

			for(int j=0; j<5; j++){
				
				int x;
				x = getLimit(b[j]);
				count[x] += 1;

				x = getLimit(i[j]);
				count[x] += 1;

				if(j < 5){
					x = getLimit(n[j]);
					count[x] += 1;
				}

				x = getLimit(g[j]);
				count[x] += 1;

				x = getLimit(o[j]);
				count[x] += 1;

			}

			bool rec = true;
			rec = rec and count[0] == 5;
			rec = rec and count[1] == 5;
			rec = rec and count[2] == 4;
			rec = rec and count[3] == 5;
			rec = rec and count[4] == 5;

			if(rec)
				printf("RECICLAVEL\n");
			else
				printf("DESCARTAVEL\n");

		}
		else
			printf("OK\n");

	}
	

	
	return 0;
}