/*
* Complexidade:
* Pior Caso: 	O(n^2)
* Caso medio: 	O(n^2)
* Melhor Caso:	O(n^2)
*
* Memoria usada: 
* O(n) para vetor
* O(1) para auxiliar
*
* Estavel: Nao
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 6;

void printVector(vector<int> &vet){
	for(int i=0; i<(int) vet.size(); i++)
		printf("%d ", vet[i]);
	printf("\n");
}



int findMin(vector<int> &vet, int i){
	int lower = vet[i];
	int j;
	for(j=i+1; j<(int) vet.size(); j++)
		if(vet[lower] < vet[j])
			lower = j;
	return lower;
}


void selectionSort(vector<int> &vet){

	int tam = vet.size();
	int j, i;

	for(i=0; i<tam; i++){
		j = findMin(vet, i);
		swap(vet[i], vet[j]);
	}
	
}


int main(){

	srand(time(NULL));
	vector<int> vet;

	for(int i=0; i<MAX; i++)
		vet.push_back(rand()%MAX);

	printVector(vet);
	
	selectionSort(vet);
	printVector(vet);



	return 0;
}