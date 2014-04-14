/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploPonteiroFuncao.c - Exemplos de como utilizar ponteiros para fun��es.
 *
 *
 * Exemplo retirado do curso de C da ufmg
 * http://ead1.eee.ufmg.br/cursos/C/
 */

#include <stdio.h>
#include <string.h>

void printString(char *str, int (*func)(const char *)) {
	(*func)(str); // chamada a fun��o atrav�s do ponteiro para fun��o

	// maneira tamb�m v�lida de se fazer a chamada a fun��o atrav�s do
	// ponteiro para fun��o func
	func(str);

}

int main () {
	char string[20] = "Curso de C/C++";

	// Declaracao do ponteiro para fun��o Funcao apontada � inteira e recebe
	// como parametro uma string constante
	int (*p)(const char *);

	// O ponteiro p passa a apontar para a fun��o puts
	// que tem o seguinte prototipo: int puts(const char *)
	p = puts;
    p(string);

	printString(string, p); // O ponteiro � passado como parametro para PrintString
	return 0;
}
