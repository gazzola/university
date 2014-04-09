#include <stdio.h>
#include <stdlib.h>
#define MAXV 1001

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

int Prim(int n, int r, int *chave, int *pi, int *queue){

    int i, som=0;
    for(i=1; i<=n; i++){
        chave[i] = 999999;
        pi[i] = 0;
        queue[i]=1;
    }

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

    int x;
    for(x=1; x<=n; x++){
        if(pi[x] > 0){
            som+= mat[x][pi[x]];
        }
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

int main(){

    int n, m, u, v, c, count=1;
    int mat[MAXV][MAXV], chave[MAXV], pi[MAXV], queue[MAXV];

    while(scanf("%d", &n) != EOF){

        scanf("%d", &m);
        setMatriz(n);

        while(m--){
            scanf("%d %d %d", &u, &v, &c);
            mat[u][v] = c;
            mat[v][u] = c;
        }

        int pr = Prim(n, 1, chave, pi, queue);
        int y;
        for(y=1; y<=n; y++){
            if(chave[y] == 999999){
                memset(mat, 0, sizeof(mat));
                Prim(n, y, chave, pi, queue);
            }
        }

        printf("Instancia %d\n%d\n\n", count, pr);
        count++;

    }

    return 0;
}
