/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploArquivos1.c - Mostra como utilizar as fun��es putc e getc
 */

#include <stdio.h>

int main() {
    // cria o arquivo se ele n�o existir
    FILE *fp = fopen("ExemploArquivos1.txt", "w");
    char *s = "Centro de Informatica";
    char c;
    int i;

    // se n�o houve erro
    if (fp != NULL) {
        // imprime a string caracter por caracter no arquivo
        for (i = 0; s[i]; i++) {
           putc(s[i], fp);
        }
    } else {
        printf("Imposs�vel abrir o arquivo.");
    }

    // fecha o arquivo
    fclose(fp);

    // abre o arquivo para leitura
    fp = fopen("ExemploArquivos1.txt", "r");

    // se n�o houve erro
    if (fp != NULL) {
        // l� todos os caracteres do arquivo
        c = getc(fp);
        while (c != EOF) {
            putchar(c);
            c = getc(fp);
        }
    } else {
        printf("Imposs�vel abrir o arquivo.");
    }

    putchar('\n');

    // fecha o arquivo
    close(fp);
    
    getchar();

    return 0;
}
