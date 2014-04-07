/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploThreadProblemaSincronizacao.cpp - Mostra como o problema da 
 *                                          sincronização pode afetar
 *                                          programs multithreads.
 */

#include <iostream>
#include <process.h>
#include <windows.h>

using namespace std;

int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void funcaoThread(void *p) {
	while (1) {
		for (int i = 0; i < 10; i++) {
			array[i] = (array[i] + 1) % 10;
			Sleep(100);
		}
	}
}

int main() {

	_beginthread( funcaoThread,50,NULL);
	
	while (1) {
		for (int i = 0; i < 10; i++) {
			cout << array[i] << ' ';
		}

		cout << endl;
		Sleep(100);
	}

	return 0;
}
