/*
* Complexidade:
* Pior Caso: 	O(n^2) com PD c.c O(2^n)
* Caso medio: 	O(n^2) com PD c.c O(2^n)
* Melhor Caso:	O(n^2) com PD c.c O(2^n)
*
* Memoria usada: 
* O(n) para vetor
* O(n) para auxiliar com PD c.c O(1)
*
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




int bruteForceCutRod(vi &vet, int n){
	if(n == 0)
		return 0;

	int q = -INF;
	for(int i=1; i<=n; i++)
		q = max(q, vet[i-1]+bruteForceCutRod(vet, n-i));
	return q;
}





int memoizedCutRodAux(vi &vet, vi &res, int n){
	if(res[n] >= 0)
		return res[n];
	else if(n == 0)
		return 0;

	int q = -INF;
	for(int i=1; i<=n; i++)
		q = max(q, vet[i-1]+memoizedCutRodAux(vet, res, n-i));
	res[n] = q;

	return res[n];
}


int memoizedCutRod(vi &vet, int n){
	
	vi res(n+1);
	
	for(int i=0; i<=n; i++)
		res[i] = -INF;
	
	return memoizedCutRodAux(vet, res, n);
}






int extMemoizedCutRodAux(vi &vet, vi &res, vi &sol, int n){
	if(res[n] >= 0)
		return res[n];
	else if(n == 0)
		return 0;

	int q = -INF;
	for(int i=1; i<=n; i++){
		int temp = vet[i-1]+extMemoizedCutRodAux(vet, res, sol, n-i);
		if(q < temp){
			q = temp;
			sol[n] = i;
		}
	}
	
	res[n] = q;
	return res[n];
}


int memoizedCutRodSolution(vi &vet, int n){
	
	vi res(n+1);
	vi sol(n+1);
	
	for(int i=0; i<=n; i++)
		res[i] = -INF;
	
	extMemoizedCutRodAux(vet, res, sol, n);


	while(n > 0){
		cout << sol[n] << " ";
		n = n-sol[n];
	}

	cout << endl;

	return res[n];
}







int bottomUpCutRod(vi &vet, int n){

	vi res(n+1);
	res[0] = 0;

	for(int i=1; i<=n; i++){

		int q = -INF;
		for(int j=1; j<=i; j++)
			q = max(q, vet[j-1]+res[i-j]);

		res[i] = q;
	}

	return res[n];
}





void extBottomUpCutRod(vi &vet, int n, vi &res, vi &sol){

	res[0] = 0;
	for(int i=1; i<=n; i++){

		int q = -INF;
		for(int j=1; j<=i; j++){

			int temp = vet[j-1]+res[i-j];
			if(q < temp){
				q = temp;
				sol[i] = j;
			}
		}

		res[i] = q;
	}
}

void printCutRodSolution(vi &vet, int n){

	vi sol(n+1);
	vi res(n+1);

	extBottomUpCutRod(vet, n, res, sol);

	while(n > 0){
		cout << sol[n] << " ";
		n = n-sol[n];
	}

	cout << endl;
}




// nao funciona
int greedyStrategy(vi &vet, int n){

	int total = n;
	int m = 0;

	while(total > 0){

		double melhor = -INF;
		int pos = 1;
		for(int i=1; i<=total; i++){
			if(vet[i-1]/i > melhor){
				melhor = vet[i-1]/i;
				pos = i;
			}
		}

		cout << pos << " ";
		m += vet[pos-1];
		total -= pos;
	}

	cout << endl;
	return m;
}





int bottomUpCutRodWithCost(vi &vet, int n, int cost){

	vi sol(n+1);
	vi res(n+1);

	res[0] = 0;

	for(int i=1; i<=n; i++){

		int q = -INF;
		for(int j=1; j<=i; j++){
			int temp = vet[j-1]+res[i-j] - (i-j)*cost;
			if(q < temp){
				q = temp;
				sol[i] = j;
			}
		}

		res[i] = q;
	}

	printVector(res);

	return res[n];
}





int fibAux(vi &vet, int n){
	if(!vet[n])
		vet[n] = fibAux(vet, n-1) + fibAux(vet, n-2);
	return vet[n];
}


int fib(int n){
	vi vet(n+1);
	vet[0] = vet[1] = 1;
	return fibAux(vet, n);
}




int main(){

	srand(time(NULL));

	const int N = 10;
	const int M = 10;
	int v[N] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	
	vi vet;
	for(int i=0; i<N; i++)
		vet.push_back(v[i]);
	

	printVector(vet);
	
	int x;
	
	cout << endl << "Brute Force: ";
	x = bruteForceCutRod(vet, M);
	cout << x << endl;

	cout << "Memoized: ";
	x = memoizedCutRod(vet, M);
	cout << x << endl;

	cout << "BottomUp: ";
	x = bottomUpCutRod(vet, M);
	cout << x << endl << endl;

	cout << "BottomUp With Cost of 3: ";
	x = bottomUpCutRodWithCost(vet, M, 3);
	cout << x << endl << endl;
		

	cout << "BottomUp Solution: "; 
	printCutRodSolution(vet, M);
	cout << endl;

	cout << "Memoized Solution: ";
	memoizedCutRodSolution(vet, M);
	cout << endl;


	cout << "Greedy Solution: ";
	x = greedyStrategy(vet, M);

	cout << "Greedy:";
	cout << x << endl << endl;


	cout << "Fib(5): ";
	x = fib(5);
	cout << x << endl;

	return 0;
}