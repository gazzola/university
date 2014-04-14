/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploExcecoes2.cpp - Exemplo de como utilizar lançar e tratar qualquer 
 *                        tipo de dado em C++
 */

#include <iostream>

using namespace std;

int dividir(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        // em C++ podemos lançar qualquer coisa
        throw "Divisao por 0!";
    }
}

int main() {
    try {
        // try-catch aninhado
        try {
            cout << dividir(4, 6) << endl; // ok
        } catch (int) {
            cout << "Um inteiro foi lançado" << endl;
        } catch (const char *s) {
            cout << s << endl;
        }
        
        cout << dividir(4, 0) << endl; // lança a string
    } catch (const char *s) {
        cout << s << endl;
    } catch (...) {
        cout << "Erro desconhecido" << endl;
    }

    cin.get();    

    return 0;
}
