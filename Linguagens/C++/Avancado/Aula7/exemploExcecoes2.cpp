/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploExcecoes2.cpp - Exemplo de como utilizar lan�ar e tratar qualquer 
 *                        tipo de dado em C++
 */

#include <iostream>

using namespace std;

int dividir(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        // em C++ podemos lan�ar qualquer coisa
        throw "Divisao por 0!";
    }
}

int main() {
    try {
        // try-catch aninhado
        try {
            cout << dividir(4, 6) << endl; // ok
        } catch (int) {
            cout << "Um inteiro foi lan�ado" << endl;
        } catch (const char *s) {
            cout << s << endl;
        }
        
        cout << dividir(4, 0) << endl; // lan�a a string
    } catch (const char *s) {
        cout << s << endl;
    } catch (...) {
        cout << "Erro desconhecido" << endl;
    }

    cin.get();    

    return 0;
}
