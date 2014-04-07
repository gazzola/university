/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploEncapsulamento.cpp - Mostra violar o sistema de encapsulamento dos 
 *                             campos das classes de C++
 */


#include <string>
#include <iostream>

using namespace std;

class Conta {

private:
	int numero;
	double saldo;

public:
	Conta(int numero, double saldo) {
		this->numero = numero;
		this->saldo = saldo;
		
	}

	double getSaldo() {
		return this->saldo;
	}

};

class ContaDetonada {

public:
	int numero;
	double saldo;
	
};



int main () {
	Conta *c = new Conta(1234, 100.00);
	ContaDetonada *cd = reinterpret_cast<ContaDetonada *> (c);

	cd->saldo = 100000.00;

	cout << "Saldo de c: " << c->getSaldo() << endl;

	delete c;

    cin.get();

	return 0;
}
