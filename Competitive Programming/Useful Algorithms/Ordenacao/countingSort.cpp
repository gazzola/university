/*
* Complexidade:
* Pior Caso: 	O(n+k)
* Caso medio: 	O(n+k)
* Melhor Caso:	O(n+k)
*
* Memoria usada: 
* O(n) para vetor
* O(n) para auxiliar
*
* Estavel: Sim
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../utils.h"

using namespace std;
const int MAX = 8;



void countingSort(vector<int> &vet, int k){

	vector<int> temp(k);

	int tam = vet.size();
	vector<int> resultado(tam);

	for(int j=0; j<tam; j++)
		temp[vet[j]]++;

	for(int i=1; i<=k; i++)
		temp[i] += temp[i-1];

	for(int j=tam-1; j>=0; j--){
		resultado[temp[vet[j]]-1] = vet[j];
		temp[vet[j]]--;
	}

	vet = resultado;
}




int main(){

	srand(time(NULL));
	vector<int> vet;

	int k = 0;
	for(int i=0; i<MAX; i++){
		int x = rand()%MAX;
		if(x > k)
			k = x;
		vet.push_back(x);
	}
	

	printVector(vet);
	
	countingSort(vet, k);
	printVector(vet);
	

	return 0;
}