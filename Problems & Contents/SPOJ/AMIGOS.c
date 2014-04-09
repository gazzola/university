#include <stdio.h>

int mod(int x){
    if(x<0)
        x=x*-1;
    return x;
}

void ladoFronteira(int a, int b, int m, int n, int k, int *vet){

    int i,j;
    for(i=0; i<k; i++){
        for(j=0; j<k; j++){
            if(mod(j-i+b)==1){//front/ds
                vet[i]=1;
            }
        }
    }

}


int main(){

int n, count=1, a, b, k, kk, m, nx;
FILE *entrada = fopen("entrada.txt", "r");
fscanf(entrada, "%d", &n);

while(n--){


    fscanf(entrada, "%d %d %d", &a, &b, &k);    //y=ax+b -> fronteira
    int *vet = (int*) malloc (k*sizeof(int));
    kk=k;
    printf("Caso %d\n", count);
    int xss=0;
    while(kk--){

        fscanf(entrada, "%d %d", &m, &nx);
        ladoFronteira(a,b,m,nx,k,vet);
        if(vet[xss])
            printf("mesmo lado\n");
        else
            printf("lado oposto\n");
        xss++;
    }

count++;

}

return 0;
}
