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
#include "../utils.h"

using namespace std;
const int MAX = 6;



void insertionSort(vector<int> &vet){

	int tam = vet.size();
	int chave, j, i;

	for(i=1; i<tam; i++){
		
		chave = vet[i];
		j = i-1; 
		
		while(vet[j] > chave and j >= 0){
			vet[j+1] = vet[j];
			j--;
		}
		
		vet[j+1] = chave;
	}
}


int main(){

	srand(time(NULL));
	vector<int> vet;

	for(int i=0; i<MAX; i++)
		vet.push_back(rand()%MAX);

	printVector(vet);
	
	insertionSort(vet);
	printVector(vet);
	

	return 0;
}