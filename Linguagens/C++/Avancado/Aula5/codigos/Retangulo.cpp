/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * Retangulo.cpp - Arquivo que contém a implementação do método que não são
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











