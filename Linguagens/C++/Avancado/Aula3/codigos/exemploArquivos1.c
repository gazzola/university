/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * exemploArquivos1.c - Mostra como utilizar as funções putc e getc
 */

#include <stdio.h>

int main() {
    // cria o arquivo se ele não existir
    FILE *fp = fopen("ExemploArquivos1.txt", "w");
    char *s = "Centro de Informatica";
    char c;
    int i;

    // se não houve erro
    if (fp != NULL) {
        // imprime a string caracter por caracter no arquivo
        for (i = 0; s[i]; i++) {
           putc(s[i], fp);
        }
    } else {
        printf("Impossível abrir o arquivo.");
    }

    // fecha o arquivo
    fclose(fp);

    // abre o arquivo para leitura
    fp = fopen("ExemploArquivos1.txt", "r");

    // se não houve erro
    if (fp != NULL) {
        // lê todos os caracteres do arquivo
        c = getc(fp);
        while (c != EOF) {
            putchar(c);
            c = getc(fp);
        }
    } else {
        printf("Impossível abrir o arquivo.");
    }

    putchar('\n');

    // fecha o arquivo
    close(fp);
    
    getchar();

    return 0;
}
