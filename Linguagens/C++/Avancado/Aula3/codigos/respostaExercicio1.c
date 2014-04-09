/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com/
 *
 * respostaExercicio1.c - Resposta ao primeiro exerc�cio da terceira aula
 */


#include <stdio.h>

int main(int agrc, char *agrv[]) {
    FILE *f = fopen("respostaExercicio4.txt", "w");
    char nome[100];

    if (f != NULL) {
        fprintf(f, "Alllan Diego Silva Lima");
        fclose(f);

        f = fopen("respostaExercicio4.txt", "r");

        if (f != NULL) {
            fgets(nome, 99, f);
            printf("%s\n", nome);
        } else {
            printf("Arquivo inexistente!\n");
        }
    } else {
        printf("Arquivo inexistente!\n");
    }

    return 0;
}
