/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploThreadSincronizacaoMutexMFC.cpp - Mostra como utilizar um Mutex para
 *                                          sincronizar threads na MFC
 */

#include <iostream>
#include <afxwin.h>
#include <afxmt.h>

using namespace std;

int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
CMutex mutex;

UINT funcaoThread(LPVOID param) {
	while (1) {
		mutex.Lock(10000);
		for (int i = 0; i < 10; i++) {
			array[i] = (array[i] + 1) % 10;
			Sleep(10);
		}
		mutex.Unlock();
		Sleep(100);
	}

	return 0;
}

int main() {
	AfxBeginThread(funcaoThread,NULL,THREAD_PRIORITY_NORMAL,0,0,NULL);

	while (1) {
		mutex.Lock();
		for (int i = 0; i < 10; i++) {
			cout << array[i] << ' ';
		}
		cout << endl;

		Sleep(10);
		mutex.Unlock();
	}

	return 0;
}

