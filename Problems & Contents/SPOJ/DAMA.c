#include <stdio.h>

int mod(int x){
    if(x<0)
        x=x*-1;
    return x;
}

int main(){

int x1, y1, x2, y2;
FILE *entrada = fopen("entrada.txt", "r");

while(1){
    fscanf(entrada, "%d %d %d %d", &x1, &y1, &x2, &y2);
    if(x1==0 && y1==0 && x2==0 && y2==0)
        break;

    int tent=2;

    if((x1 == x2 && y1 != y2) || (x1!=x2 && y1==y2)){
        tent=1;
    }
    else if(x1==x2 && y1==y2){
        tent=0;
    }
    else if((x1-y1) == (x2-y2)){//diagonal principal;
        tent=1;
    }
    else if(mod(x2-x1) == mod(y2-y1)){//diagonal secundaria
        tent=1;
    }

    printf("%d\n", tent);

}


return 0;
}
