/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploFloat.c - Mostra como utilizar o header float.h para descobri os 
 *                  valores m�ximos e m�nimos dos tipos de ponto flutuante.
 */

#include <stdio.h>
#include <float.h>

int main() {
	printf("Maior double: %lf\n", DBL_MAX);
	printf("Menor double positivo: %lf\n", DBL_MIN);
	printf("Precisao: %d\n\n", DBL_DIG);

	printf("Maior float: %f\n", FLT_MAX);
	printf("Menor float positivo: %f\n", FLT_MIN);
	printf("Precisao: %d\n\n", FLT_DIG);

	getchar();
	
	return 0;
}
