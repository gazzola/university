/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploStatic.cpp - Mostra como criar e utilizar membros de classe static.
 */

#include <iostream>

using namespace std;

class Ponto {
public:
	float x;
	float y;

	static int qtdPontos;
public:

	Ponto(float x, float y) {
		this->x = x;
		this->y = y;
		qtdPontos++;
	};

	~Ponto() {
		qtdPontos--;
	}

	static int getQtdPontos() {
		// Um comando como o seguinte é inválido:
		// x = 10;
		// porque x não é estático

		return qtdPontos;
	}
};

int Ponto::qtdPontos = 0;

int main() {
	// não é necessário que um objeto do tipo ponto esteja instaciando
	cout << "Quantidade de pontos: " << 
             Ponto::getQtdPontos() << endl;

	Ponto p1(10.0f, 14.0f);
	Ponto p2(10.0f, 14.0f);
	Ponto *p3 = new Ponto(4.0f, 5.2f);

	cout << "Quantidade de pontos: "
         << Ponto::getQtdPontos() << endl;

	delete p3;
	delete &p1;
	
	cout << "Quantidade de pontos: " 
         << Ponto::getQtdPontos() << endl;

    getchar();
      
    return 0;
}
