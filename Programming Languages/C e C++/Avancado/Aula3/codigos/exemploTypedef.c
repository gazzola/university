/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploTypedef.c - Exemplo de como utilizar a palavra reservada typedef
 */

#include <stdio.h>

enum bool {
	true = 1, false = 0
};

typedef enum bool boolean;


typedef struct N {
	char *valor;
} Nome;

int main() {
	boolean b = true;
	Nome nome; // declaraçao sem o struct

	if (b) {
		nome.valor = "Allan";
		printf("%s\n", nome.valor);
		b = false;
	}

	return 0;
}
