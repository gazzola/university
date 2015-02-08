#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>

using namespace std;



int main(){
 
	
	
	double peso, m, total;

	int y, t, qtd;
	cin >> y;

	while(y--){

		cin >> t;
		total = 0;

		string nome;
		map<string, double> treno;
		
		for(int i=0; i<t; i++){
			getline(cin, nome);
			getline(cin, nome);

			cin >> peso;
			treno[nome] = peso;
		}

		cin >> m;

		while(true){

			getline(cin, nome);
			getline(cin, nome);
			cin >> qtd;

			if(nome[0] == '-' and qtd == 0)
				break;

			if(treno.count(nome) > 0)
				total += qtd*treno[nome];
			else{
				treno[nome] = 0;
				cout << "NAO LISTADO: " << nome << endl;
			}
		}

		printf("Peso total: %.2lf kg\n", total);
		printf("Numero de trenos: %d\n", (int) ceil(total/m));
		printf("\n");

	}
 
	return 0;
}