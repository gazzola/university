#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;
 
const int TAM = 100001;
const int INF = 9999999;
 
int vet[TAM], esq[TAM], dir[TAM];
int invs;
 
 
void merge(int *vet, int p, int q, int r){
 
	int n1 = q-p+1;
	int n2 = r-q;
	int i, j, k;
 
 
	for(i=0; i<n1; i++)
		esq[i] = vet[p+i];
 
	for(j=0; j<n2; j++)
		dir[j] = vet[q+j+1];
 
	esq[n1] = INF;
	dir[n2] = INF;
	i = j = 0;
 
 
	for(k=p; k<=r; k++){
		if(esq[i] <= dir[j])
			vet[k] = esq[i++];
		else{
			invs += (n1-i);
			vet[k] = dir[j++];
		}
	}
 
}
 
 
void mergeSort(int *vet, int p, int r){
	if(p < r){
		int q = (p+r)/2;
		mergeSort(vet, p, q);
		mergeSort(vet, q+1, r);
		merge(vet, p, q, r);
	}
}
 
 
 
 
int main(){
	 
	 
	int t, n;
	bool cresente, decresc;


	scanf("%d", &t);
	while(t--){
 	

		cresente = decresc = true;
		invs = 0;

		scanf("%d", &n);
		scanf("%d", &vet[0]);
 
		for(int i=1; i<n; i++){
			scanf("%d", &vet[i]);
 
			if(vet[i-1] > vet[i])
				cresente = false;
			else if(vet[i-1] < vet[i])
				decresc = false;
		}
		 
 
		if(cresente){
			printf("Optimal train swapping takes 0 swaps.");
		}
		else if(decresc){
			invs = n*(n-1)/2;
			printf("Optimal train swapping takes %d swaps.", invs);
		}
		else{
			mergeSort(vet, 0, n-1);
			printf("Optimal train swapping takes %d swaps.", invs);
		}
 
		printf("\n");
		
	}
	 
 
	return 0;
}