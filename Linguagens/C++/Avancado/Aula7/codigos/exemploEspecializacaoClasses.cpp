/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploEspecializa��oClasses.cpp - Mostra como especializar templates de classes.
 */

#include <iostream>

using namespace std;

template <class T>
class A {
public:
       void imprimir() {
            cout << "Tipo generico" << endl;
       }

};

template <>
class A <int> {
public:
       void imprimir() {
            cout << "Tipo inteiro" << endl;
       }

       // novo membro
       void imprimir2();
};

void A<int>::imprimir2() {
     cout << "Tipo inteiro" << endl;
}


int main() {
    A <long> a;
    A <int>  b;
    A <char> c;

    a.imprimir();
    b.imprimir();
    b.imprimir2();
    c.imprimir();

    cin.get();

    return 0;
}
