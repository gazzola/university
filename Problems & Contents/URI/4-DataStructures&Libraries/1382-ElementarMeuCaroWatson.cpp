#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

	int t, n;
	int pos[10001];
	int vet[10001];

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		int invs = 0;
		for(int i=1; i<=n; i++){
			scanf("%d", &vet[i]);
			pos[vet[i]] = i;
		}
		
		for(int i=1; i<=n; i++){
			if(vet[i] != i){
				invs++;
				vet[pos[i]] = vet[i];
				pos[vet[i]] = pos[i];
				vet[i] = pos[i] = i;
			}
		}


		printf("%d\n", invs);
	}


	return 0;
}