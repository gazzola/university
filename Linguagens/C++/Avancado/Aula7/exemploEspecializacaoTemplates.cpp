/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploEspecializacaoTemplates.cpp - Mostra especializar templaes de funções em C++
 */

#include <iostream>
#include <cstring>

using namespace std;

template <class T>
T maximo(T a, T b) {
  return (a > b) ? a : b;
}

// permite que a função máximo seja aplicada correntamente a char[]
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
