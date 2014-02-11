/*
* Media de alunos
*/

#include <stdio.h>

int main(){

    int i, qtda, qtdm;
    float n1, n2, n3, n4, media;


    printf("Digite a quantidade de alunos e a nota minima de aprovacao: ");
    scanf("%d %d", &qtda, &qtdm);

    for(i=0; i<qtda; i++){
        printf("\nDigite as 4 notas do aluno:\n");
        scanf("%f %f %f %f", &n1, &n2, &n3, &n4);

        media = (n1+n2+n3+n4)/4;

        if(media>=qtdm)
            printf("\nAprovado\n\n");
        else
            printf("\nReprovado\n\n");
    }

    return 0;

}
