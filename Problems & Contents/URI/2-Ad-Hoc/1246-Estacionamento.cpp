#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <map>


using namespace std;


int main(){


	map<int, int> comprimento;
	map<int, int> posicao;

	int c, n, placa, comp, qtdEntrada;
	int estac[10001];
	char cheg;

	while(scanf("%d %d ", &c, &n) != EOF){

		int j=c;
		for(int i=0; i<=c; i++)
			estac[i] = j--;


		qtdEntrada = 0;

		
		while(n--){

			scanf("%c ", &cheg);
			if(cheg == 'C'){

				scanf("%d %d ", &placa, &comp);
				for(int i=0; i<c; i++){
					if(estac[i] >= comp){

						int final=comp+i;
						for(int j=i; j<final; j++)
							estac[j] = 0; //posicao ocupada

						comprimento[placa] = comp;
						posicao[placa] = i; //posicao inicial, pos final = inicial+comp
						qtdEntrada++;
						break;
					}
				}

			}
			else{

				scanf("%d ", &placa);
				if(posicao.count(placa) > 0){
					
					int inicio = posicao[placa];
					int fim = inicio+comprimento[placa];
					int comp = comprimento[placa];

					int aux = estac[fim]; //pega oq tem a direita dele e preenche
					for(int i=fim-1; i>=inicio; i--)
						estac[i] = ++aux;


					//preenche os que estao a esquerda dele
					for(int i=inicio-1; i>=0; i--){
						if(estac[i] > 0)
							estac[i] = ++aux;
						else
							break;
					}

					comprimento.erase(placa);
					posicao.erase(placa);
				}

			}
		}

		printf("%d\n", qtdEntrada*10);
	}

	return 0;
}



/*

Caso 2:

[3 2 1 0] 
[0 2 1 0] entrou 1000(1)
[0 0 1 0] entrou 1001(1)
[0 0 0 0] entrou 1002(1)
[1 0 0 0] saiu o 1000(1)
[1 0 1 0] saiu o 1002(1)
[1 0 1 0] entrou 1003(2) - cheio!
[3 2 1 0] saiu o 1001(1)
[0 0 1 0] entrou 1003(2) - agora foi!
[0 0 1 0] entrou 1004(2) - cheio!
[0 0 1 0] saiu o 1004(2) - nem entrou
[0 0 1 0] entrou 1005(3) - cheio!


*/