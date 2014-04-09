#include <stdio.h>

int main(){

int t,n,p;
FILE *entrada = fopen("entrada.txt", "r");
while(1){
    fscanf(entrada, "%d %d", &t, &n);
    if(t==0)
        break;

    int soma=0;
    int mult=3*n;
    char time[11];

    while(t--){
        fscanf(entrada, "%s %d", time, &p);
        soma+=p;
    }

    soma = mult-soma;
    printf("%d\n", soma);

}

return 0;
}
