/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio1.c - Resposta ao primeiro exercício da segunda aula
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
