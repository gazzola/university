/*
* Complexidade:
* Pior Caso: 	O(n^2)
* Caso medio: 	O()
* Melhor Caso:	O(n+k)
*
* Memoria usada: 
* O(n) para vetor
* O(n.k) para auxiliar
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




void bucketSort(vector<float> &vet){

	int tam = vet.size();
	vector<float> temp[tam];

	for(int i=0; i<tam; i++){
		int index = tam*vet[i];
		temp[index].push_back(vet[i]);
	}

	for(int i=0; i<tam; i++)
		sort(temp[i].begin(), temp[i].end());

	int k = 0;
	for(int i=0; i<tam; i++)
		for(int j=0; j<(int) temp[i].size(); j++)
			vet[k++] = temp[i][j];
}




int main(){

	srand(time(NULL));
	vector<float> vet;

	for(int i=0; i<MAX; i++){
		float x = ((rand()%100)+1)/100.0;
		vet.push_back(x);
	}
	

	printVector(vet);
	
	bucketSort(vet);
	printVector(vet);
	

	return 0;
}