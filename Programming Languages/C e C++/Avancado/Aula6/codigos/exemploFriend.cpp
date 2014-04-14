/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploFriends.cpp - Mostra como utilizar a palavra reservada friend para
 *                      violar o emcapsulamento de membros.
 */
 

class Ponto {

private:
	float x;
	float y;

public:
	Ponto(float x, float y) {
		this->x = x;
		this->y = y;
	}
	
    friend void reverter(Ponto &); // declara uma fun��o amiga
  	friend class Circulo; // declara uma classe amiga

    void copiar(Ponto &p) {
		x = p.x; // uma classe � friend dela pr�pria
		y = p.y;
	}

};

void reverter(Ponto &p) {
	p.x = -p.x;
	p.y = -p.y;
}

class Circulo {
private:
	Ponto centro;
public:
	// esta fun��o tem acesso aos atributos da classe Ponto
	void deslocar(float v) {
		centro.x = centro.x + v;
		centro.y = centro.y + v;
	}
};

int main() {

	return 0;
}
