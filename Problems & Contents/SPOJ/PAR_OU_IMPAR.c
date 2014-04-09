#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 11

struct Arquivo{
    char n1[SIZE];
    char n2[SIZE];
};

int main(){

struct Arquivo *arq;
arq = (struct Arquivo *) malloc (sizeof(struct Arquivo));
int count=1, a,b,n;

FILE *entrada = fopen("entrada.txt", "r");

while(1){

    fscanf(entrada, "%d", &n);
    if(n == 0)
        break;

    fscanf(entrada, "%s", &arq[count-1].n1);
    fscanf(entrada, "%s", &arq[count-1].n2);

    printf("Teste %d\n", count);

    int x=n;
    while(x--){
        fscanf(entrada, "%d %d", &a, &b);
        int soma = a+b;
        if(soma % 2 == 0){
            printf("%s\n", arq[count-1].n1);
        }
        else{
            printf("%s\n", arq[count-1].n2);
        }
        if(x==0)
            printf("\n");
    }

    count++;
}

return 0;
}
