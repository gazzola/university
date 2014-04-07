/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exmeploStatic.cpp - Mostra como utilizar classe herança em C++.
 */

#include <iostream>
#include <string>

using namespace std;

class Empregado {
private:
	string nome;
	float salario;
	int numDepartamento;
	int ramal;

public:

	Empregado(string nome, float salario, int numDepartamento, int ramal);

	string getNome() {
		return this->nome;
	}

	float getSalario() {
		return this->salario;
	}

	int getNumDepartamento() {
		return this->numDepartamento;
	}

	int getRamal() {
		return this->ramal;
	}

	void setNome(string nome) {
		this->nome = nome;
	}

	void setSalario(float salario) {
		this->salario = salario;
	}

	void setNumDepartamento(int numDepartamento) {
		this->numDepartamento = numDepartamento;
	}

	void setRamal(int ramal) {
		this->ramal = ramal;
	}

};

Empregado::Empregado(string nome, float salario, int numDepartamento, int ramal) {
	this->nome = nome;
	this->salario = salario;
	this->numDepartamento = numDepartamento;
	this->ramal = ramal;
}

ostream &operator<<(ostream &output, Empregado &e) {
	output << "Nome: " << e.getNome() << endl;
	output << "Salario: " << e.getSalario() << endl;
	output << "Numero do departamento: " << e.getNumDepartamento() << endl;
	output << "Ramal: " << e.getRamal() << endl;
	return output;
}

class Gerente : public Empregado {
private:
	int tamanhoGrupo;
	Empregado *grupo;

public:

	Gerente(string nome, float salario, int numDepartamento,
			int ramal, Empregado *grupo, int tamanhoGrupo);

	int getTamanhoGrupo() {
		return this->tamanhoGrupo;
	}

	Empregado *getGrupo() {
		return this->grupo;
	}

	void setGrupo(Empregado *grupo, int tamanhoGrupo) {
		this->grupo = grupo;
		this->tamanhoGrupo = tamanhoGrupo;
	}
};

Gerente::Gerente(string nome, float salario, int numDepartamento,
	int ramal, Empregado *grupo, int tamanhoGrupo)
	: Empregado(nome, salario, numDepartamento, ramal) {

	this->grupo = grupo;
	this->tamanhoGrupo = tamanhoGrupo;
}

ostream &operator<<(ostream &output, Gerente &g) {
    Empregado e = (Empregado) g;
	output << e;

	output << "Subordinados: " << endl;
	for (int i = 0; i < g.getTamanhoGrupo(); i++) {
		output << g.getGrupo()[i].getNome() << endl;
	}
	return output;
}

int main() {
	Empregado e("Fulano", 1000.00f, 3, 5);
	Gerente g("Beltrano", 5000.00f, 3, 5, &e, 1);

	cout << e;
	cout << "--------------------------\n";
	cout << g;

   	// Também podemos ter ponteiros para Classe
   	// Um ponteiro para uma classe básica pode apontar
    // para qualquer uma de suas sub-classes
   	Empregado *emp = new Gerente
           ("Cicrano", 5000.0f, 3, 4, &g, 1);

   	emp->setNome("Cicrano da Silva");
	cout << "--------------------------\n";
	// chama o operador << de Empregado
	cout << *emp;

	Gerente *ge = (Gerente *) emp;
	ge->setGrupo(&e, 1);
    cout << "--------------------------\n";
	// chama o operador << de Gerente
	cout << *ge;

   	delete emp;
   	
	return 01;
}
