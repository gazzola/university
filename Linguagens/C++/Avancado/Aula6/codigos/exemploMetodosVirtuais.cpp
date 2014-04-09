/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploMetodosVirtuais.cpp - Mostra como declarar.
 */

#include <iostream>

using namespace std;

class Poligono {

protected:
    int altura;
    int largura;
    
public:
   
    Poligono(int altura, int largura) {
        this->altura = altura;
        this->largura = largura;
    }

    
    virtual int area() { return 0; };
};

class Retangulo : public Poligono {
public:

    Retangulo(int altura, int largura)
        : Poligono(altura,  largura) {
    }

    int area() {
        return this->altura * this->largura;
    }
};

class Triangulo : public Poligono {
public:

    Triangulo(int altura, int largura) 
        : Poligono(altura,  largura) {
    }


    int area() {
        return (this->altura * this->largura) / 2;
    }
};

int main() {
    Retangulo r(10, 51);
    Triangulo t(45, 10);
    Poligono p(10, 10);
    Poligono *pp = &r;
    
    cout << "Area de r: " << r.area() << endl;
    cout << "Area de t: " << t.area() << endl;
    cout << "Area de p: " << p.area() << endl;
    cout << "Area de pp: " << pp->area() << endl;
    
    pp = &t;
    cout << "Area de pp: " << pp->area() << endl;
    
    getchar();
    
    return 0;
}
