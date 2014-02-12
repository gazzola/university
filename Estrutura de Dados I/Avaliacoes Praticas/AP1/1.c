#include <stdio.h>


int main(){

	float valor;

    printf("Digite um valor em Reais: ");
    scanf("%f", &valor);

    valor = valor*(0.44);
    printf("Novo valor em Euros: %f", valor);

    return 0;

}
