typedef struct _Bloco{  // estrutura tipo Bloco(Nodo)
    int info;
    struct _Bloco *ant;
    struct _Bloco *prox;
} Bloco;

typedef struct _listaD{ // estrutura tipo ListaD(Deque)
    struct _Bloco *prim;
    struct _Bloco *ult;
} ListaD;


struct Arquivo{ // estrutura tipo Arquivo
    int val_a;
    int val_b;
    char ata[10];
    char atb[10];
    char qt[10];
};


void criaLista(ListaD *l);  // Cria a lista (aponta o prim e o ult da lista para null).

void destroiLista(ListaD *l);   // Destroi cada componente da lista e faz o prim eo ult apontar para null.

int verificaLista(ListaD *l, int x);    // Verifica se na info do Bloco possui o valor igual a x, retornando 1 se V e 0 para F, podendo assim retornar a posicao do elemento.

void criaVetorListas(ListaD **MyLista, int imp);    // Cria o vetores de listas e insere cada um em sua posicao inicial, se imp=1 -> imprime a lista inicial.

void removeInicio(ListaD *l);   // Remove os Blocos do inicio da lista.

void insereInicio(ListaD *l, int x);    // Insere os Blocos no inicio da lista.

void imprime(ListaD *l);    // Imprime a lista do fim para o inicio.

void MoveAOntoB(ListaD **l, int a, int b);  // Move o Bloco A para cima do Bloco B, retornando eventuais Blocos que estiverem acima dos mesmos aos seus lugares iniciais.

void MoveAOverB(ListaD **l, int a, int b);  // Move o Bloco A para cima do Bloco B, retornando eventuais Blocos que estiverem acima do Bloco A aos seus lugares iniciais.

void PileAOntoB(ListaD **l, int a, int b);  // Empilha o Bloco A no Bloco B, retornando eventuais Blocos que estiverem acima do Bloco B para seus lugares iniciais.

void PileAOverB(ListaD **l, int a, int b);  // Empilha o Bloco A no Bloco B.

void quit(ListaD **l);  // Destroi a lista e libera a memoria ocupada pela lista e pelo vetor de listas.

void Entrada(); // Le os valores do arquivo entrada.txt e verifica sua validade.
void Manipula(int tam_entrada, struct Arquivo *arq);    // Manipula os valores obtidos na entrada e seleciona a funcao respectiva a eles.
void Saida(ListaD **MyLista);   // Sobrescreve o arquivo saida.txt com de acordo com as opcoes desejadas no arquivo de entrada.
