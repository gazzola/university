/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploExcecoes1.cpp - Simples exemplo de como criar e tratar exceções em C++.
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
        c.setRaio(-18); // lança a exceção
        c.setRaio(15);
    } catch (ParametroInvalidoException &) {
        cout << "Raio invalido!!!" << endl;
    }

    return 0;
}
