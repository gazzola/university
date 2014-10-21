/*
* Complexidade:
* Pior Caso: 	O(n)
* Caso medio: 	O(n)
* Melhor Caso:	O(n)
*
* Memoria usada: 
* O(n) para vetor
* O(1) para auxiliar
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../utils.h"

using namespace std;
const int MAX = 8;


void minAndMax(vector<int> &vet, int *min, int *max){

	int menor, maior;
	menor = maior = 0;

	for(int i=1; i<(int) vet.size(); i++){
		if(vet[i] > vet[maior])
			maior = i;
		else if(vet[i] < vet[menor])
			menor = i;
	}

	*min = vet[menor];
	*max = vet[maior];
}



int main(){

	srand(time(NULL));
	vector<int> vet;


	for(int i=0; i<MAX; i++){
		int x = rand()%MAX;
		vet.push_back(x);
	}
	

	printVector(vet);
	
	int menor = *min_element(vet.begin(), vet.end());
	int maior = *max_element(vet.begin(), vet.end());
	cout << "min: " << menor << endl;
	cout << "max: " << maior << endl;

	minAndMax(vet, &menor, &maior);
	cout << "min: " << menor << endl;
	cout << "max: " << maior << endl;
	

	return 0;
}