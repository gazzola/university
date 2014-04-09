#include <stdio.h>

int main(){

int a=1, v, x, y, ct=1, vet[101], maiores[101];
FILE *entrada = fopen("entrada.txt", "r");

while(1){
    fscanf(entrada, "%d %d", &a, &v);
    if(a==0 || v==0)
        break;

    //vet = (int*) malloc (a*sizeof(int));

    int i;
    for(i=1; i<=a; i++){
        vet[i]=0;
        maiores[i]=0;
    }


    for(i=1; i<=v; i++){
        fscanf(entrada, "%d %d", &x, &y);
        vet[x] += 1;
        vet[y] += 1;
    }

    printf("Teste %d\n", ct);

    int maior=0, u;
    for(i=1; i<=a; i++){
        if(vet[i] > maior){
            maior = vet[i];
            u=i;
        }
    }

    maiores[u]=1;

    for(i=1; i<=a; i++){
        if(vet[i] == maior)
            maiores[i] = 1;
    }

    for(i=1; i<=a; i++){
        if(maiores[i] == 1)
            printf("%d ", i);
        if(i==a)
            printf("\n\n");
    }

    ct++;
}

return 0;
}
