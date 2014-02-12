#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memset
#define MAXV 1000


int n, m, u, v, c;
int MAdj[MAXV][MAXV];
int dis[MAXV];

void Prim (int Vi, int V){

        char vis[MAXV];
        memset (vis, 0, sizeof (vis));

        memset (dis, 0x7f, sizeof (dis));
        dis[Vi] = 0;

        while (1){
            int i, n = -1;

            for (i = 0; i < V; i++)
                if (n < 0 || dis[i] < dis[n])
                    n = i;

            if (n < 0)
                break;

            vis[n] = 1;

            for (i = 0; i < V; i++)
                if (vis[n] && MAdj[n][i] < dis[i])
                        dis[i] = MAdj[n][i];
        }
}


int main(){

FILE *entrada;
entrada = fopen("entrada.txt", "r");

while(!feof(entrada)){

    fscanf(entrada, "%d %d", &n, &m);
    printf("\nn:%d m:%d\n", n, m);

    if(n<1 || n>1000 || m<1 || m>2000000)
        break;

    //

    int m2=m;

    while(m2--){
        fscanf(entrada, "%d %d %d", &u, &v, &c);
        printf("u:%d v:%d c:%d\n", u, v, c);
        MAdj[u-1][v-1] = c;
    }

    int b,c;
    for(b=0; b<n; b++){
        for(c=0; c<n; c++){
            printf("%.5d | ", MAdj[b][c]);
        }
        printf("\n");
    }

    Prim(0, n-1);

    printf("\n\nDIS:\n\n");
    int y;
    for(y=0; y<n; y++){
        printf("dis[%d] = %d\n", y, dis[y]);
    }

}


fclose(entrada);
return 0;
}
