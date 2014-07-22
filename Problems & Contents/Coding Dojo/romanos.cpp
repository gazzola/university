#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<string, int> si;


int main(){
	
	si romanos[7] = {
		si("M", 1000), si("D", 500), si("C", 100), si("L", 50), si("X", 10), si("V", 5), si("I", 1)
	}; 

	int numArabico = 499;

	string numRomano = "";
	int i=0, valor=numArabico;

	while(i<7){
		if(valor >= romanos[i].second){
			valor -= romanos[i].second;
			numRomano += romanos[i].first;
		}
		else{

			if(i < 6){ // ate V

				int d = ((i&1) == 1) ? 1 : 2;	//deslocamento
												//se par, entao romano atual eh M, C, X
												//entao vai diminuir M->C, C->X, X->I
												//senao, entao romano atual eh D, L, V
												//entao vai diminuir D->C, L->X, V->I

				if(valor+romanos[i+d].second >= romanos[i].second){
					valor -=  romanos[i].second-romanos[i+d].second;
					numRomano += romanos[i+d].first + romanos[i].first;
				}
			}

			i++;
		}
	}

	cout << numArabico << " : " << numRomano << endl;

}