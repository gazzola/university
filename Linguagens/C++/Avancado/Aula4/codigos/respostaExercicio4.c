/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExerccio4.c - Resposta ao quato exercício da quarta aula
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main(int argc, char *argv[]) {
	double a, b;
	int n;
	
	switch (argv[1][0]) {
		case 'a':
			n = atoi(argv[2]);
			printf("%d\n", abs(n));
			break;
		case 'p':
			a = atof(argv[2]);
			b = atof(argv[3]);
			printf("%lf\n", pow(a,b));
			break;
		case 's':
			a = atof(argv[2]);
			printf("%lf\n", sqrt(a));
			break;
		case 'n':
			a = atof(argv[2]);
			printf("%lf\n", sin(a * PI / 180));
			break;
		case 'c':
			a = atof(argv[2]);
			printf("%lf\n", cos(a * PI / 180));
			break;
		case 't':
			a = atof(argv[2]);
			printf("%lf\n", tan(a * PI / 180));
			break;
		default:
			printf("Parametros Invalidos\n");
			break;
	}

	return 0;
}
