#include <stdio.h>

int multiplicacao(int x, int y){

    if(y == 0){
        return 0;
    }
    else{
        if(x<0 && y<0){
            y=y*-1;
            return (x+multiplicacao(x,y-1))*-1;
        }else{
            return x+multiplicacao(x,y-1);
        }

    }

}

int main(){

    int x, y, result;

    printf("Digite dois numeros para multiplacao entre eles: ");
    scanf("%d %d", &x, &y);

    result = eq(x, y);
    printf("\nResultado:%d", result);

    return 0;
}
