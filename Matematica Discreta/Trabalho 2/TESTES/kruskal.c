#include <stdio.h>
#include <stdlib.h>
#define MAXV 1001

int mat[MAXV][MAXV];
int mat_ord[MAXV][MAXV];
int mat_A[MAXV][MAXV];


void setMatriz(int n){
    int i,j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            mat[i][j] = 0;
        }
    }
}

void OrdenaMatriz(int n, int m){

    int x, i, ult=0, men=999999;

        for(i=1; i<=n; i++){
            for(x=1; x<=m; x++){
                if(mat[i][x]<=men && (i+x) != ult && mat[i][x]!=0){
                    men = mat[i][x];
                    mat_ord[i][x] = men;
                    ult = i+x;
                }

        }
    }
    printf("\n\n");
    int s, e;
    for(s=1; s<=n; s++){
        for(e=1; e<=m; e++){
            printf("%d ", mat_ord[s][e]);
        }
         printf("\n");
    }
    printf("\n\n");
}


int Kruskal(int n, int m){

    int *vet = (int*) malloc (n*sizeof(int));

    int i, j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            mat_A[i][j] = 0;
            mat_ord[i][j] = 0;
        }
        vet[i]=0;
    }

    OrdenaMatriz(n,m);

    return 1;

}



int main(){

    int n, m, u, v, c, count=1;
    FILE *entrada = fopen("entrada.txt", "r");

    while(!feof(entrada)){

        fscanf(entrada, "%d %d", &n, &m);

        if(n<1 || n>1000 || m<1 || m>2000000)
            break;

        setMatriz(n);

        int mm=m;
        while(mm--){
            fscanf(entrada, "%d %d %d", &u, &v, &c);
            mat[u][v] = c;
            //mat[v][u] = c;
        }


        int pr = Kruskal(n, m);
        printf("Instancia %d\n%d\n\n", count, pr);
        count++;

    }

    return 0;
}
