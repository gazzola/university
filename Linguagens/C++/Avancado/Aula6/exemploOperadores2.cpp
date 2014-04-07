/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploOperadores2.cpp - Mostra como implementar os operadores () e  []
 */

#include <iostream>

using namespace std;

class Matriz {
private:	
	int *elementos;
	int linhas;
	int colunas;

public:

	Matriz(int linhas, int colunas);

	int &operator[] (int indice);

	int &operator() (int linha, int coluna);
	
	~Matriz();

};

int &Matriz::operator[] (int indice) {
	return elementos[indice];
}

int &Matriz::operator() (int linha, int coluna) {
	return elementos[(linha * colunas) + coluna];
}

Matriz::Matriz(int l, int c) : 
    linhas(l), colunas(c) {
    
	elementos = new	int[l * c];
}

Matriz::~Matriz() {
    delete [] elementos;
}

int main() {
	int tamanho = 3;
	Matriz m(tamanho, tamanho);
	int i, j;

	for (i = 0; i < tamanho * tamanho; i++) {
		m[i] = i;
	}

	for (i = 0; i < tamanho; i++) {
		for (j = 0; j < tamanho; j++) {
			cout << "m(" << i << "," << j << ") = "
                 << m(i,j) << endl;
		}
	}
	
	return 0;
}
