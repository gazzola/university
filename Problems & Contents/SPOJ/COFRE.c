#include <stdio.h>


int main(){

int n,j,z, count=1, result=0;
FILE *entrada = fopen("entrada.txt", "r");

while(1){


    fscanf(entrada, "%d", &n);
    if(n==0)
        break;

    printf("Teste %d\n", count);
    while(n--){
        fscanf(entrada, "%d %d", &j, &z);
        result+=j-z;
        printf("%d\n", result);
    }
    printf("\n");

    count++;

}

return 0;
}
