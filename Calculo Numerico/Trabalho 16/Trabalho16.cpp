/*
* Trabalho 16.
* Implemente um algoritmo que permita invocar todos os 
* demais algoritmos implementados na disciplina.
*
*
* Calculo Numerico
* Claudio Schepke
* ---
* Ciencia da Computacao
* Universidade Federal do Pampa
* 
*
* Integrantes:
* ---
* Marcos V. Treviso, 121150107, marcosvtreviso@gmail.com
*
*
* Instrucoes:
* ---
* Compile: g++ -o trab Trabalho16.cpp -Wall -Wextra
* Run: ./trab
*
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
const int NUM_TRABALHOS = 15;

const string trabalhos[NUM_TRABALHOS] = {
	"Conversor de decimal para binario e vice-versa",
	"Método da Bisseção",
	"Método de Newton-Raphson",
	"Algoritmo de Briot-Ruffini",
	"Ajuste Linear",
	"Ajuste Quadrático",
	"Método de Lagrange",
	"Método de Newton",
	"Método dos Retângulos e Método dos Trapézios",
	"Regra de Simpson",
	"Método de Newton-Côtes",
	"Fatoração LU",
	"Métodos de Jacobi e Gauss-Seidel",
	"Método de Euler",
	"Método de Runge-Kutta"
};


void printMenu(){

	cout << endl;
	cout << "Escolha uma opcao de 1 a " << NUM_TRABALHOS << endl;
	cout << "Ou 0 (zero) para parar a execucao" << endl << endl;

	for(int i=1; i<=NUM_TRABALHOS; i++)
		cout << i << " -> Trabalho " << i << " - " << trabalhos[i-1] << endl;

	cout << endl;
}


string compAndRun(int opcao){
	return "g++ -std=c++11 -o teste Trabalho"+to_string(opcao)+".cpp && ./teste";
}

string switchDir(int opcao){
	if(opcao < 10)
		return "cd ../Trabalho\\ 0"+to_string(opcao)+"/ && ";
	return "cd ../Trabalho\\ "+to_string(opcao)+"/ && ";
}

void execute(int opcao){

	cout << trabalhos[opcao-1] << ":" << endl;
	cout << "-------------------------------------" << endl;
	system((switchDir(opcao)+compAndRun(opcao)).c_str());
}


int main(){

	int p;
	while(true){
		printMenu();
		cin >> p;

		if(p == 0 or p > NUM_TRABALHOS)
			break;
		
		execute(p);
	}

	return 0;
}