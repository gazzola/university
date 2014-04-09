/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemplostruc2.c - Mostar como delimitar o n�mero m�ximo de bits que um campo possui na estrutura.
 */

#include <stdio.h>

struct Exemplo {
	int a:3;
	char c:4;
	long long l:40;
};

struct QuadroPPP {
	unsigned int endereco:8;
	unsigned int controle:8;
	unsigned int protocolo:16;
	unsigned char *informacao;
	unsigned int vereficacao:4;
};


int main() {
	struct Exemplo s;

	s.a = -5;
	printf("s.a = %d\n", s.a);
	s.a = 10;
	printf("s.a = %d\n", s.a);
	getch();
}
