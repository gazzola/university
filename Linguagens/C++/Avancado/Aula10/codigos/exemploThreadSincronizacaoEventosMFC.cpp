/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploThreadSincronizacaoEventosMFC.cpp - Mostra como utilizar Eventos para 
 *                                            sincronizar threads na MFC
 */

#include <iostream>
#include <afxwin.h>
#include <afxmt.h>

using namespace std;

int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
CEvent evento1(FALSE, FALSE, "Evento1", NULL);
CEvent evento2(TRUE, FALSE, "Evento2", NULL);

UINT funcaoThread(LPVOID param) {
	while (1) {
		evento1.Lock();
		for (int i = 0; i < 10; i++) {
			array[i] = (array[i] + 1) % 10;
			Sleep(10);
		}
		evento2.SetEvent();
		Sleep(100);
	}

	return 0;
}

int main() {
	AfxBeginThread(funcaoThread,NULL,THREAD_PRIORITY_NORMAL,0,0,NULL);

	while (1) {
		evento2.Lock();
		for (int i = 0; i < 10; i++) {
			cout << array[i] << ' ';
		}
		cout << endl;
		Sleep(10);
		evento1.SetEvent();
	}

	return 0;
}

