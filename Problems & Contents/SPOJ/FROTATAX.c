#include <stdio.h>

int main(){

    FILE *entrada = fopen("entrada.txt", "r");
    float pa, pg, ra, rg;
    fscanf(entrada, "%f %f %f %f", &pa, &pg, &ra, &rg);
    if(pa/ra < pg/rg)
        printf("A");
    else if(pa/ra > pg/rg)
        printf("G");
    else if(pa/ra == pg/rg)
            printf("G");

    return 0;
}
