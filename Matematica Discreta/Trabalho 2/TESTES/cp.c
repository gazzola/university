#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAXV 501

int mat[MAXV][MAXV];

int ehVazio(int n, int *queue){
    if(!queue[n])
        return 1;
    return 0;
}

int extraiMin(int n, int *queue, int *chave){

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

int Prim(int n, int r, int *queue, int *chave, int *pi){

    chave[r]=0;

    while(!ehVazio(n, queue)){
        int u=extraiMin(n, queue, chave);
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

    int x, som=0;
    for(x=1; x<=n; x++){
        som+= mat[x][pi[x]];
    }

    return som;

}

void setMatriz(int n, int *queue, int *chave, int *pi){
    int i,j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            mat[i][j] = 0;
        }
        chave[i] = 999999;
        pi[i] = 0;
        queue[i]=1;
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
    int chave[MAXV], pi[MAXV], queue[MAXV];

    FILE *entrada = fopen("entrada.txt", "r");

    while(!feof(entrada)){

        fscanf(entrada, "%d %d", &n, &m);
        setMatriz(n, queue, chave, pi);

        while(m--){
            fscanf(entrada, "%d %d %d", &u, &v, &c);
            mat[u][v] = c;
            mat[v][u] = c;
        }

        int pr = Prim(n, 1, queue, chave, pi);
        int y;
        for(y=1; y<=n; y++){
            if(chave[y] == 999999){
                setMatriz(n, queue, chave, pi);
                Prim(n, y, queue, chave, pi);
            }
        }

        printf("Instancia %d\n%d\n\n", count, pr);
        count++;

    }

    tempo = crono() - tempo;
    printf("\n\nTEMPO DE EXECUCAO: %.25lf", tempo);

    return 0;
}
