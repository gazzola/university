/*
* Complexidade:
* Pior Caso: 	O(n^2)
* Caso medio: 	O(nlgn)
* Melhor Caso:	O(nlgn)
*
* Memoria usada: 
* O(n) para vetor
* O(logn) para auxiliar
*
* Estavel: Nao
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../utils.h"

using namespace std;
const int MAX = 8;




int partition(vector<int> &vet, int p, int r){

	int x = vet[r];
	int i = p-1;

	for(int j=p; j<r; j++)
		if(vet[j] <= x)
			swap(vet[++i], vet[j]);

	swap(vet[++i], vet[r]);
	return i;
}


// pivo aleatorio
int randPartition(vector<int> &vet, int p, int r){
	int i = (rand()%(r-p+1))+p;
	swap(vet[p], vet[i]);
	return partition(vet, p, r);
}


void quickSort(vector<int> &vet, int p, int r, bool random){

	if(p < r){
		
		int q; 
		if(random)
			q = randPartition(vet, p, r);
		else
			q = partition(vet, p, r);
		
		quickSort(vet, p, q-1, random);
		quickSort(vet, q+1, r, random);
	}
}


void quickSortIter(vector<int> &vet, int p, int r, bool random){

	int stack[r-p+1];
	int top = -1;

	// push
	stack[++top] = p;
	stack[++top] = r;

	while(top >= 0){

		// pop
		r = stack[top--];
		p = stack[top--];

		int q; 
		if(random)
			q = randPartition(vet, p, r);
		else
			q = partition(vet, p, r);

		if(q-1 > p){
			stack[++top] = p;
			stack[++top] = q-1;
		}

		if(q+1 < r){
			stack[++top] = q+1;
			stack[++top] = r;
		}
	}
}


int main(){

	srand(time(NULL));
	vector<int> vet;

	for(int i=0; i<MAX; i++)
		vet.push_back(rand()%MAX);
	

	printVector(vet);
	
	quickSort(vet, 0 , MAX-1, true);
	printVector(vet);
	

	return 0;
}