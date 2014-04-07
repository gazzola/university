/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploArquivos3.c - Mostra como utilizar as funções fwrite e fread
 */

#include <stdio.h>

int main() {

    FILE *pf = fopen("exemploArquivos3.txt", "w");
    int i, conteudo[4], mat[] = { 1, 2, 3, 4 };

    if (pf != NULL) {
        fwrite(mat, sizeof(int), 4, pf);

        if (ferror(pf)) {
            printf("Erro ao escrever no arquivo.\n");
            exit(1);
        }
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }

    fclose(pf);

    pf = fopen("exemploArquivos3.txt", "r");


    if (pf != NULL) {
        fread(conteudo, sizeof(int), 4, pf);

        if (ferror(pf)) {
            printf("Erro ao ler arquivo.\n");
            exit(1);
        }

        for (i = 0; i < 4; i++) {
            printf("%d ", conteudo[i]);
        }

        printf("\n");
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }

    fclose(pf);
    
    getchar();

    return 0;
}
