/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploPonteiroFuncao.c - Exemplos de como utilizar ponteiros para funções.
 *
 *
 * Exemplo retirado do curso de C da ufmg
 * http://ead1.eee.ufmg.br/cursos/C/
 */

#include <stdio.h>
#include <string.h>

void printString(char *str, int (*func)(const char *)) {
	(*func)(str); // chamada a função através do ponteiro para função

	// maneira também válida de se fazer a chamada a função através do
	// ponteiro para função func
	func(str);

}

int main () {
	char string[20] = "Curso de C/C++";

	// Declaracao do ponteiro para função Funcao apontada é inteira e recebe
	// como parametro uma string constante
	int (*p)(const char *);

	// O ponteiro p passa a apontar para a função puts
	// que tem o seguinte prototipo: int puts(const char *)
	p = puts;
    p(string);

	printString(string, p); // O ponteiro é passado como parametro para PrintString
	return 0;
}
