/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploNamespaceFuncoes.cpp - Mostra como criar duas funções com o mesmo
 *                               protótipo mas que se encontram em namespaces
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
