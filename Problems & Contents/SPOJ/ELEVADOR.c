#include <stdio.h>
#include <stdlib.h>

int main(){

FILE *entrada = fopen("entrada.txt", "r");
int n, c, s, e, sit=0, som=0;
fscanf(entrada, "%d %d", &n, &c);

    while(n--){
        fscanf(entrada, "%d %d", &s, &e);
        som+=e;
        som-=s;
        //som=som+e-s
        if(som > c)
            sit=1;
    }

    if(sit)
        printf("S");
    else
        printf("N");

return 0;
}
