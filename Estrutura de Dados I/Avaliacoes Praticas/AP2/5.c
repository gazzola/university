#include <stdio.h>

int somatorio(int n, int x, int soma){

    if(x <= n){
        soma = soma+(3*(x*x)) + (3*x) + 2;
        return somatorio(n, x+1, soma);
    }
    else{
        return soma;
    }


}



int main(){
    
    int x=1, n, result;

    do{
        printf("Digite um numero maximo de vezes para realizar o somatorio: ");
        scanf("%d", &n);

        if(n<0){
            printf("Apenas inteiros positivos...\n");
        }

    }while(n < 0);

    result = somatorio(n, x, 0);

    printf("\nResultado:%d", result);

    return 0;
}
