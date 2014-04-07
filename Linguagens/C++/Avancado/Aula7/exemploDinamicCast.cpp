/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploDynamicCast.cpp - Mostra como utlizar o dynamic_cast.
 */

#include <iostream>

using namespace std;

class Animal {
    public: virtual ~Animal() {}
};

class Cachorro : public Animal {};

class Gato : public Animal {};

int main() {
    Animal* a = new Gato();

    Cachorro* c = dynamic_cast<Cachorro*>(a);
    cout << "c = " << ((c == NULL) ? "NULL" : "Nao NULO") << endl;

    Gato* g = dynamic_cast<Gato*>(a);
    cout << "g = " << ((g == NULL) ? "NULL" : "Nao nulo") << endl;

    cin.get();
    
    return 0;
}
