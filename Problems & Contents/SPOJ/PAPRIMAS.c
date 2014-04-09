#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int num){

    int i, teste=0;
    for(i=2; i<num; i++)
        if(num % i == 0)
          teste = 1;

    if (!teste)
        return 1;
    else
        return 0;
}

int main(){

FILE *entrada = fopen("entrada.txt", "r");
char txt;
int soma=0, c;

while(fscanf(entrada, "%c", &txt) != EOF){

    if(txt!='\n'){
        c=txt;
        if(c>64 && c<91)//A-Z
            c-=38;
        if(c>96 && c<122)//a-z
            c-=96;
        soma+=c;
    }

    if(txt == '\n'){
        if(soma!=0){
            if(ehPrimo(soma))
                printf("It is a prime word.\n");
            else
                printf("It is not a prime word.\n");
        }
        soma=0;
    }

}

return 0;
}
