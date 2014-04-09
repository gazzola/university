/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploThreadSimpleEx.cpp - Mostra como utilizar a função _beginthreadex para a
 *                             criação de threads
 */

#include <iostream>
#include <process.h>
#include <windows.h>

using namespace std;

int interacoes = 0;

unsigned __stdcall funcaoThread(void *p) {
	while (interacoes < 10) {
		cout << "Funcao thread\n";
		Sleep(1000);
	}
	
    _endthreadex(0);
    return 0;
}


int main() {
    HANDLE hThread;
    unsigned int threadId;
    
    hThread = (HANDLE)_beginthreadex( NULL, 0, &funcaoThread, NULL, 0, &threadId);   

	while (interacoes < 10) {
		cout << "Funcao main\n";
		Sleep(1000);
		interacoes++;
	}
	
	return 0;
}

