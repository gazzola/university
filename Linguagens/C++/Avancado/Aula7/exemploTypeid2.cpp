/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploTypeid2.cpp - Mostra o comportamento do operador typeid com ponteiros
 *                      e heran�a.
 */

#include <iostream>
#include <typeinfo>

using namespace std;

struct A {};

struct B : A{};

struct C : A {};

int main() {
	A *p1 = new B();
	A *p2 = new C();


	cout << typeid(*p1).name()
		 << endl
	     << typeid(*p2).name()
		 << endl;

	cout << typeid(*((B*) p1)).name()
		 << endl
	     << typeid( *((C*)p2)).name()
		 << endl;

    delete p1;
    delete p2;
    
    cin.get();    

	return 0;
}
