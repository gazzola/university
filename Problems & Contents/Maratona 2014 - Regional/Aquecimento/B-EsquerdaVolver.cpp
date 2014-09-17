/*
*
* File: Problema B - EsquerdaVolver
* Author: Marcos V. Treviso
*
* Complexity: O(n)
*
* Description: 
*	- Direcao que o recruta deve ter a face voltada apos
	  executar a serie de comandos.
*
* Compile: g++ -o teste B-EsquerdaVolver.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/

#include <cstdio>
#include <cmath>

using namespace std;


int main(){

	int n, pos;
	char c;


	while(true){
		
		scanf("%d\n", &n);
		if(n == 0)
			break;

		pos = 0;

		while(n--){
			scanf("%c", &c);
			if(c == 'D'){
				if(pos == 3)
					pos = 0;
				else
					pos++;
			}
			else{
				if(pos == -3)
					pos = 0;
				else
					pos--;
			}
		}

		int x = abs(pos);

		if(x == 0 || x == 3)
			printf("N");
		else if(x == 1){
			if(pos < 0)
				printf("O");
			else
				printf("L");
		}
		else if(x == 2)
			printf("S");

		printf("\n");


	}

	return 0;
}