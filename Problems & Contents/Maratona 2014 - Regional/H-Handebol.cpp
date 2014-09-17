/*
*
* File: Problema H - Handebol
* Author: Marcos V. Treviso
*
* Complexity: O(n.m)
*
* Description: 
*	- Contar quantos jogadres maracaram gol em todas as partidas
*
* Compile: g++ -o teste H-Handebol.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>


int main(){

	int numJogadroes, numPartidas;
	int count, gol;
	bool golEmTodas;
	
	while(scanf("%d %d", &numJogadroes, &numPartidas) != EOF){

		count = 0;

		for(int i=0; i<numJogadroes; i++){

			golEmTodas = true;
			
			for(int j=0; j<numPartidas; j++){
				scanf("%d", &gol);
				if(gol == 0)
					golEmTodas = false;
			}

			if(golEmTodas)
					count++;
		}

		printf("%d\n", count);

	}

	return 0;
}