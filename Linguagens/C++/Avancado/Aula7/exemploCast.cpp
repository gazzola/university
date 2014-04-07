/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio1.cpp - Resposta ao primeiro exercício da aula sete.
 */

#include <iostream>

using namespace std;

class A {
    private:
        int a;

    public:
        A() {
            a = 9;
        }

        int getA() {
            return a;
        }
};

class B {
    public:
        int b;

        void crash() {
            cout << b << endl;
        }
};

int main() {
	A a;
	B *b;
	b = (B *) &a; // compila normalmente
    b->crash();
    b->b = 50;
    cout << "a.getA() : " << a.getA() << endl;
    cin.get();
	return 0;
}
