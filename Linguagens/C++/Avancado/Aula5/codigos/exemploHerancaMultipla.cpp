/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploHerancaMultipla.cpp - Mostra como utilizar a herança múltipla de
 *                              classes em C++.
 */

#include <iostream>

using namespace std;

class A {
public:
	virtual void m() {
		cout << "Classe A\n";
	}
};

class B {
public:
	virtual void m() {
		cout << "Classe B\n";
	}
};

class C : public A, public B {
public:
	C () { }

	void m() {
		B::m();
	}
};

int main() {
	C c;
	c.m();
	cin.get();
	return 0;
}
