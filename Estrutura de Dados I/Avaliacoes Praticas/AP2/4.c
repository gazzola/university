#include <stdio.h>


int fibonnaci(int n){

    if(n > 1){
        return fibonnaci(n-1)+fibonnaci(n-2);
    }
    else if(n == 1 || n == 0){
        return 1;
    }

}

int main(){

    int n, result;

    printf("Digite um numero para elemento da serie fibonnaci:");
    scanf("%d", &n);

    result = fibonnaci(n);
    printf("\nResultado:%d", result);

    return 0;

}
