#include <stdio.h>

int main(){

	int i, soma=0, mult=1;

    for(i=1; i<=10; i++){
        soma = soma + i;
        mult = mult * i;
    }

    printf("Soma = %d \nProduto = %d", soma, mult);


    return 0;
}
