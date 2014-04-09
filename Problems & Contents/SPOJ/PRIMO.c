#include <stdio.h>

int main(){

int num;
FILE *entrada = fopen("entrada.txt", "r");
fscanf(entrada, "%d", &num);


int i, contar, teste;
teste = contar = 0;

for(i=2; i<num; i++, contar++)
    if (num % i == 0)
      teste = 1;

if (!teste)
    printf("sim");
else
    printf("nao");

return 0;
}
