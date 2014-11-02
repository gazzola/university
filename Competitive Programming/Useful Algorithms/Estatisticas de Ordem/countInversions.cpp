/*
* Complexidade:
* Pior Caso: 	O(n^2)
* Caso medio: 	O(n^2)
* Melhor Caso:	O(n^2)
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
const int INF = 999999;


int countInvsBruteForce(vector<int> &vet){
	
	int invs = 0;
	int n = vet.size();

	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(vet[i] > vet[j])
				invs++;

	return invs;
}

// using merge-sort:
// O(logn) comp time and O(n) memory

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



int main(){

	srand(time(NULL));
	vector<int> vet;


	for(int i=0; i<MAX; i++){
		int x = rand()%MAX;
		vet.push_back(x);
	}
	

	printVector(vet);
	
	cout << "Invs1: " << countInvsBruteForce(vet) << endl;
	myMergeSort(vet, 0, MAX-1);
	cout << "Invs2: " << trocas << endl;

	return 0;
}