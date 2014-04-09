/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploOperador1.cpp - Mostra fazer overloads de operadores em C++
 */


#include <iostream>

using namespace std;


class Ponto {

public:
	float x;
	float y;

	Ponto(float pX, float pY);

	Ponto operator + (Ponto &p1);

};

Ponto::Ponto(float pX, float pY) {
	x = pX;
	y = pY;
}

Ponto Ponto::operator + (Ponto &p) {
	return Ponto(x + p.x, y + p.y);
}

// Também podemos re-definir um operador sem que o protótipo do método esteja
// declarado na função
Ponto operator - (Ponto &p1, Ponto &p2) {
	return Ponto(p1.x - p2.x, p1.y - p2.y);
}

Ponto operator +(Ponto &p, float v) {
	return Ponto(p.x + v, p.y + v);
}

int main() {
	Ponto p1(10.0f, 14.0f);
	Ponto p2(8.0f, 5.0f);
	Ponto p3 = p1 + p2;
	Ponto p4 = p1.operator +(p2); // outra maneira da chamar
	Ponto p5 = p1 - p2;
	Ponto p6 = p1 + 10.0f;
	// Não compila
	//Ponto p6 = 10.0f + p1;

	cout << "p3 = (" << p3.x << ", " << p3.y << ")" << endl;
	cout << "p4 = (" << p4.x << ", " << p4.y << ")" << endl;
	cout << "p5 = (" << p5.x << ", " << p5.y << ")" << endl;
	cout << "p6 = (" << p6.x << ", " << p6.y << ")" << endl;

	return 0;
}
