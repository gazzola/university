/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploThreadSimplesMFC.cpp - Mostra como criar um simples thread na MFC
 *
 */

#include <iostream>
#include <afxwin.h>
#include <afxmt.h>

using namespace std;

int interacoes = 0;

UINT funcaoThread(LPVOID param) {
	while (1) {
		cout << "Funcao thread" << endl;
		Sleep(1000);
	}

	return 0;
}

int main() {

	AfxBeginThread(funcaoThread,NULL,THREAD_PRIORITY_NORMAL,0,0,NULL);

	while (1) {
		cout << "Funcao main" << endl;
		Sleep(1000);
	}

	return 0;
}
