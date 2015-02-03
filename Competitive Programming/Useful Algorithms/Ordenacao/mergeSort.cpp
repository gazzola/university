/*
* Complexidade:
* Pior Caso: 	O(nlgn)
* Caso medio: 	O(nlgn)
* Melhor Caso:	O(nlgn)
*
* Memoria usada: 
* O(n) para vetor
* O(n) para auxiliar
*
* Estavel: sim
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../utils.h"

using namespace std;
const int MAX = 8;
const int INF = 999999;
int trocas = 0;



void myMerge(vector<int> &vet, int p, int q, int r){

	int n1 = q-p+1;
	int n2 = r-q;
	int i, j, k;

	vector<int> esq(n1+1);
	vector<int> dir(n2+1);

	for(i=0; i<n1; i++)
		esq[i] = vet[p+i];

	for(j=0; j<n2; j++)
		dir[j] = vet[q+j+1];

	esq[n1] = INF;
	dir[n2] = INF;
	i = j = 0;

	for(k=p; k<=r; k++){
		if(esq[i] <= dir[j]){
			vet[k] = esq[i];
			i++;
		}
		else{
			trocas += (n1-i);
			vet[k] = dir[j];
			j++;
		}
	}

}


void myMergeSort(vector<int> &vet, int p, int r){
	if(p < r){
		int q = (p+r)/2;
		myMergeSort(vet, p, q);
		myMergeSort(vet, q+1, r);
		myMerge(vet, p, q, r);
	}
}


void mergeSort(vector<int> &vet){
	
	if(vet.size() == 1)
		return;
 
	int m = vet.size()/2;
	vector<int> left(vet.begin(), vet.begin()+m);
	vector<int> right(vet.begin()+m, vet.end());
 
	mergeSort(left);
	mergeSort(right);

	merge(left.begin(), left.end(), right.begin(), right.end(), vet.begin());
}


int main(){

	srand(time(NULL));
	vector<int> vet;

	for(int i=0; i<MAX; i++)
		vet.push_back(rand()%MAX);

	printVector(vet);
	
	myMergeSort(vet, 0, MAX-1);
	printVector(vet);
	printf("Trocas: %d\n", trocas);
	

	return 0;
}