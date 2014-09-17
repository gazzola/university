/*
*
* File: Problema B - BaralhoEmbaralhado.cpp
* Author: Marcos V. Treviso
*
* Complexity: O(n^2)
* Algoritmo de forca bruta
*
* Description: 
*	- Quantas iteracoes sao necessarias para embaralhar 
*	  o baralho ate que ele fique novamente ordenado
*
* Compile: g++ -o teste B-BaralhoEmbaralhado.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <vector>

using namespace std;

bool estaOrdenado(vector<int> &baralho){
	return (baralho[0] == 1 and baralho[1] == 2);
}

void embaralhar(vector<int> &baralhoVelho, vector<int> &baralhoNovo, int n){
	int n2 = n/2;

	int p = 0;
	int q = n2;

	for(int i=0; i<n; i+=2){

		baralhoNovo[i] = baralhoVelho[q];
		baralhoNovo[i+1] = baralhoVelho[p];

		q++;
		p++;
	}
}


void printVector(vector<int> &baralho, int n){
	for(int i=0; i<n; i++){
		printf("%.2d ", baralho[i]);
		if(i+1 == n/2)
			printf("| ");
	}
	printf("\n\n");
}


void initialize(vector<int> &baralho, int n){
	for(int i=0; i<n; i++)
		baralho[i] = i+1;
}


bool ehImpar(int n){
	return (n%2 != 0);
}

int main(){

	int n;

	while(scanf("%d", &n) != EOF){

		vector<int> baralhoVelho(n);
		vector<int> baralhoNovo(n);

		initialize(baralhoVelho, n);

		bool trocar = true;
		int count = 1;

		printVector(baralhoVelho, n);

		while(true){

			if(trocar){
				embaralhar(baralhoVelho, baralhoNovo, n);
				printVector(baralhoNovo, n);
				if(estaOrdenado(baralhoNovo))
					break;
			}
			else{
				embaralhar(baralhoNovo, baralhoVelho, n);
				printVector(baralhoVelho, n);
				if(estaOrdenado(baralhoVelho))
					break;
			}


			trocar = !trocar;
			count++;
		}
		
		printf("RESULTADO:%d ", count);
		printf("\n\n\n");

	}

	printf("\n");

	return 0;
}