#include <stdio.h>
#include <stdlib.h>

int calcula_tempo(int h1, int m1, int h2, int m2){

    if(h1==0)
    h1=24;
    if(h2==0)
    h2=24;

    h1=h1*60;
    h2=h2*60;

    if((h1+m1) > (h2+m2))
        return (24*60)+((h2+m2)-(h1+m1));

    return (h2+m2)-(h1+m1);
}


int main(){
int h1,m1,h2,m2,result;
FILE *entrada = fopen("entrada.txt", "r");

    while(1){

        fscanf(entrada, "%d %d %d %d", &h1, &m1, &h2, &m2);
        if(h1==0 && m1==0 && h2==0 && m2==0)
            break;
        result = calcula_tempo(h1,m1,h2,m2);
        printf("%d\n", result);

    }

return 0;
}
