/*
    Ciência da Computação - UNIPAMPA.
    Matemática Discreta 2012/2 - Teoria de Grafos.
    Problema 819. Pedágio.
    Bruno Schubert, Marcos Treviso, Matheus Serpa e Paulo Almeida.
*/

#include <stdio.h>
#define VMAX 51
#define INF 999999

int Qvazio(int *Q, int n){
    int v;
    for(v = 1; v <= n; v++)
        if(Q[v]) /* Se contem um vertice em Q */
            return 0; /* Retorna falso pois o grafo não é vazio */
    return 1;/* Se não encontrar nenhum vertice em Q, Retorna verdadeiro */
}

int extract_min(int *Q, int *dist, int n){
    int v, menor = 0;
    for(v = 1; v <= n; v++)
        if(Q[v]){
            menor = v;
            break;
        }
    for(v = menor; v <= n; v++)
        if(Q[v] && dist[v] < dist[menor])
            menor = v;
    return menor;
}

void dijkstra(int w[VMAX][VMAX], int n, int *dist, int *p, int *Q, int s){
    int u, v;
    for(v = 1; v <= n; v++){/* Percorre todos vértices */
        dist[v] = INF;/* Distancia[v] <- Infinito */
        p[v] = 0;/* Predecessor[v] <- Nulo */
        Q[v] = 1;/* Q <- V[G] */
    }
    dist[s] = 0; /* Distancia[inicio] <- 0 */

    while(!Qvazio(Q, n)){
        u = extract_min(Q, dist, n);
        Q[u] = 0;/* Q <- Q - {u} */
        for(v = 1; v <= n; v++){ /* Percorre todos vértices */
            if(w[u][v] > 0){ /* Se vértice {v} é adj a {u} */
                if(dist[v] > dist[u] + w[u][v]){
                    dist[v] = dist[u] + w[u][v];
                    p[v] = u; /* Predecessor[v] = {u} */
                    Q[v] = 1; /* Q <- Q + {v} */
                }
            }
        }
    }
}

int main(){
    int c, e, l, p, x, y, n = 1;
    int w[VMAX][VMAX];
    int dist[VMAX];
    int pred[VMAX];
    int Q[VMAX];

    while(1){
        scanf("%d %d %d %d", &c, &e, &l, &p);
        if(c == 0 && e == 0 && l == 0 && p == 0)
            return 0;

        for(x = 0; x <= c; x++)
            for(y = 0; y <= c; y++)
                w[x][y] = 0;

        while(e--){
            scanf("%d %d", &x, &y);
            w[x][y] = 1;
            w[y][x] = 1;
        }

        dijkstra(w, c, dist, pred, Q, l);

        printf("Teste %d\n", n++);
        for(x = 1;x <= c; x++)
            if(dist[x] <= p && dist[x] > 0)
                printf("%d ", x);
        printf("\n\n");
    }
}
