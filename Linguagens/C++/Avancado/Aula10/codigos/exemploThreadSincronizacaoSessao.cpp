/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploThreadSincronizacaoSessao.cpp - Mostra como utilizar uma Critical
 *                                         Section para sincronizar threads
 */

#include <iostream>
#include <process.h>
#include <windows.h>

using namespace std;

int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
CRITICAL_SECTION cs;

void funcaoThread(void *p) {
	while (1) {
		EnterCriticalSection(&cs);

		for (int i = 0; i < 10; i++) {
			array[i] = (array[i] + 1) % 10;
			Sleep(10);
		}

		LeaveCriticalSection(&cs);
	}
}

int main() {
    InitializeCriticalSection( &cs );

	_beginthread( funcaoThread,50,NULL);

	while (1) {
		EnterCriticalSection(&cs);
		for (int i = 0; i < 10; i++) {
			cout << array[i] << ' ';
		}

		cout << endl;
		Sleep(10);
		LeaveCriticalSection(&cs);
	}
	
	return 0;
}
