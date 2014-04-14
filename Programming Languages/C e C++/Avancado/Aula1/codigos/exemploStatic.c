/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploStatic.c - Mostra utilizar a palavra reservada static.
 */

#include <stdio.h>

// Evita que outros módulos possam modificar e ver esta variável
static int numero = 0;

int f() {
	// Declara a como uma variável statica
	// assim o valor da no final de uma chamada da funcão
	// será o valor inicial de a na próxima chamada
	static int a = 0;

	a = a + 2;
	return a;
}

int main() {
	printf("Chamada numero 1: %d\n", f());
    printf("Chamada numero 2: %d\n", f());
    printf("Chamada numero 3: %d\n", f());
    printf("Chamada numero 4: %d\n", f());
}
