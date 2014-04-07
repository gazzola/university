/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploArquivo.cpp - Exemplo de como realizar operações básicas com arquivos em C++
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	char * arquivo = "exemploES.txt";
	ofstream saida;
	saida.open(arquivo, ios::out | ios::trunc);

	if (saida.is_open()) {
		cout << "Arquivo aberto com sucesso" << endl;
	}

	saida << "Universidade Federal de Pernambuco" << endl;
	saida << "Centro de Informatica" << endl;

	saida.close();
	
	if (!saida.is_open()) {
		cout << "Arquivo fechado com sucesso" << endl;
	}

	ifstream entrada(arquivo);
	string s;

	if (entrada.is_open()) {
		cout << "Arquivo aberto com sucesso" << endl;
	}

	while (getline(entrada, s)) {
		cout << s << endl;
	}

	entrada.close();

	if (!entrada.is_open()) {
		cout << "Arquivo fechado com sucesso" << endl;
	}

	return 0;
}
