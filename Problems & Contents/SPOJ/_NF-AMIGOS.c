#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void verificaMatriz(int mat[11][6], int a, int b, int m, int n){

    int i,j;
    for(i=11; i>1; i--){
        for(j=6; j>1; j--){
            printf("%d %d\n", m, n);
            if((m<((a*i)+b) && n<((a*i)+b)) || (m>((a*i)+b) && n>((a*i)+b))){
                printf("Mesmo lado da fronteira\n");
                return;
            }
            else if((m<((a*i)+b) && n>((a*i)+b)) || (m>((a*i)+b) && n<((a*i)+b))){
                printf("Lados opostos da fronteira\n");
                return;
            }

        }
    }

}

void preencheMatriz(int mat[11][6]){

//preencher matriz em espiral.

}


int main(){

int n, a, b, k, mn, count=1, ult, ct=1;
FILE *entrada = fopen("entrada.txt", "r");
fscanf(entrada, "%d", &n);
int mat[11][6];
memset(mat, 0, sizeof(mat));

while(n--){
    printf("Caso %d\n", count);
    fscanf(entrada, "%d %d %d", &a, &b, &k);
    int kk=k*2;
    while(kk--){
        fscanf(entrada, "%d", &mn);
        int i, j;
        for(i=1; i<11; i++){
            for(j=1; j<6; j++){
                mat[i][j] = mn;
            }
        }

        if(ct%2==0){
            verificaMatriz(mat, a, b, ct-1, ct);
        }
        //verificaMatriz(mat, a, b, ult, mn);

        ult=mn;
        ct++;
    }



count++;
}


return 0;
}
