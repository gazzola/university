/*
* Resolucao exercicio do Coding Dojo 2014 - SACTA
* Complexidade do algoritmo: O(N^2)
*
* Compile: g++ -o espiral espiral.cpp -Wall -Wextra
* Run: ./espiral
*/

#include <iostream>
#include <cstdio>

#define TAM 4

using namespace std;

int main(){

	const unsigned short int norte=1, leste=2, sul=3, oeste=4;

	int mat[TAM][TAM];
	int count = 0;


	// nao modificado
	for(int i=0; i<TAM; i++)
		for(int j=0; j<TAM; j++)
			mat[i][j] = 0;



	// direcao:
	// -> \/ <- /\ (leste, sul, oeste, norte)
	// por isso que se comeca pelo leste (atual=leste)
	unsigned short int atual = leste;

	for(int i=0; i<TAM; i++){

		int lastIndex = (TAM-1)-i; 

		if(atual == leste){
			for(int j=0; j<TAM; j++)
				if(mat[i][j] == 0)
					mat[i][j] = ++count;
			atual = sul;
		}

		if(atual == sul){
			for(int j=0; j<TAM; j++)
				if(mat[j][lastIndex] == 0)
					mat[j][lastIndex] = ++count;
			atual = oeste;
		}

		if(atual == oeste){
			for(int j=TAM-1; j>=0; j--)
				if(mat[lastIndex][j] == 0)
					mat[lastIndex][j] = ++count;
			atual = norte;
		}

		if(atual == norte){
			for(int j=TAM-1; j>=0; j--)
				if(mat[j][i] == 0)
					mat[j][i] = ++count;
			atual = leste;
		}
	}


	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++)
			printf("%.2d ", mat[i][j]);
		printf("\n");
	}

	return 0;
}