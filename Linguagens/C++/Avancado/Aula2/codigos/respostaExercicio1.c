/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio1.c - Resposta ao primeiro exerc�cio da segunda aula
 */

#include <stdio.h>

#define min(a, b) (a > b) ? b : a
#define isPar(a) (a%2) ? 0 : 1

int main () {
	printf("10 eh par ? %d\n", isPar(10));
	printf("3 eh par ? %d\n", isPar(3));

	printf("min(18, 9) = %d\n", min(18, 9));
	printf("min(7, 45) = %d\n", min(7, 45));
	
}
