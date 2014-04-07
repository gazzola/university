/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploReinterpretCast.cpp - Mostra como utlizar o reinterpret_cast para
 *                              violar o encapsulamento.
 */

#include <iostream>

using namespace std;

class Ponto {
private:
    float x;
    float y;
public:
    Ponto(float x, float y) {
        this->x = x;
        this->y = y;
    }

    float getX() {
        return x;
    }

    float getY() {
        return y;
    }

};

int main() {
    Ponto *p = new Ponto(7.5f, 56.0f);
    // funciona!!!
    float *i = reinterpret_cast<float *> (p);

	// funciona!!!
	i[0] = 5.69f;
	i[1] = 44.56f;

    cout << p->getX() << endl;
    cout << p->getY() << endl;
    
    delete p;

    cin.get();

    return 0;
}
