#include <stdio.h>

int multiplicacao(int x, int y){

    int i, res = 0, men, mai;

    if(y == 0)
        return 0;
    else if(x > y){
        men = y;
        mai = x;
    }
    else{
        men = x;
        mai = y;
    }

    if(men < 0 )
        men = men*(-1);

    for(i=men; i>0; i--)
        res = mai+res;

    if(x<0 || y<0)
        res = res*(-1);

    return res;

}

int main(){

    int x, y, result;

    printf("Digite dois numeros para multiplacao entre eles: ");
    scanf("%d %d", &x, &y);

    result = multiplicacao(x, y);

    printf("\nResultado:%d", result);

    return 0;
}
