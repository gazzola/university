/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
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
	
    friend void reverter(Ponto &); // declara uma função amiga
  	friend class Circulo; // declara uma classe amiga

    void copiar(Ponto &p) {
		x = p.x; // uma classe é friend dela própria
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
	// esta função tem acesso aos atributos da classe Ponto
	void deslocar(float v) {
		centro.x = centro.x + v;
		centro.y = centro.y + v;
	}
};

int main() {

	return 0;
}
