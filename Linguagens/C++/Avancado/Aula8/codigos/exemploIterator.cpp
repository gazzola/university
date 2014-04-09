/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploIterator.cpp - Mostra como utilizar a classe const_iterator.
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    typedef vector <int> IntVector;
    IntVector v;

    v.push_back(10);
    v.push_back(14);
    v.push_back(0);
    v.push_back(-8);
    v.push_back(30);

    // declara um iterator para um vetor
    IntVector::const_iterator iter;

    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }

    cout << endl;

    return 0;
}
