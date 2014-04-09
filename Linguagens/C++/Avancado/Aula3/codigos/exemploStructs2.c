/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemplostruc2.c - Mostar como delimitar o número máximo de bits que um campo possui na estrutura.
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
