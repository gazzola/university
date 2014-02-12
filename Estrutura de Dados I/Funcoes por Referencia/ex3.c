#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nCaracteres(char *frase, int *nA, int *nE){

    int i;
    int tamstr;

    tamstr = strlen(frase);

    for(i=0; i<tamstr; i++){

        if(frase[i] == 'a'){
            *nA = *nA+1;
        }
        else if(frase[i] == 'e'){
            *nE = *nE+1;
        }

    }

    printf("Palavra escrita: %s \nNumero de 'a':%d \nNumero de 'e':%d\n", frase, *nA, *nE);
}

int main(){

    int na=0, ne=0;
    char mystr[100];

    printf("Digite uma frase qualquer: ");
    scanf("%s", mystr);

    nCaracteres(mystr, &na, &ne);

    return 0;
}
