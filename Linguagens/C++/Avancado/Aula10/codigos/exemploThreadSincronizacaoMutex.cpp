/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploThreadSincronizacaoMutex.cpp - Mostra utilizar um Mutex para
 *                                       sincronizar threads
 */

#include <iostream>
#include <process.h>
#include <windows.h>

using namespace std;

int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
HANDLE mutex;

void funcaoThread(void *p) {
	while (1) {
		WaitForSingleObject(mutex, INFINITE);

		for (int i = 0; i < 10; i++) {
			array[i] = (array[i] + 1) % 10;
			Sleep(10);
		}

		Sleep(100);
		ReleaseMutex(mutex);
	}
}

int main() {
    mutex = CreateMutex( NULL, FALSE, NULL );

	_beginthread(funcaoThread,50,NULL);
	
	while (1) {
		WaitForSingleObject(mutex, INFINITE);

		for (int i = 0; i < 10; i++) {
			cout << array[i] << ' ';
		}
		cout << endl;

		Sleep(10);
		ReleaseMutex(mutex);

	}

	return 0;
}


