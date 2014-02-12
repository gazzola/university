#include <stdio.h>

void deslocaDireita(int n, int *vet){
    int i;

    for(i=0; i<n; i++){
       printf("digite um valor para o vetor[%.2d]:", i);
       scanf("%d", &vet[i]);
    }

    for(i=n-1; i>0; i--)
        vet[i] = vet[i-1];
    vet[0] = 0;

    for(i=0; i<n; i++)
        printf("vetor[%.2d] = %d\n", i, vet[i]);

}

int main(){

    int numv=10; int vet[10];
    deslocaDireita(numv, vet);

    return 0;
}
