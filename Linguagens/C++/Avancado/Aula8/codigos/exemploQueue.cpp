/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
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
		// pop da classe queue é void
		fila.pop();
	}

	cout << endl;

	return 0;
}
