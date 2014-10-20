/*
* Complexidade:
* Pior Caso: 	O(n^2)
* Caso medio: 	O(n^2)
* Melhor Caso:	O(n)
*
* Memoria usada: 
* O(n) para vetor
* O(1) para auxiliar
*
* Estavel: sim
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 8;

void printVector(vector<int> &vet){
	for(int i=0; i<(int) vet.size(); i++)
		printf("%d ", vet[i]);
	printf("\n");
}


void bubbleSort(vector<int> &vet){

	int i, j, swaps;
	int tam = vet.size();

	for(i=0; i<tam; i++){

		swaps = 0;

		for(j=tam-1; j>=0; j--){
			if(vet[j-1] > vet[j]){
				swap(vet[j-1], vet[j]);
				swaps++;
			}
		}

		if(swaps == 0)
			break;
	}
}


int main(){

	srand(time(NULL));
	vector<int> vet;

	for(int i=0; i<MAX; i++)
		vet.push_back(rand()%MAX);
	

	printVector(vet);
	
	bubbleSort(vet);
	printVector(vet);
	

	return 0;
}