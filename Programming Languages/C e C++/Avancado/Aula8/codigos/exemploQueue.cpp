/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploQueue.cpp - Mostra como utilizar a classe queue de C++.
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	queue <string> fila;

	fila.push("EU");
	fila.push("TU");
	fila.push("ELE");
	fila.push("NOS");
	fila.push("VOS");
	fila.push("ELES");

	while (!fila.empty()) {
		cout << fila.front() << ' ';
		// pop da classe queue � void
		fila.pop();
	}

	cout << endl;

	return 0;
}
