//estrutura do no
typedef struct _no{
    int  dado;
    struct _no *esq;
    struct _no *dir;
}no;
 
//no raiz
typedef no *raiz;
 
void cria_arvore(raiz *r); // 1
no *aloca_no(int x); // 2
void insere(raiz *r, int x); // 3
void insere_filho_esq(raiz *r, int pai, int x); // 4
void insere_filho_dir(raiz *r, int pai, int x); // 5
no *localiza(raiz *r, int x); // 6
no *localiza_ordenado(raiz *r, int x); // 7
no *remove_no(raiz *r, int x); // 8
int arvore_vazia(raiz *r); // 9
int nivel(raiz *r, no **x); // 10
no *pai(raiz *r, no **x); // 11
void em_ordem(raiz *r); // 12
void pre_ordem(raiz *r); // 12
void pos_ordem(raiz *r); // 12
void clear(raiz *r); //extra
void em_nivel(raiz *r);
void imprime_dado_nivel(raiz *r, int nivel);
int altura(raiz *r);