/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio2.cpp - Resposta ao segundo exercício da sexta aula do curso.
 */

#include <iostream>

using namespace std;


class Ponto {

public:
	float x;
	float y;

	Ponto() {}

	Ponto(float pX, float pY);
	
	Ponto operator + (Ponto &p);
	Ponto operator - (Ponto &p);
	bool operator == (Ponto &p1);
	bool operator != (Ponto &p1);
};

Ponto::Ponto(float pX, float pY) {
	x = pX;
	y = pY;
}

Ponto Ponto::operator + (Ponto &p) {
	return Ponto(x + p.x, y + p.y);
}

Ponto Ponto::operator - (Ponto &p) {
	return Ponto(x - p.x, y - p.y);
}

bool Ponto::operator == (Ponto &p) {
	return x == p.x && y == p.y;
}

bool Ponto::operator != (Ponto &p) {
	return x != p.x || y != p.y;
}

Ponto operator + (float a, Ponto &p) {
	return Ponto(p.x + a, p.y + a);
}

Ponto operator + (Ponto &p, float a) {
	return Ponto(p.x + a, p.y + a);
}

Ponto operator - (float a, Ponto &p) {
	return Ponto(p.x - a, p.y - a);
}

Ponto operator - (Ponto &p, float a) {
	return Ponto(p.x - a, p.y - a);
}


int main() {
	Ponto p1(10.0f, 14.0f);
	Ponto p2(10.0f, 14.0f);
	Ponto p3 = p1 + p2;
	Ponto p4 = p1 + 10.2f;
	Ponto p5 = 10.2f + p1;
	Ponto p6 = p1 - 10.2f;
	Ponto p7 = 10.2f - p1;

	cout << "p3 = (" << p3.x << ", " << p3.y << ")" << endl;
	p3 = p1 - p2;
	cout << "p3 = (" << p3.x << ", " << p3.y << ")" << endl;

	cout << "p3 == p1 ? " << (p3 == p1) << endl;
	cout << "p2 == p1 ? " << (p2 == p1) << endl;

	cout << "p3 != p1 ? " << (p3 != p1) << endl;
	cout << "p2 != p1 ? " << (p2 != p1) << endl;

	cout << "p4 = (" << p4.x << ", " << p4.y << ")" << endl;
	cout << "p5 = (" << p5.x << ", " << p5.y << ")" << endl;

	cout << "p6 = (" << p6.x << ", " << p6.y << ")" << endl;
	cout << "p7 = (" << p7.x << ", " << p7.y << ")" << endl;

	return 0;
}
