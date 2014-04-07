/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio1.cpp - Resposta ao primeiro exercício da quinta aula do curso.
 */

#include <iostream>
#include <string>

using namespace std;

//////////////////////
// CLASSE EMPREGADO //
//////////////////////
class Empregado {

private:
	string nome;
	string email;
	string celular;
	float salario;
	int departamento;

public:
	Empregado() {};
	Empregado(string nome, string email, string celular, float salario, int departamento);

	string getNome() {
		return this->nome;
	}

	void setNome(string nome) {
		this->nome = nome;
	}

	string getEmail() {
		return this->email;
	}

	void setEmail(string email) {
		this->email = email;
	}

	string getCelular() {
		return this->celular;
	}

	void setCelular(string celular) {
		this->celular = celular;
	}

	float getSalario() {
		return this->salario;
	}

	void setSalario(float salario) {
		if (salario > 0.0f) {
			this->salario = salario;
		}
	}

	int getDepartamento() {
		return this->departamento;
	}

	void setDepartamento(int departamento) {
		this->departamento = departamento;
	}

};

Empregado::Empregado(string nome, string email, string celular, float salario, int departamento) {
	this->nome = nome;
	this->email = email;
	this->celular = celular;
	this->salario = salario;
	this->departamento = departamento;
}

////////////////////
// CLASSE GERENTE //
////////////////////
class Gerente : public Empregado {

private:
	int tamanhoGrupo;
	Empregado *grupo;

public:

	Gerente(string nome, string email, string celular, float salario, 
			int departamento, Empregado *grupo, int tamanhoGrupo);

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

Gerente::Gerente(string nome, string email, string celular, float salario, 
	int departamento, Empregado *grupo, int tamanhoGrupo) 
	: Empregado(nome, email, celular, salario, departamento) {
	
	this->grupo = grupo;
	this->tamanhoGrupo = tamanhoGrupo;
}

///////////////////////
// CLASSE SECRETARIA //
///////////////////////
class Secretaria : public Empregado {
private:
	Empregado chefe;
public:
	Secretaria(string nome, string email, string celular, float salario, 
	int departamento, Empregado chefe);

	Empregado getChefe() {
		return this->chefe;
	}

	void setChefe(Empregado e) {
		this->chefe = chefe;
	}
};

Secretaria::Secretaria(string nome, string email, string celular, float salario, 
	int departamento, Empregado chefe) 
	: Empregado(nome, email, celular, salario, departamento) {
		this->chefe = chefe;				   
}

///////////////////////
// CLASSE TEMPORARIO //
///////////////////////
class Temporario {
private:
	int dia;
	int mes;
	int ano;
	int mesesDuracao;

public:
	
	Temporario(int dia, int mes, int ano, int mesesDuaracao);

	int getMesesDuracao() {
		return this->mesesDuracao;
	}

	void setMesesDuracao(int mesesDuracao) {
		this->mesesDuracao = mesesDuracao;
	}

	int	getDia() {
		return this->dia;
	}

	void setDia(int dia) {
		this->dia = dia;
	}

	int getMes() {
		return this->mes;
	}

	void setMes(int mes) {
		this->mes = mes;
	}

	int getAno() {
		return this->ano;
	}

	void setAno(int ano) {
		this->ano = ano;
	}
};

Temporario::Temporario(int dia, int mes, int ano, int mesesDuaracao) {
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
	this->mesesDuracao = mesesDuaracao;
}



///////////////////////////
// CLASSE SECRETARIATEMP //
///////////////////////////
class SecretariaTem : public Secretaria, public Temporario {
public:
	SecretariaTem(string nome, string email, string celular, float salario, 
		int departamento, Empregado chefe, int dia, int mes, 
		int ano, int mesesDuaracao);
};

SecretariaTem::SecretariaTem(string nome, string email, string celular, float salario, 
		int departamento, Empregado chefe, int dia, int mes, 
		int ano, int mesesDuaracao) : Secretaria (nome, email, celular, salario, 
		departamento, chefe), Temporario(dia, mes, ano, mesesDuaracao) {
		
}

//////////////////////
// CLASSE CONSULTOR //
//////////////////////
class Consultor : public Empregado, public Temporario {
private:	
	string areaConsutoria;

public:
	string getAreaconsultoria() {
		return this->areaConsutoria;
	}

	string setAreaConsultoria(string areaConsultoria) {
		this->areaConsutoria = areaConsutoria;
	}
};

int main() {
	return 0;
}
