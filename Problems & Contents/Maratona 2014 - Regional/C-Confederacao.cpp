/*
*
* SEM SOLUCAO POR ENQUANTO (esse eh dificil)
*
* File: Problema C - Confederacao
* Author: Marcos V. Treviso
*
* Complexity: O(n)
*
* Description: 
*	- Verificar quantos planetas estao em cada regioes, onde
*     cada regiao corresponde a regiao definida pela interseccao
*     dos planos infinitos
*
* Compile: g++ -o teste C-Confederacao.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>


using namespace std;

typedef struct _coord{
	int x, y, z;
	int d;
	int qtd;
}coord;


int main(){

	int m, n, x, y, z, d;
	while(scanf("%d %d", &m, &n) != EOF){

		vector<coord> planos;
		vector<coord> pontos;

		for(int i=0; i<m; i++){
			scanf("%d %d %d %d", &x, &y, &z, &d);
			coord aux;
			aux.x = x;
			aux.y = y;
			aux.z = z;
			aux.d = d;
			aux.qtd = 0;
			planos.push_back(aux);
		}

		for(int i=0; i<n; i++){
			scanf("%d %d %d", &x, &y, &z);
			coord aux;
			aux.x = x;
			aux.y = y;
			aux.z = z;
			pontos.push_back(aux);
		}



		for(int i=0; i<m; i++){
			int a = planos[i].x;
			int b = planos[i].y;
			int c = planos[i].z;
			d = planos[i].d;
			
			for(int j=0; j<n; j++){

				x = pontos[j].x;
				y = pontos[j].y;
				z = pontos[j].z;

				int total = a*x + b*y + c*z - d;
				printf("%d\n", total);
				if(total >= 0){

					planos[i].qtd++;
				}
			}

			printf("\n");

		}

		//for(int i=0; i<m; i++){
		//	printf("%d\n", planos[i].qtd);
		//}

	}

	return 0;
}