#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


typedef long long unsigned int llu;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void bubbleInverse(int *vet, int n, vector<int> &mods, int m){

	for(int i=0; i<m; ++i){

		int trocas = 0;
		for(int j=0; j<n-1; j++){
			if(vet[j] < vet[j+1]){
				swap(vet[j], vet[j+1]);
				trocas++;
			}
			if(trocas == mods[i])
				break;
		}
	}
}

void printVet(int *vet, int n){
	for(int i=0; i<n; ++i)
		printf("%d ", vet[i]);
	printf("\n");
}




void bubbleReverse(int *vet, int n, int *mods, int m){

	int pos = 0;
	int ele = 0;

	for(int i=0; i<m; ++i){
		pos = mods[i];
		while(vet[pos] > 0)
			++pos;

		vet[pos] = ++ele;
	}

	int k = m;
	for(int i=0; i<n; ++i)
		if(vet[i]==0)
			vet[i] = ++k;
}



int main(){
 
	int n, m, x;
	int vet[100000];
	int mods[100001];

	while(scanf("%d %d", &n, &m) and n > 0){

		memset(vet, 0, sizeof(vet));
		
		for(int i=0; i<m; ++i){
			scanf("%d", &x);
			mods[i] = x;
		}


		bubbleReverse(vet, n, mods, m);

		printf("%d", vet[0]);
		for(int i=1; i<n; ++i)
			printf(" %d", vet[i]);

		printf("\n");
	}
 
	return 0;
}