#include <stdio.h>
#define MAX 1000

typedef struct alunos{
    int c,m;
}Aluno;


int main(){

    int n, i, count=1, maior=0;
    Aluno aluno[MAX];

    scanf("%d", &n);
    while(n){

        printf("Turma %d\n", count++);
        for(i=0; i<n; i++){
            scanf("%d %d", &aluno[i].c, &aluno[i].m);
            if(i==0)
                maior = aluno[i].m;
            if(aluno[i].m > maior)
                maior = aluno[i].m;

        }

        for(i=0; i<n; i++){
            if(maior == aluno[i].m)
                printf("%d ", aluno[i].c);
        }

        printf("\n\n");
        scanf("%d", &n);
    }

    return 0;
}
