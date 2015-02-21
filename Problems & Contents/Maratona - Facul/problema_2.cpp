#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<string, int> si;


int main(){
	
	si romanos[7] = {
		si("M", 1000), si("D", 500), si("C", 100), si("L", 50), si("X", 10), si("V", 5), si("I", 1)
	}; 

	int numArabico, i, valor;

	cin >> numArabico;

	valor = numArabico;
	string numRomano = "";
	i = 0; 

	while(i < 7 && valor > 0){

		if(valor >= romanos[i].second){	
			valor -= romanos[i].second;	
			numRomano += romanos[i].first;
		}
		else{

			if(i < 6){
				int d = ((i&1) == 1) ? 1 : 2;
				if(valor+romanos[i+d].second >= romanos[i].second){		
					valor -=  romanos[i].second - romanos[i+d].second;	
					numRomano += romanos[i+d].first + romanos[i].first;	
				}
			}

			i++;
		}
	}

	cout << numRomano << endl;

}