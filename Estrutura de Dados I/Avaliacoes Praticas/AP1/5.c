#include <stdio.h>

int main(){

	int vet[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, qtdpar = 0;

    for(i=0; i<9; i++){
        if(vet[i] % 2 == 0)
            qtdpar += 1;

    printf("Quantidade de pares: %d", qtdpar);

    return 0;
}
