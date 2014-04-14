/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploThreadSincronizacaoEventos.cpp - Mostra como utilizar Eventos
 *                                         sincronizar threads
 */

#include <iostream>
#include <process.h>
#include <windows.h>

using namespace std;

int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
HANDLE evento1;
HANDLE evento2;

void funcaoThread(void *p) {
	while (1) {
		WaitForSingleObject(evento2, INFINITE);

		for (int i = 0; i < 10; i++) {
			array[i] = (array[i] + 1) % 10;
			Sleep(10);
		}

		SetEvent(evento1);
	}
}

int main() {
    evento1 = CreateEvent(NULL, FALSE, TRUE, "Evento1");
	evento2 = CreateEvent(NULL, FALSE, FALSE, "Evento2");

	_beginthread(funcaoThread,50,NULL);

	while (1) {
		WaitForSingleObject(evento1, INFINITE);

		for (int i = 0; i < 10; i++) {
			cout << array[i] << ' ';
		}
		cout << endl;

		Sleep(10);
		SetEvent(evento2);

	}

	return 0;
}

