/*
* Complexidade:
* Pior Caso: 	O(n^2)
* Caso medio: 	O(n) 
* Melhor Caso:	O(n) elementos distintos
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

// pivo mediana
int medPartition(vector<int> &vet, int p, int r){
	int i = (p+r)/2;
	swap(vet[p], vet[i]);
	return partition(vet, p, r);
}


int randomizedSelect(vector<int> &vet, int p, int r, int i){
	
	if(p == r)
		return vet[p];

	int q = randPartition(vet, p, r);
	int k = q-p+1;

	if(k == i)
		return vet[q];
	else if(i < k)
		return randomizedSelect(vet, p, q-1, i);

	return randomizedSelect(vet, q+1, r, i-k);
}


// usa o algoritmo select por tras dos panos
int select(vector<int> &vet, int i){
	nth_element(vet.begin(), vet.begin()+i-1, vet.end());
	return vet[i-1];
}



int main(){

	srand(time(NULL));
	vector<int> vet;


	for(int i=0; i<MAX; i++){
		int x = rand()%MAX;
		vet.push_back(x);
	}

	printVector(vet);

	int ele = randomizedSelect(vet, 0, MAX-1, 2); // second element
	int ele2 = select(vet, 2);

	sort(vet.begin(), vet.end());
	printVector(vet);

	cout << ele << endl;
	cout << ele2 << endl;
	

	return 0;
}