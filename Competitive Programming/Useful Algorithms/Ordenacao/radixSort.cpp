/*
* Complexidade:
* Pior Caso: 	O(d(n+b)) #d = digits | b = base (10)
* Caso medio: 	O(d(n+b))
* Melhor Caso:	O(d(n+b))
*
* Memoria usada: 
* O(n) para vetor
* O(n+s) para auxiliar
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



int numDigits(int n){
	if(n == 0)
		return 1;
	return (int) log10(abs(n)) + 1;
}


int getDigit(int value, int e){
	return (value/e)%10;
}

void countingSort(vector<int> &vet, int e){

	vector<int> temp(10);

	int tam = vet.size();
	vector<int> resultado(tam);

	for(int j=0; j<tam; j++)
		temp[getDigit(vet[j], e)]++;

	for(int i=1; i<10; i++)
		temp[i] += temp[i-1];

	for(int j=tam-1; j>=0; j--){
		resultado[temp[getDigit(vet[j], e)]-1] = vet[j];
		temp[getDigit(vet[j], e)]--;
	}

	vet = resultado;
}



void radixSort(vector<int> &vet, int greater){
	for(int e=1; (greater/e)>0; e*=10)
		countingSort(vet, e);
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
	
	radixSort(vet, k);
	printVector(vet);
	

	return 0;
}