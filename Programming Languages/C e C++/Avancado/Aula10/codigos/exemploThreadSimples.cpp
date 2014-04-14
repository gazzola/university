/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploThreadSimples.cpp - Simples exemplo de como criar um thread com a API
 *                            do windows
 */

#include <iostream>
#include <process.h>
#include <windows.h>

using namespace std;

int interacoes = 0;

void funcaoThread(void *p) {
	while (interacoes < 10) {
		cout << "Funcao thread\n";
		Sleep(1000);
	}
	
    _endthread();
}


int main() {
    _beginthread( funcaoThread,0,NULL);

	while (interacoes < 10) {
		cout << "Funcao main\n";
		Sleep(1000);
		interacoes++;
	}
	
	return 0;
}

