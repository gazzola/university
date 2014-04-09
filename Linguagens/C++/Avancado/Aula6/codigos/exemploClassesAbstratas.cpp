/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploClassesAbstratas.cpp - Mostra implementar classes abstratas em C++
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

    // torna Poligono uma classe Abstrata
    virtual int area() = 0;
    
    bool isMaior(Poligono &p) {
        return this->area() > p.area();
    }
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
    //Poligono p(10, 10); daria um erro de compilação
    Poligono *pp = &r;
    
    cout << "Area de r: " << r.area() << endl;
    cout << "Area de t: " << t.area() << endl;
    cout << "Area de pp: " << pp->area() << endl;
    
    pp = &t;
    cout << "Area de pp: " << pp->area() << endl;
    
    cout << "r > t ? " << r.isMaior(t) << endl;
    cout << "t > r ? " << t.isMaior(r) << endl;
    
    return 0;
}
