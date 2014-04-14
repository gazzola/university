/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploTypeid1.cpp - Exemplo de como utilizar o operador typeid.
 */

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Quadrado {
private:
	int aresta;
public:
	Quadrado(int aresta = 0) {
		this->aresta = aresta;
	}

	int area() {
		return this->aresta * this->aresta;
	}

	int perimetro() {
		return 2 * this->aresta;
	}
};


int main() {
	Quadrado q(10);
	Quadrado *p = new Quadrado(15);
    
	cout << typeid(q).name() << endl;
	cout << typeid(q.area()).name() << endl;
	cout << typeid(p).name() << endl;
	cout << typeid(*p).name() << endl;

	if (typeid(q) == typeid(*p)) {
		cout << "Tipos iguais" << endl;
	}

    delete p;

    cin.get();
    
	return 0;
}
