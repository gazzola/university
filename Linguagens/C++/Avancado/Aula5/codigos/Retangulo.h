/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * Retangulo.h - Arquivo que contém a definição da classe Retangulo
 */
 
#ifndef _RETANGULO_H_
#define _RETANGULO_H_

class Retangulo {
	private:
		int altura;
		int largura;

	protected:
		void setAltura(int a);
		void setLargura(int l);

	public:
		Retangulo(int a = 1, int l = 1);

		int getAltura() {
			return this->altura;
		}

		int getLargura() {
			return this->largura;
		}

		int perimetro();

		int area();

		bool equals(Retangulo &r);
		
};

#endif // #ifndef _RETANGULO_H_
