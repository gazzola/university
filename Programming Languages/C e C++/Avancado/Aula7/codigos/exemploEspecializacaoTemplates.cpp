/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploEspecializacaoTemplates.cpp - Mostra especializar templaes de fun��es em C++
 */

#include <iostream>
#include <cstring>

using namespace std;

template <class T>
T maximo(T a, T b) {
  return (a > b) ? a : b;
}

// permite que a fun��o m�ximo seja aplicada correntamente a char[]
template <char *>
char *maximo(char *a, char *b) {
  return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    cout << maximo(10, 5) << endl;
    cout << maximo("C++", "Java") << endl;
    cout << maximo("AAACC", "AAACB") << endl;
    cin.get();
    return 0;
}
