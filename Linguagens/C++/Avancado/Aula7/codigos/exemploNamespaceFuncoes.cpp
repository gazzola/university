/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploNamespaceFuncoes.cpp - Mostra como criar duas fun��es com o mesmo
 *                               prot�tipo mas que se encontram em namespaces
 *                               distintos  
 */

#include <iostream>

using namespace std;

namespace A {
    void f() {
        cout << "Funcao f() do namespace A" << endl;
    }
}

namespace B {
    void f() {
        cout << "Funcao f() do namespace B" << endl;
    }
}

void g() {
    using namespace B;
    f();
}

int main() {
    A::f();
    g();    
    B::f();
    cin.get();
    return 0;
}
