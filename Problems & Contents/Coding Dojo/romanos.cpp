/*
* Resolucao exercicio do Coding Dojo 2014 - SACTA
* Complexidade do algoritmo: O(n*log(n))
*
* Compile: g++ -o romanos romanos.cpp -Wall -Wextra
* Run: ./romanos
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<string, int> si;


int main(){
	
	si romanos[7] = {
		si("M", 1000), si("D", 500), si("C", 100), si("L", 50), si("X", 10), si("V", 5), si("I", 1)
	}; 

	int numArabico, i, valor, qtdIters;

	while(true){

		cout << "Digite o num arabico: ";
		cin >> numArabico;

		valor = numArabico;
		string numRomano = "";
		i = qtdIters = 0; 

		while(i < 7 && valor > 0){

			if(valor >= romanos[i].second){		//51 >= 50(L)
				valor -= romanos[i].second;		//valor = valor - 50 -> valor = 51-50 -> valor = 1
				numRomano += romanos[i].first;	//numRomano = numRomano + L
			}
			else{

				if(i < 6){ //ate V
					int d = ((i&1) == 1) ? 1 : 2;	//deslocamento

					//se eh impar, entao romano atual eh D ou L ou V (desloca 1 no vetor de numeros romanos)
					//entao vai diminuir C do D, X do L, I do V

					//senao, entao romano atual eh M ou C ou X (desloca 2 no vetor de numeros romanos)
					//entao vai diminuir C do M, X do C, I do X

					if(valor+romanos[i+d].second >= romanos[i].second){			//49+10(X) >= 50(L)
						valor -=  romanos[i].second - romanos[i+d].second;		//valor = valor - (50-10) -> valor = 49-40 -> valor = 9
						numRomano += romanos[i+d].first + romanos[i].first;		//numRomano = numRomano + X + L
					}
				}

				i++;
			}

			qtdIters++;
		}

		cout << numArabico << " para " << numRomano << " em " << qtdIters << " iteracoes." << endl << endl;

	}

}