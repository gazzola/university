#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>


using namespace std;



int main(){
	

	int n;
	const int DESCENDO = 0;
	const int SUBINDO = 1;
	const int PARADO = 2;

	while(true){

		scanf("%d", &n);
		if(n == 0)
			break;


		int direcaoAtual = PARADO;
		int direcaoAnterior = PARADO;
		
		int primeiro, segundo, ultimo, atual;
		int total = 0;

		scanf("%d", &ultimo);
		primeiro = ultimo;
		segundo = primeiro;

		for(int i=1; i<=n+1; i++){

			if(i < n)
				scanf("%d", &atual);
			else if(i == n)
				atual = primeiro;
			else
				atual = segundo;


			if(i == 1)
				segundo = atual;

			
			if(atual < ultimo)
				direcaoAtual = DESCENDO;
			else if(atual > ultimo)
				direcaoAtual = SUBINDO;
			else
				direcaoAtual = PARADO;

			if(direcaoAnterior != direcaoAtual and direcaoAnterior != PARADO)
				total++;
		

			direcaoAnterior = direcaoAtual;
			ultimo = atual;
		}


		printf("%d\n", total);


	}
	

	return 0;
}