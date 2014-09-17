/*
*
* File: Problema K - PizzaDoVoPepe
* Author: Marcos V. Treviso
*
* Complexity: O(n^2)
*
* Description: 
*	- Verificar se eh possivel dividir a pizza em pedacos iguais
*     de modo que tenha uma azeitona em cada pedaco
*
* Compile: g++ -o teste K-PizzaDoVoPepe.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>


using namespace std;



bool temNoPedaco(int *pizza, int tamPedaco, int inicio, int circ){
	int j=inicio;
	int count = 0;
	for(int i=inicio; i<inicio+tamPedaco; i++){
		
		if(i == circ)
			j = 0;

		if(pizza[j] == 1)
			count++;

		j++;
	}

	return (count == 1);
}


bool verifica(int inicio, int circ, int numAzeit, int *pizza, bool *temEmTodos){


	int tamPedaco = circ/numAzeit;
	memset(temEmTodos, false, sizeof(*temEmTodos));

	for(int i=inicio; i<circ+inicio; i+=tamPedaco)
		temEmTodos[i/tamPedaco] = temNoPedaco(pizza, tamPedaco, i, circ);
	
	for(int i=0; i<numAzeit; i++)
		if(temEmTodos[i] == false)
			return false;

	return true;
}

bool verificaTudo(int circ, int numAzeit, int *pizza, bool *temEmTodos){
	int tamPedaco = circ/numAzeit;
	for(int i=0; i<=tamPedaco; i++)
		if(verifica(i, circ, numAzeit, pizza, temEmTodos))
			return true;
	return false;
}

void printPizza(int *pizza, int circ){
	for(int i=0; i<circ; i++)
		printf("%.2d | ", i);
	printf("\n");
	for(int i=0; i<circ; i++)
		printf("%.2d | ", pizza[i]);

	printf("\n");printf("\n");
}

int main(){

	
	int circ, numAzeit, x;
	int pizza[100001];
	bool temEmTodos[100001];

	while(scanf("%d %d", &circ, &numAzeit) != EOF){

		memset(pizza, 0, sizeof(pizza));
		
		for(int i=0; i<numAzeit; i++){
			scanf("%d", &x);
			pizza[x] = 1;
		}

		if(verificaTudo(circ, numAzeit, pizza, temEmTodos))
			printf("S\n");
		else
			printf("N\n");

	}

	return 0;
}