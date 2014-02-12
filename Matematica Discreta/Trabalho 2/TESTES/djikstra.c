#include <stdio.h>
#define VMAX 101
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
    int n, m, i, j, t, s, d;
    int w[VMAX][VMAX];
    int dist[VMAX];
    int p[VMAX];
    int Q[VMAX];

    while(1){
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0)
            return 0;

        for(i = 0; i <= n; i++)
            for(j = 0; j <= n; j++)
                w[i][j] = 0;

        while(m--){
            scanf("%d %d %d", &i, &j, &t);
            w[i][j] = t;
        }

        scanf("%d %d", &s, &d);
        dijkstra(w, n, dist, p, Q, s);

        if(dist[d] == INF)
            printf("-1\n");
        else
            printf("%d\n", dist[d]);
    }

}
