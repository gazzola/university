#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int len(int value){
    int l=0;
    while(value){
        l++;
        value/=10;
    }
    return l;
}


int ult(int ft){

    int tam = len(ft);
    int i, ult=1;

    for (i=0; i<tam; i++) {
        int y = pow(10, i);
        int z = ft/y;
        int x2 = ft / (y * 10);
        if(z - x2*10 != 0){
            ult = z - x2*10;
            break;
        }
    }

    return ult;
}

unsigned long int fat(unsigned long int n){

    unsigned long int ft=1;
    while(n>0){
        ft=ft*n;
        n--;!
    }

    return ft;
}

int main(){

FILE *entrada = fopen("entrada.txt", "r");
int n, count=1;

while(!feof(entrada)){
fscanf(entrada, "%d", &n);
unsigned long int ft=fat(n);
printf("%lu\n", ft);
ft=ult(ft);
printf("Instancia %d\n%lu\n\n", count, ft);
count++;
}


return 0;
}
