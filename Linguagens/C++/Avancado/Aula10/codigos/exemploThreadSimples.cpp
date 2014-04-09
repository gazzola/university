/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
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

