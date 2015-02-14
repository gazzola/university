#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;




int main(){
	
	
	int n, x;
	int vet[100001];
	vet[0] = 0;

	while(scanf("%d", &n) and n > 0){

		for(int i=1; i<=n; i++)
			vet[i] = 0;
		// memset(vet, 0, sizeof(vet));

		bool ok = true;
		for(int i=1; i<=n; i++){
			scanf("%d", &x);
			vet[i] = x;
			if(vet[x] != 0 and vet[x] != i)
				ok = false;
		}

		if(ok)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");

	}


	
	return 0;
}