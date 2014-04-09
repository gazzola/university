/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * Retangulo.cpp - Arquivo que cont�m a implementa��o do m�todo que n�o s�o
 *                 inline na classe Retangulo.
 */

#include "Retangulo.h"

Retangulo::Retangulo(int a, int l) {
	this->altura = a;
	this->largura = l;
}

void Retangulo::setAltura(int a) {
	this->altura = a;
}

void Retangulo::setLargura(int l) {
	this->largura = l;
}

int Retangulo::area() {
	return this->altura * this->largura;
}

int Retangulo::perimetro() {
	return 2 * (this->altura + this->largura);
}

bool Retangulo::equals(Retangulo &r) {
	return (this->altura == r.altura && this->largura == r.largura);
}











