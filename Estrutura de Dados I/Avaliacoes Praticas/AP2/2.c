#include <stdio.h>

int equacao2(int x){

    if(x==0){
        return 2;
    }
    else if(x > 0){
        return 2 * equacao2(x-1) - 2;

    }

}

int main(){

    int x, result;

    printf("Digite um numero qualquer: ");
    scanf("%d", &x);

    result = equacao2(x);
    printf("\nResultado:%d", result);

    return 0;
}
