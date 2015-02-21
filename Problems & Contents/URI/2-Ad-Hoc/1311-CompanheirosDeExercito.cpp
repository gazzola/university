#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int, int> ii;



int main(){
	
	int s, b, l, r;
	ii soldados[100005];

	while(scanf("%d %d", &s, &b) and s > 0){

		for(int i=1; i<=s; i++)
			soldados[i] = ii(i-1, i+1);

		while(b--){
			scanf("%d %d", &l, &r);
			
			/*
			// O(sb) = TLE
			for(int i=l; i<=r; i++)
				soldados[i] = -1;

			int j = l-1;
			while(true){
				if(soldados[j] > 0 and soldados[j] <= s)
					break;
				j--;
			}

			int k = r+1;
			while(true){
				if(soldados[k] > 0 and soldados[k] <= s)
					break;
				k++;
			}

			int esq = j;
			int dir = k;
			*/

			int esq = soldados[l].first;
			int dir = soldados[r].second;

			if(esq > 0 and esq <= s){
				printf("%d ", esq);
				soldados[esq].second = dir;
			}
			else
				printf("* ");
			
			if(dir > 0 and dir <= s){
				printf("%d", dir);
				soldados[dir].first = esq;
			}
			else
				printf("*");

			printf("\n");
		}

		printf("-\n");
	}


	
	return 0;
}