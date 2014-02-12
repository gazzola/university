typedef struct _no{ //estrutura do no
	int  dado;
	struct _no *esq;
	struct _no *dir;
}no;

typedef no *raiz; //raiz

void inserir(raiz *r, int x); //inserir nos na arvore
void em_ordem(raiz *r); //exibir em ordem -infixa
void pre_ordem(raiz *r); //exibir em pre ordem -prefixa
void pos_ordem(raiz *r); //exibir em pos ordem -poxfixa
