/*
*
* NAO ESTA FUNCIONANDO AINDA
*
* File: Problema F - Teletransporte
* Author: Marcos V. Treviso
*
* Complexity: O()
*
* Description: 
*	- 
*
* Compile: g++ -o teste F-Teletransporte.cpp -Wall -Wextra
* Run: ./teste < <arquivo.txt>
*
*/


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <deque>
#include <map>
#include <string>

using namespace std;


int main(){

	
	
	int n, l, s, t, x;

	while(scanf("%d %d %d %d", &n, &l, &s, &t) != EOF){

		
		vector<int> botoes(4);
		vector< vector<int> > naves;
		vector< int > quantos;

		naves.push_back(botoes);
		quantos.push_back(0);


		for(int i=1; i<=n; i++){

			int qtd = 0;
			for(int j=0; j<4; j++){
				scanf("%d", &x);
				botoes[j] = x;
				if(x == t)
					qtd++;
			}
			naves.push_back(botoes);
			quantos.push_back(qtd);
		}

		int valor = 0;
		for(int i=0; i<4; i++){
			int qual = naves[s][i];
			if(quantos[qual] != 0)
				valor++;
		}

		printf("%d\n", valor % 10000);


	}





	return 0;
}