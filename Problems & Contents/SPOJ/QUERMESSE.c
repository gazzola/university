#include <stdio.h>

int main(){

int n, x, count=1, prem=1, esc;
FILE *entrada = fopen("entrada.txt", "r");

while(1){
fscanf(entrada, "%d", &n);

if(n==0)
break;

    while(n--){
        fscanf(entrada, "%d", &x);
        if(x==prem)
            esc=x;
    prem++;
    }

prem=1;
printf("Teste %d\n%d\n\n", count, esc);
count++;
}

return 0;
}
