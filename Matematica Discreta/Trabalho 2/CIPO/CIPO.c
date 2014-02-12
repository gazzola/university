/*
    Ciência da Computação - UNIPAMPA.
    Matemática Discreta 2012/2 - Teoria de Grafos.
    Problema 1746. Sistema Cipoviário.
    Bruno Schubert, Marcos Treviso, Matheus Serpa e Paulo Almeida.
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>
#define VMAX 1001/*Gera erro no windows pois a matriz fiz 1001 x 1001, funciona normalmente no linux */
//#define VMAX 501

void prim(int w[VMAX][VMAX], int n, int *dist, int *p, int *Q, int s)
{
    int u, v;
    for(v = 0; v <= n; v++) /* Percorre todos vértices */
    {
        dist[v] = INT_MAX;/* Distancia[v] <- Infinito */
        p[v] = 0;/* Predecessor[v] <- Nulo */
        Q[v] = 1;/* Q <- V[G] */
    }
    dist[s] = 0; /* Distancia[inicio] <- 0 */

    while(1)
    {
        int menor = 0;
        for(u = 1; u <= n; u++)
            if(Q[u] && dist[u] < dist[menor])
                menor = u;
        u = menor;
        if(u == 0)
            return;
        Q[u] = 0;/* Q <- Q - {u} */
        for(v = 1; v <= n; v++)  /* Percorre todos vértices */
        {
            if(w[u][v] > 0)  /* Se vértice {v} é adj a {u} */
            {
                if(dist[v] > w[u][v] && Q[v])
                {
                    dist[v] = w[u][v];
                    p[v] = u; /* Predecessor[v] = {u} */
                }
            }
        }
    }
}

int main()
{
    int n,m,u,v,c,k=1,custo;
    int grafo[VMAX][VMAX];
    int dist[VMAX];
    int p[VMAX];
    int determinados[VMAX];

    while(scanf("%d", &n) != EOF)
    {
        custo = 0;
        scanf("%d", &m);
        memset(grafo, 0, sizeof(grafo));/* inicializa a matriz com 0 */

        while(m--)
        {
            scanf("%d %d %d", &u, &v, &c);
            grafo[u][v] = c;
            grafo[v][u] = c;
        }

        prim(grafo, n, dist, p, determinados, 1);
        custo += grafo[1][p[1]];
        for(v = 2; v <= n; v++)
        {
            if(dist[v] == INT_MAX)
            {
                prim(grafo, n, dist, p, determinados, v);
            }
            custo += grafo[v][p[v]];
        }

        printf("Instancia %i\n%d\n\n", k++, custo);
    }
    return 0;
}
