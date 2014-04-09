#include <stdio.h>

int main(){

int x1, y1, x2, y2, n, x, y, som=0, count=1;
FILE *entrada = fopen("entrada.txt", "r");

    while(1){
    fscanf(entrada, "%d %d %d %d %d", &x1, &y1, &x2, &y2, &n);

    if(x1==0 & y1==0 && x2==0 && y2==0)
        break;

        while(n--){
            fscanf(entrada, "%d %d", &x, &y);
            if(x >= x1 && x<= x2 && y<=y1 && y>=y2)
                som++;
        }

        printf("Teste %d\n%d\n\n", count, som);
        som=0;
        count++;

    }

return 0;
}
