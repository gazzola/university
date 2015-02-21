#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){

	
	bool vet[10000];
	memset(vet, false, sizeof(vet));

	int n, r, x;
	int count = 0;

	
	scanf("%d ", &n);
	scanf("%d", &r);

	for(int i=0; i<r; i++){
		scanf("%d", &x);
		x--;
		if(!vet[x]){
			vet[x] = true;
			count++;
		}
	}
	
	if(count == n){
		printf("* ");
	}
	else{
		for(int i=0; i<n; i++){
			if(!vet[i])
				printf("%d ", i+1);			
		}
	}

	printf("\n");


	return 0;
}