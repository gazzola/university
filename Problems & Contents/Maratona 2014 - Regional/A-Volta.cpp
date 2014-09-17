/*
*
* File: Problema A - Volta
* Author: Marcos V. Treviso
*
* Complexity: O(n)
*
* Description: 
*	- Voltas para o piloto mais veloz ultrapassar o mais lento
*
* Compile: g++ -o teste A-Volta.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>


int main(){

	int m, n, segundos, voltasM, voltasN;
	
	while(scanf("%d %d", &m, &n) != EOF){

		voltasM = m;
		voltasN = n;
		segundos = 1;

		while(true){

			// a cada m segundos o primeiro piloto faz uma volta
			if(segundos % m == 0){
				voltasM += m;

				// se o primeiro piloto deu uma volta e nessa volta ele passou o segundo, entao para
				if(voltasM <= voltasN)
					break;
			}

			// a cada n segundos o segundo piloto faz uma volta
			if(segundos % n == 0)
				voltasN += n;

			segundos++;
		}

		printf("%d\n", voltasM/m);

	}

	return 0;
}