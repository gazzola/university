/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploStatic.c - Mostra utilizar a palavra reservada static.
 */

#include <stdio.h>

// Evita que outros m�dulos possam modificar e ver esta vari�vel
static int numero = 0;

int f() {
	// Declara a como uma vari�vel statica
	// assim o valor da no final de uma chamada da func�o
	// ser� o valor inicial de a na pr�xima chamada
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
