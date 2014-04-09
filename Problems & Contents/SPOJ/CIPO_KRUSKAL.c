/*
 * Alexandre Martins
 * SPOJBR 1746 - Sistema Cipoviario
 */
#include <stdio.h>
#define MAXV 1001
#define MAXE 2000001
#define INFINITY 11000

typedef short vertex;
typedef struct { vertex v, w; short cst; } edge;

/* grafo (como so' uso um, dispensei a struct) */
int vertices;
short adj[MAXV][MAXV];

/* arestas separadas em classes (custos) */
edge ed[3][MAXE], e[MAXE];
int ed_n[3], e_n; /* arestas ordenadas */

/* estrutura do Union-Find */
vertex set[MAXV];
int sz[MAXV];

/* utilidades */
int map(int cst) { return ((cst==1235) ? 0 : ((cst==8977) ? 1 : 2)); }
edge edge_new(vertex v, vertex w, short cst) { edge e; e.v=v; e.w=w; e.cst=cst; return e; }


/*
 * graph_init()
 * inicializa o grafo com n vertices
 */
void graph_init(int n)
{
    vertex v, w;

    ed_n[0] = ed_n[1] = ed_n[2] = 0;
    for(v=0; v<n; v++)
        for(w=0; w<n; w++)
            adj[v][w] = INFINITY;
    vertices = n;
}


/*
 * graph_newedge()
 * insere aresta v-w com custo c no grafo
 * (apenas se for conveniente)
 */
void graph_newedge(vertex v, vertex w, short c)
{
    if(c < adj[v][w]) {
        adj[v][w] = adj[w][v] = c;
        ed[ map(c) ][ ed_n[map(c)]++ ] = edge_new(v, w, c);
    }
}


/*
 * graph_kruskal()
 * algoritmo de Kruskal
 */
int graph_kruskal()
{
    int i, k, cst = 0;
    vertex u, v0, w0;

    /* inicializa union-find */
    for(u=0; u<vertices; u++) {
        set[u] = u;
        sz[u] = 1;
    }

    /* para cada aresta e[i]... (vetor 'e' previamente ordenado) */
    for(i=k=0; i<e_n && k<vertices-1; i++) {

        /* encontra representantes dos conjuntos dos vertices v e w */
        for(v0=e[i].v; v0!=set[v0]; v0=set[v0]);
        for(w0=e[i].w; w0!=set[w0]; w0=set[w0]);

        /* v e w estao em conjuntos diferentes? */
        if(v0 != w0) {

            /* uniao */
            if(sz[v0] < sz[w0]) {
                set[v0] = w0;
                sz[w0] += sz[v0];
            }
            else {
                set[w0] = v0;
                sz[v0] += sz[w0];
            }

            /* montando a MST... */
            k++;
            cst += e[i].cst;

        }

    }

    return cst;
}


/*
 * main()
 * funcao principal
 */
int main()
{
    int n, m, i, j, t=0;
    vertex v, w;
    short c;

    while(scanf("%d %d", &n, &m) == 2) {
        /* input */
        graph_init(n);
        while(m--) {
            scanf("%hd %hd %hd", &v, &w, &c);
            graph_newedge(v-1, w-1, c);
        }

        /* ordena arestas em tempo linear */
        e_n = 0;
        for(i=0; i<3; i++)
            for(j=0; j<ed_n[i]; j++)
                e[e_n++] = ed[i][j];

        /* kruskal */
        printf("Instancia %d\n%d\n\n", ++t, graph_kruskal());
    }

    return 0;
}
