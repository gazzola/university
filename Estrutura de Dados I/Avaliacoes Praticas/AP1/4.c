#include <stdio.h>

int main(){

	int i, val;

    do{
        printf("Informe um numero inteiro, ou informe zero para sair: ");
        scanf("%d", &val);

        printf("O quadrado de %d eh: %d \n\n", val, (val*val));
    }
    while(val != 0);


    return 0;
}