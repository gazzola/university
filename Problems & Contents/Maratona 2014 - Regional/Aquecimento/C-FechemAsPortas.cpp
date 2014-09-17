/*
*
* File: Problema C - FechemAsPortas
* Author: Marcos V. Treviso
*
* Complexity: O(sqrt(n)) -> O(n)
*
* Description: 
*	- Sequencia de numeros crescente correspondente aos
*	  identificadores dos quartos com portas abertas.
*
* Compile: g++ -o teste C-FechemAsPortas.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int main(){

	int n;

	while(scanf("%d", &n) != EOF){

		int i = 1;
		while(i*i <= n){
			printf("%d ", i*i);
			i++;
		}

		printf("\n");

	}


	return 0;

}
