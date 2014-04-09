/*
Ciência da Computação - UNIPAMPA.
Matemática Discreta 2012/2 - Teoria de Grafos.
Problema 810. Rede ótica.
Bruno Schubert, Marcos Treviso, Matheus Serpa e Paulo Almeida.
*/

#include <stdio.h>
#define VMAX 101
#define INF 999999

int Qvazio(int *Q, int n)
{
    int v;
    for(v = 1; v <= n; v++)
        if(Q[v]) /* Se contem um vertice em Q */
            return 0; /* Retorna falso pois o grafo não é vazio */
    return 1;/* Se não encontrar nenhum vertice em Q, Retorna verdadeiro */
}

int extract_min(int *Q, int *dist, int n)
{
    int v, menor = 0;
    for(v = 1; v <= n; v++)
        if(Q[v])
        {
            menor = v;
            break;
        }
    for(v = menor; v <= n; v++)
        if(Q[v] && dist[v] < dist[menor])
            menor = v;
    return menor;
}

void prim(int w[VMAX][VMAX], int n, int *dist, int *p, int *Q, int s)
{
    int u, v;
    for(v = 1; v <= n; v++) /* Percorre todos vértices */
    {
        dist[v] = INF;/* Distancia[v] <- Infinito */
        p[v] = 0;/* Predecessor[v] <- Nulo */
        Q[v] = 1;/* Q <- V[G] */
    }
    dist[s] = 0; /* Distancia[inicio] <- 0 */

    while(!Qvazio(Q, n))
    {
        u = extract_min(Q, dist, n);
        Q[u] = 0;/* Q <- Q - {u} */
        for(v = 1; v <= n; v++)  /* Percorre todos vértices */
        {
            if(w[u][v] > 0)  /* Se vértice {v} é adj a {u} */
            {
                if(dist[v] > w[u][v] && Q[v])
                {
                    dist[v] = w[u][v];
                    p[v] = u; /* Predecessor[v] = {u} */
                    //Q[v] = 1; /* Q <- Q + {v} */
                }
            }
        }
    }
}

int main()
{
    int n,m,x,y,z,total=1;
    int grafo[VMAX][VMAX];
    int dist[VMAX];
    int p[VMAX];
    int determinados[VMAX];

    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n==0)
            return 0;

        for(x = 0; x <= n; x++)
            for(y = 0; y <= n; y++)
                grafo[x][y] = 0;

        while(m--)
        {
            scanf("%d %d %d", &x, &y, &z);
            grafo[x][y] = z;
            grafo[y][x] = z;
        }

        prim(grafo, n, dist, p, determinados, 1);

        printf("Teste %i\n", total++);
        for(x = 1; x <= n; x++)
            if(p[x] != 0)
            {
                if(p[x] < x)
                    printf("%d %d\n", p[x], x);
                else
                    printf("%d %d\n", x, p[x]);
            }
        printf("\n");
    }
}

