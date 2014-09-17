/*
*
* File: Problema C - FechemAsPortas 2
* Author: Marcos V. Treviso
*
* Complexity: O(n^2)
* Algoritmo de forca bruta
*
* Description: 
*	- Sequencia de numeros crescente correspondente aos
*	  identificadores dos quartos com portas abertas.
*
* Compile: g++ -o teste C-FechemAsPortas2.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;






// observe o padrao criado eh simplesmente verificar que se o numero de
// divisores eh impar, a porta vai estar aberta. Ao analisar o padrao, da para
// perceber que as portas abertas cujo os quadrados de seus  identificadores
// que sao menores ou iguais a n


int main(){
	
	int n;

	while(scanf("%d", &n) != EOF){

		vector<bool> portas;

		for(int i=0; i<=n; i++)
			portas.push_back(false);

		for(int i=1; i<=n; i++)
			for(int j=0; j<=n; j+=i)
				portas[j] = !portas[j];
		
		for(int i=1; i<=n; i++)
			if(portas[i])
				printf("%d ", i);

		printf("\n");
	}


	return 0;

}
