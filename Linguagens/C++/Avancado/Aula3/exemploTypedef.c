/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
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
	Nome nome; // declara�ao sem o struct

	if (b) {
		nome.valor = "Allan";
		printf("%s\n", nome.valor);
		b = false;
	}

	return 0;
}
