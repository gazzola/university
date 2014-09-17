/*
*
* File: Problema A - Mario
* Author: Marcos V. Treviso
*
* Complexity: O(n)
*
* Description: 
*	- Numero minimo de trocar para ter N armarios
	  consecutivos disponiveis.
*
* Compile: g++ -o teste A-Mario.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <deque>


using namespace std;

void printDeque(deque<int> armario){
	for(unsigned int i=0; i<armario.size(); i++)
		printf("%d | ", armario[i]);
	printf("\n");
}


// uma estragegia para resolver, eh pegar todos os elementos
// que estao no comeco e jogar pro fim de modo a maximizar
// para mais informacoes, veja o arquivo 2 e imprima os casos
// de teste para verificar esse acontecimento.
// de mosso, podemos tirar os elementos que sao muito baixos
// ja que mais adiante eles seriam colocados para frente
// pesquise sobre max interval sum

bool daParaTirar(int atual, deque<int> &armario, int n){
	int primeiro = armario.front();
	int tam = armario.size();
	return ((atual-primeiro >= n) && (tam > 0));
}


int main(){
	
	int n, l, x;
	
	while(scanf("%d %d", &n, &l) != EOF){
		
		deque<int> armario;
		
		scanf("%d", &x);
		armario.push_back(x);

		int tam = armario.size();
		int maiorTam = tam;
		
		for(int i=1; i<l; i++){
			scanf("%d", &x);

			//printDeque(armario);

			while(daParaTirar(x, armario, n))
				armario.pop_front();

			armario.push_back(x);
			tam = armario.size();

			if(tam > maiorTam)
				maiorTam = tam;
		}
		
		printf("%d\n", n - maiorTam);
		
	}
	
	return 0;
}
