/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio2.cpp - Resposta ao segundo exerc�cio da oitava aula.
 */

#include <iostream>
#include <vector>

using namespace std;

template <class T>
bool isPalindromo(vector<T> &v) {
    int s = v.size() / 2;

    for (int i = 0; i <= s; i++) {
        if (v[i] != v[v.size()-i-1]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector <int> v;

    v.push_back(13);
    v.push_back(0);
    v.push_back(45);
    v.push_back(97);
    v.push_back(56);
    cout << "v � um palindromo ? " << (isPalindromo(v) ? "Sim" : "Nao") << endl;

    v.clear();
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    cout << "v � um palindromo ? " << (isPalindromo(v) ? "Sim" : "Nao") << endl;

    v.clear();
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    cout << "v � um palindromo ? " << (isPalindromo(v) ? "Sim" : "Nao") << endl;

    v.clear();
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    v.push_back(4);
    cout << "v � um palindromo ? " << (isPalindromo(v) ? "Sim" : "Nao") << endl;


    return 0;
}
