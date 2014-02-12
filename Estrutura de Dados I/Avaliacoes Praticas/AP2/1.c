#include <stdio.h>

int equacao(int x){

    if(x > 1)
        return (5 * equacao(x-1)) + 3;
    else if(x == 1)
        return 1;

}

int main(){

    int x, result;

    printf("Digite um numero que seja inteiro positivo: ");
    scanf("%d", &x);

    result = equacao(x);
    printf("\nResultado:%d", result);


    return 0;
}
