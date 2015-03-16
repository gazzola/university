#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int temp[231];
int resultado[3000001];

void countingSort(vector<int> &vet, int k){

	int tam = vet.size();
	for(int i=0; i<=k; i++)
		temp[i] = 0;

	for(int j=0; j<tam; j++)
		temp[vet[j]]++;

	for(int i=1; i<=k; i++)
		temp[i] += temp[i-1];

	for(int j=tam-1; j>=0; j--){
		resultado[temp[vet[j]]-1] = vet[j];
		temp[vet[j]]--;
	}
}


int main(){
 	
 	
	int t, n, x;
	
	scanf("%d", &t);
	while(t--){

		scanf("%d", &n);
		vector<int> vet;
		int k = 0;

		while(n--){
			scanf("%d", &x);
			k = max(k, x);
			vet.push_back(x);
		}

		countingSort(vet, k);

		printf("%d", resultado[0]);
		for(int i=1; i<(int) vet.size(); i++)
			printf(" %d", resultado[i]);
		printf("\n");
	}

 
	return 0;
}