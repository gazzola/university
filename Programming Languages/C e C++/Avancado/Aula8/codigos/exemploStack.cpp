/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploStack.cpp - Mostra utilizar a classe stack de C++.
 */

#include <iostream>
#include <stack>
#include <list>
#include <vector>

using namespace std;

template <class T>
void popPilha(T &s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "\n";
}


int main() {
    // pilha sobre uma deque
    stack <int> intDequeStack;
    // pilha sobre um vector
    stack <int, vector <int> > intVectorStack;
    // pilha sobre uma list
    stack <float, list <float> > floatListStack;

    for (int i = 0; i < 10; i++) {
        intDequeStack.push(i);
        intVectorStack.push(i);
        floatListStack.push(i);
    }

    popPilha(intDequeStack);
    popPilha(intVectorStack);
    popPilha(floatListStack);

    return 0;
}


