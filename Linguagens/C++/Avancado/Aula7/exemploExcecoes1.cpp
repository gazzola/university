/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploExcecoes1.cpp - Simples exemplo de como criar e tratar exce��es em C++.
 */

#include <iostream>

using namespace std;

class ParametroInvalidoException {
};

class Circulo {
private:
    float raio;

public:
    float getRaio() {
        return this->raio;
    }

    void setRaio(float raio);
};

void Circulo::setRaio(float raio) {
    if (raio >= 0) {
        this->raio = raio;
    } else {
        throw ParametroInvalidoException();
    }
}

int main() {
    Circulo c;

    try {
        c.setRaio(10);
        c.setRaio(-18); // lan�a a exce��o
        c.setRaio(15);
    } catch (ParametroInvalidoException &) {
        cout << "Raio invalido!!!" << endl;
    }

    return 0;
}
