#include <stdio.h>

int main(){

    FILE *entrada = fopen("entrada.txt", "r");
    int n,j,z,dif,i,inst=1;
    fscanf(entrada, "%d", &n);
    while(n){
        dif=0;
        printf("Teste %d\n", inst++);

        for(i=0; i<n; i++){
            fscanf(entrada, "%d %d", &j, &z);
            dif+= j-z;
            printf("%d\n", dif);
        }

        printf("\n");
        fscanf(entrada, "%d", &n);
    }

    return 0;
}
