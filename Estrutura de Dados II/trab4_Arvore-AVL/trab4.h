typedef struct _no{
	int dado;
    //int fb; //foi usado a funcao altura() para descobrir o fator de balanceamento de um no
	struct _no *esq;
	struct _no *dir;
}no;

typedef no *raiz;


void cria_arvore(raiz *r);
no *aloca_no(int x);
void rotaciona_direita(raiz *r); //se he > hd: se hnoe > hnod (LEGENDA: height_esquerda > height_esquerda: height_no_a_esquerda > height_no_a_direita)
void rotaciona_esquerda(raiz *r); //se he < hd: se hnoe < hnod
void rotaciona_dupla_direita(raiz *r); //se he > hd: se hnoe < hnod
void rotaciona_dupla_esquerda(raiz *r); //se he < hd: se hnoe > hnod
void rebalancear(raiz *r);
void insere(raiz *r, int x, raiz *t);
void remove_no(raiz *r, int x, raiz *t);
void em_nivel(raiz *r);
void imprime_dado_nivel(raiz *r, int nivel);
int altura(raiz *r);
void destroi_arvore(raiz *r);
int modulo(int x);