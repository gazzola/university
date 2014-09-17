/*
*
* File: Problema B - BaralhoEmbaralhado
* Author: Marcos V. Treviso
*
* Complexity: O(n)
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
#include <cmath>

using namespace std;


bool estaOrdenado(int pos1, int pos2){
	return (pos1 == 1 and pos2 == 2);
}

int getNovaPos(int pos, int n){

	int metade1 = n/2;
	int metade2 = floor((float) metade1/2.0);
	if(pos <= metade1){
		if(pos <= metade2){
			return pos*2;
		}
		else{
			int aux = pos-metade2;
			if(metade1 % 2 == 0)
				return metade1+(2*aux);
			else
				return metade1+(2*aux)-1; 
		}
	}
	else{
		if(pos <= (metade1+metade2)){
			int aux = pos-metade1;
			return 2*aux - 1;
		}
		else{
			int aux = pos-(metade1+metade2);
			if(metade1 % 2 == 0)
				return metade1+(2*aux - 1);
			else
				return metade1+(2*aux - 1)-1;
		}
	}

	return 0;
}

/* 
Observe que se ficarmos de verificarmos apenas o elemento 1 e 2 do vetor,
vamos conseguir dizer se ele esta ordenado. Sendo assim, podemos fazer as
iteracoes de troca do lugar apenas com esses 2 valores, gastando assim tempo
constante (O(2)) para realizar a troca. Para mais informacoes, rode o
algoritmo de forca bruta e analise as posicoes do 1 e do 2 em cada vez que o
baralho eh embralahado. 
*/

int main(){

	int n, count, pos1, pos2;

	while(scanf("%d", &n) != EOF){

		count = 1;
		pos1 = 1;
		pos2 = 2;

		while(true){
			pos1 = getNovaPos(pos1, n);
			pos2 = getNovaPos(pos2, n);
			
			if(estaOrdenado(pos1, pos2))
				break;

			count++;
		}
		
		printf("%d\n", count);

	}

	return 0;
}