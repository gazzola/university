/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * ExemploInterfaces.cpp - Mostra como simular a criação e implementação de 
 *                         interfaces em C++
 */



#include <iostream>

using namespace std;

class ElementoGeometrico {
public:
	virtual int area() const = 0;

	virtual int perimetro() const = 0;

};

class ComponenteGrafico {
public:
	virtual void exibir() const = 0;

	virtual bool colidiu(const ComponenteGrafico &e) const = 0;
};

class Quadrado : 
    public ElementoGeometrico , 
    public ComponenteGrafico {
    
private:
	int aresta;

public:

	Quadrado(int aresta) {
		this->aresta = aresta;
	}

	virtual int area() const {
		return this->aresta * this->aresta;
	};

	virtual int perimetro() const {
		return this->aresta * 4;
	}

	virtual void exibir() const {
		int i, j;

		for (i = 0; i < this->aresta; i++) {
			cout << '*';
		}

		for (i = 0; i < this->aresta-2; i++) {
			cout << "\n*";
			
			for (j = 0; j < this->aresta - 2; j++) {
				cout << ' ';
			}

			cout << '*';
		}

		cout << "\n*";
		for (i = 0; i < this->aresta-2; i++) {
			cout << '*';
		}
		cout << '*';
		
	}

	virtual bool colidiu(const ComponenteGrafico &e) const {
		return false;
	}


};


int main() {
	Quadrado *q = new Quadrado(8);
	ElementoGeometrico *eG = q;
	ComponenteGrafico *cG = q;

	cout << "Perimetro: " << eG->perimetro() << endl;
	cout << "Area: " << eG->area() << endl;
	cG->exibir();
	cout << endl;
	
	delete q;
	
	return 0;
}
