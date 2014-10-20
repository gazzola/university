/*
* Complexidade:
* Pior Caso: 	O(nlogn)
* Caso medio: 	O(nlogn)
* Melhor Caso:	O(nlogn)
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
#include <tuple> // C++11
#include "../utils.h"

using namespace std;
const int INF = 999999;
const int MAX = 8;



// retorna tupla com indices que demarcam o array e a soma deles
iii findMaxCrossingSubarray(vector<int> &vet, int p, int q, int r){

	int leftSum, rightSum, sum;
	int posLeft, posRight;

	leftSum = -INF;
	sum = 0;
	for(int i=q; i>=p; i--){
		sum += vet[i];
		if(sum > leftSum){
			leftSum = sum;
			posLeft = i;
		}
	}

	rightSum = -INF;
	sum = 0;
	for(int j=q+1; j<=r; j++){
		sum += vet[j];
		if(sum > rightSum){
			rightSum = sum;
			posRight = j;
		}
	}

	return iii(posLeft, posRight, leftSum+rightSum);
}


iii findMaxSubarray(vector<int> &vet, int p, int r){

	if(p == r)
		return iii(p, r, vet[p]);
	

	int q = (p+r)/2;
	iii leftSubarray = findMaxSubarray(vet, p, q);
	iii rightSubarray = findMaxSubarray(vet, q+1, r);
	iii crossSubarray = findMaxCrossingSubarray(vet, p, q, r);
	
	int leftSum = get<2>(leftSubarray);
	int rightSum = get<2>(rightSubarray);
	int crossSum = get<2>(crossSubarray);

	if(leftSum >= rightSum and leftSum >= crossSum)
		return leftSubarray;
	else if(rightSum >= leftSum and rightSum >= crossSum)
		return rightSubarray;
	
	return crossSubarray;

}


// O(n^2)
iii findMaxSubarrayTrivial(vector<int> &vet){
	
	int sum, maxSum = -INF;
	int tam = vet.size();
	int posLeft, posRight;

	for(int i=0; i<tam; i++){
		sum = 0;
		for(int j=i; j<tam; j++){

			sum += vet[j];
			if(sum > maxSum){
				maxSum = sum;
				posLeft = i;
				posRight = j;
			}
		}
	}

	return iii(posLeft, posRight, maxSum);
}


int main(){

	srand(time(NULL));
	vector<int> vet;
	
	for(int i=0; i<MAX; i++){
		vet.push_back((rand()%MAX)-(rand()%MAX));
	}

	printVector(vet);

	iii t = findMaxSubarray(vet, 0, MAX-1);

	int first = get<0>(t);
	int second = get<1>(t);
	int third = get<2>(t);
	printf("%d %d %d\n", first, second, third);

	return 0;
}