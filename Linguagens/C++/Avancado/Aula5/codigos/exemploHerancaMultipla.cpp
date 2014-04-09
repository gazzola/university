/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploHerancaMultipla.cpp - Mostra como utilizar a heran�a m�ltipla de
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
