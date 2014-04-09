/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio1.cpp - Resposta ao primeiro exercício da aula seis.
 */

#include <iostream>

using namespace std;

class ElementoGeometrico {

public:

    float virtual area() = 0;
    float virtual perimetro() = 0;
    
};

class Circulo : public ElementoGeometrico {

private:

    float raio;
    
public:

    Circulo(float raio) {
        this->raio = raio;
    }


    float area() {
        return 3.14f * (raio * raio);
    }

    float perimetro() {
        return 2 * 3.14f * raio;
    }
    
};

class Quadrado : public ElementoGeometrico {

private:

    float aresta;
       
public:

    Quadrado(float aresta) {
        this->aresta = aresta;
    }
    
    float area() {
        return this->aresta * this->aresta;
    }
    
    float perimetro() {
        return 2 * this->aresta;
    }
    
};

int main() {
    Circulo c(2.5f);
    Quadrado q(6.3);
    ElementoGeometrico *g;
    
    cout << "Area de c:      " << c.area() << endl;
    cout << "Perimetro de c: " << c.perimetro() << endl;
    cout << "Area de q:      " << q.area() << endl;
    cout << "Perimetro de q: " << q.perimetro() << endl;
    
    g = &c;
    cout << "Area de g:      " << g->area() << endl;
    cout << "Perimetro de g: " << g->perimetro() << endl;
    
    g = &q;
    cout << "Area de g:      " << g->area() << endl;
    cout << "Perimetro de g: " << g->perimetro() << endl;
    
    return 0;
}
