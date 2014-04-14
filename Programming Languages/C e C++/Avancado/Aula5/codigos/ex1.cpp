#include <iostream>
#include <typeinfo>

using namespace std;


/////////////////////////////////////
// EMPREGADO
/////////////////////////////////////
class Empregado{
	private:
		static unsigned int id;
		string nome, email, celular;
		float salario;
		int departamento;

	public:
		Empregado(){
			this->id++;
		};

		Empregado(string nome, string email, string celular, float salario, int departamento);

		string getNome(){
			return this->nome;
		}

		void setNome(string nome){
			this->nome = nome;
		}

		string getEmail(){
			return this->email;
		}

		void setEmail(string email){
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
			if (salario > 0.0f)
				this->salario = salario;
		}

		int getDepartamento() {
			return this->departamento;
		}

		void setDepartamento(int departamento) {
			this->departamento = departamento;
		}

		int getId(){
			return this->id;
		}

};

unsigned int Empregado::id = 0;

Empregado::Empregado(string nome, string email, string celular, float salario, int departamento){
	this->id++;
	this->setNome(nome);
	this->setEmail(email);
	this->setCelular(celular);
	this->setSalario(salario);
	this->setDepartamento(departamento);
}

std::ostream& operator<<(std::ostream &output, Empregado &e){
	cout << typeid(e).name() << endl;
	output << "Nome: " << e.getNome() << endl;
	output << "Email: " << e.getEmail() << endl;
	output << "Celular: " << e.getCelular() << endl;
	output << "Salario: " << e.getSalario() << endl;
	output << "Departamento: " << e.getDepartamento() << endl << endl;
	return output;
}


/////////////////////////////////////
// GERENTE <- Empregado
/////////////////////////////////////
class Gerente: public Empregado{

	private:
		Empregado *gerenciados;
		int numGerenciados;


	public:
		Gerente(string nome, string email, string celular, float salario, int departamento, Empregado *gerenciados, int numGerenciados);

		Empregado *getGerenciados(){
			return this->gerenciados;
		}

		void setGerenciados(Empregado *gerenciados){
			this->gerenciados = gerenciados;
		}

		int getNumGerenciados(){
			return this->numGerenciados;
		}

		void setNumGerenciados(int numGerenciados){
			this->numGerenciados = numGerenciados;
		}

};

Gerente::Gerente(string nome, string email, string celular, float salario, int departamento, Empregado *gerenciados, int numGerenciados):
	Empregado(nome, email, celular, salario, departamento){
	this->setGerenciados(gerenciados);
	this->setNumGerenciados(numGerenciados);
};



/////////////////////////////////////
// SECRETARIA <- Empregado
/////////////////////////////////////
class Secretaria: public Empregado{

	private:
		Empregado chefe;

	public:
		Secretaria(string nome, string email, string celular, float salario, int departamento, Empregado chefe);
		
		Empregado getChefe(){
			return this->chefe;
		}

		void setChefe(Empregado chefe){
			this->chefe = chefe;
		}
};

Secretaria::Secretaria(string nome, string email, string celular, float salario, int departamento, Empregado chefe):
	Empregado(nome, email, celular, salario, departamento){
	this->setChefe(chefe);
}



/////////////////////////////////////
// TEMPORARIO
/////////////////////////////////////
class Temporario{

	private:
		string dataContrato;
		int numMeses;

	public:
		Temporario(string dataContrato, int numMeses){
			this->setDataContrario(dataContrato);
			this->setNumMeses(numMeses);
		};

		string getDataContrato(){
			return this->dataContrato;
		}

		void setDataContrario(string dataContrato){
			this->dataContrato = dataContrato;
		}

		int getNumMeses(){
			return this->numMeses;
		}

		void setNumMeses(int numMeses){
			this->numMeses = numMeses;
		}

};



/////////////////////////////////////
// SECRETARIA TEMPORARIA
/////////////////////////////////////
class SecretariaTemporaria: public Temporario, public Secretaria{

	public:
		SecretariaTemporaria(string dataContrato, int numMeses, string nome, string email, string celular, float salario, int departamento, Empregado chefe);
};

SecretariaTemporaria::SecretariaTemporaria(string dataContrato, int numMeses, string nome, string email, string celular, float salario, int departamento, Empregado chefe):
	Temporario(dataContrato, numMeses),
	Secretaria(nome, email, celular, salario, departamento, chefe){
}



/////////////////////////////////////
// CONSULTOR
/////////////////////////////////////
class Consultor: public Temporario, public Empregado{
	private:	
		string areaConsutoria;

	public:
		string getAreaconsultoria() {
			return this->areaConsutoria;
		}

		void setAreaConsultoria(string areaConsultoria) {
			this->areaConsutoria = areaConsutoria;
		}
};


int main(int argc, char const *argv[]){
	
	cout << "MINHA EMPRESA\n=======================\n" << endl;

	Empregado *e1 = new Empregado();
	cout << e1->getId() << endl;
	e1->setNome("Marcos");
	e1->setEmail("marcos@gmail.com");
	e1->setCelular("84132621");
	e1->setSalario(450.75);
	e1->setDepartamento(1);
	cout << *e1;

	Empregado *e2 = new Empregado("Jesus", "jesus@gmail.com", "99669966", 55.55, 1);
	cout << e2->getId() << endl;
	cout << *e2;


	int qtdEmpregados = 2;
	Empregado *arr = new Empregado[qtdEmpregados];
	arr[0] = *e1;
	arr[1] = *e2;


	Gerente *g1 = new Gerente("Satanas", "satan@gmail.com", "66666666", 66.66, 2, arr, qtdEmpregados);
	Empregado *temp = g1->getGerenciados();

	cout << endl << "USUARIOS MINISTRADOS PELO GERENTE:" << endl;
	cout << g1->getId() << endl;
	cout << *g1 << endl;

	for(int i=0; i<g1->getNumGerenciados(); i++)
		cout << temp[i] << endl;



	SecretariaTemporaria *st1 = new SecretariaTemporaria("08/09/2014", 8, "Juliana", "ju@gmail.com", "99556677", 69.69, 4, *e1);
	cout << *st1 << endl;
	cout << st1->getNumMeses() << "meses" << endl;
	cout << st1->getDataContrato() << endl;


	delete e1;
	delete e2;
	delete[] arr;  //ja deleta o temp tbm, nao fez clone do objeto, apenas o referenciou (partilham a mesma instancia (like others languages))
	delete g1;
	delete st1;

	return 0;
}