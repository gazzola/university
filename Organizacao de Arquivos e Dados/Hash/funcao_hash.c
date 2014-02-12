// Organizacao de Arquivos e Dados - 2013 - CC03
// Marcos Vinicius Treviso - 121150107 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
   
    srand(time(NULL));
    int mod10c[10], mod8c[8], mod7c[7];
    int i;

    for(i=0; i<10; i++){
        mod10c[i] = -1;
        if(i<8)
            mod8c[i] = -1;
        if(i<7)
            mod7c[i] = -1;
    }

    for(i=0; i<1000; i++){
	    int r = rand()%1000;
	    mod10c[r % 10] += 1;
	    mod8c[r % 8] += 1;
	    mod7c[r % 7] += 1;
    }

    printf("NUM DE COLISOES POR INDICE\n\n");

    printf("MOD7:\n");
    for(i=0; i<7; i++)
        mod7c[i] < 1 ? printf("%d ", 0) : printf("%d ", mod7c[i]);

    printf("\n\nMOD8:\n");
    for(i=0; i<8; i++)
        mod8c[i] < 1 ? printf("%d ", 0) : printf("%d ", mod8c[i]);

    printf("\n\nMOD10:\n");
    for(i=0; i<10; i++)
        mod10c[i] < 1 ? printf("%d ", 0) : printf("%d ", mod10c[i]);

    printf("\n");

    return 0;
}