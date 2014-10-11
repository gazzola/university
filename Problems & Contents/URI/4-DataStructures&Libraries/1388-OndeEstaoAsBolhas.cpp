#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void bubbleInverse(int *vet, int n, vector<int> &mods, int m){

	for(int i=0; i<m; i++){

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



int main(){
 
	int n, m, x;
	int vet[100000];

	while(scanf("%d %d", &n, &m) and n > 0){

		for(int i=0; i<n; i++)
			vet[i] = i+1;

		vector<int> mods;
		for(int i=0; i<m; i++){
			scanf("%d", &x);
			mods.push_back(x);
		}


		bubbleInverse(vet, n, mods, m);

		for(int i=0; i<n; i++)
			printf("%d ", vet[i]);

		printf("\n");
	}
 
	return 0;
}