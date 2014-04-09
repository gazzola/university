#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define MAXV 501

int mat[MAXV][MAXV], chave[MAXV], pi[MAXV], queue[MAXV];

int ehVazio(int n){
    int i;
    for(i=1; i<=n; i++){
        if(!queue[i]){
            if(i==n)
                return 1;
            }
    }
    return 0;
}


int extraiMin(int n){

    int i;
    int u, men=999999;
    for(i=1; i<=n; i++){
        if(chave[i] <= men && queue[i]){
            men = chave[i];
            u=i;
        }
    }

    queue[u] = 0;
    return u;

}

int Prim(int n, int r){

    int i, som=0;
    for(i=1; i<=n; i++){
        chave[i] = 999999;
        pi[i] = 0;
        queue[i]=1;
    }

    chave[r]=0;

    while(!ehVazio(n)){
        int u=extraiMin(n);
        int v;
        for(v=1; v<=n; v++){
            if(mat[u][v]>0){

                if(queue[v] && mat[u][v] < chave[v]){
                    pi[v] = u;
                    chave[v] = mat[u][v];
                }

            }
        }
    }

    int x;
    for(x=1; x<=n; x++){

            som+= mat[x][pi[x]];

    }

    return som;

}

void setMatriz(int n){
    int i,j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            mat[i][j] = 0;
        }
    }
}

double crono(){
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec / 1e6;
}

int main(){

    double tempo = crono();
    int n, m, u, v, c, count=1;
    FILE *entrada = fopen("entrada.txt", "r");

    while(!feof(entrada)){

        fscanf(entrada, "%d %d", &n, &m);
        setMatriz(n);

        while(m--){
            fscanf(entrada, "%d %d %d", &u, &v, &c);
            mat[u][v] = c;
            mat[v][u] = c;
        }

        int pr = Prim(n, 1);
        int y;
        for(y=1; y<=n; y++){
            if(chave[y] == 999999){
                setMatriz(n);
                Prim(n, y);
            }
        }

        printf("Instancia %d\n%d\n\n", count, pr);
        count++;

    }

    tempo = crono() - tempo;
    printf("\n\nTEMPO DE EXECUCAO: %.25lf", tempo);

    return 0;
}
