/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * main.cpp - Arquivo que cont�m os testes da classe Retangulo
 */

#include <iostream>
#include "Retangulo.h"
#include "Retangulo.cpp"

using namespace std;

int main() {
	Retangulo *r = new Retangulo(10, 15);
	Retangulo *array = new Retangulo[10];
	Retangulo ret(10, 15);

	cout << "Area de r: " << r->area() << endl;
	cout << "Perimetro de r: " << r->perimetro() << endl;
	cout << "r = array[0]: " << r->equals(array[0]) << endl;
	cout << "r = ret: " << r->equals(ret) << endl;

	delete r;
	delete[] array;

	return 0;
}






