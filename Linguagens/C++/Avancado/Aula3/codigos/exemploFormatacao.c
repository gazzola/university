/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploFomatacao.c - Mostra como fomatar a saída através da função printf
 */


#include <stdio.h>

int main() {
	printf(" %%4d, 45 -> |%4d|\n\n", 45); 	 // |  45|
	printf("%%-4d, 45 -> |%-4d|\n\n", 45);	 // |45  |
	printf("%%04d, 45 -> |%04d|\n\n", 45);   // |0045|
	
	printf("  %%.2f, 75.777 -> |%.2f|\n\n", 75.777);   // |75,78|
	printf(" %%8.2f, 75.777 -> |%8.2f|\n\n", 75.777);  // |   75,78|
	printf("%%-8.2f, 75.777 -> |%-8.2f|\n\n", 75.777); // |75,78   |

	printf ("%%-10s, \"Ola\" -> |%-10s|\n\n","Ola");   // |Ola       |

	return 0;
}
