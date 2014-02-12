#include <stdio.h>

int equacaoX(x){
    int res;

     if(x==1){
        return 1;
    }
    else{
        while(x>1){
            res = 10*(res)+2;
            x = x-1;

        }

        return res;
    }

}

int main(){

    int x, result;

    printf("Digite um numero qualquer: ");
    scanf("%d", &x);

    result = equacaoX(x);

    printf("\nResultado:%d", result);

    return 0;
}
