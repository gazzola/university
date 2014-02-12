typedef struct _nodo{
    int info, i, j;
    struct _nodo *prox;
    //struct _nodo *abaix;  //circular
}Nodo;

typedef Nodo *Lista;

void criaLista(Lista *l);   //funcao para criar a lista
void destroiLista(Lista *l);    //funcao para destruir a lista
void insereOrdenado(Lista *l, int x, int posi, int posj, int num_colunas);  //funcao para inserir ordenado
void imprimeLista(Lista *l, int num_linhas, int num_colunas);   //funcao para imprimir a lista
void entradaImagem();   // funcao que le a entrada e executa as funcoes de saida e manipulacao
void saidaImagem(Lista *l, int num_max, int num_linhas, int num_colunas);   // funcao de saida
void insereBorda(Lista *l, int num_linhas, int num_colunas);    //funcao de manipulacao para inserir borda de 3px na cor 255
void inverteImagem(Lista *l, int num_max, int num_linhas, int num_colunas); //funcao de manipulacao para inverter as cores da imagem
