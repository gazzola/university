/*
* Implementacao do mundo dos blocos usando lista encadeada.
* Trabalho realizado em conjunto com Matheus Serpa e Wolgan Ens.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tblocos.h"

int tam_vetor; //var global para tamanho do vetor

void criaVetorListas(ListaD **MyLista, int imp){

    int i;
    for(i=0; i<tam_vetor; i++){ // percorro o vetor de listas
        MyLista[i] = (ListaD *) malloc(sizeof(ListaD)); // aloco memoria
        criaLista(MyLista[i]);  // crio a lista, faco os pontos prim e ult apontar para null
        insereInicio(MyLista[i],i); // insiro cada um em seu lugar inicial
    }
    if(imp){    // se for verdadeiro, imprimo a posicao inicial de cada um
        for(i=0; i<tam_vetor; i++){
            printf("%d: ",i);
            imprime(MyLista[i]);
        }
    }
}

void destroiLista(ListaD *l){
    Bloco *aux = l->prim;   // crio um bloco auxiliar
    while(aux != NULL){ // enquanto nao for null
        Bloco *libera = aux;    // crio um pronteiro para o bloco do auxiliar
        aux = aux->prox;    // mando o auxiliar apontar para o proximo
        free(libera);   //libera o bloco
    }
    l->prim = NULL; // aponto os pontos da lista para null
    l->ult = NULL;
}

void criaLista(ListaD *l){  // aponto os pontos da lista para null
    l->prim=NULL;
    l->ult=NULL;
}

void insereInicio(ListaD *l, int x){
    Bloco* novo = (Bloco*) malloc(sizeof(Bloco));
    novo->info = x;
    novo->ant = NULL;
    novo->prox = l->prim;

    if(l->prim!=NULL) //se lista não vazia
        l->prim->ant = novo;
    else //se lista vazia
        l->ult = novo;
        l->prim=novo;
}

void imprime(ListaD *l){
    Bloco *aux = l->ult;

    while(aux != NULL){// enquanto nao chego no fim da lista
        printf("%d ", aux->info);
        aux = aux->ant;
    }
    printf("\n");
}

void removeInicio(ListaD *l){
    if(l->prim != NULL){ //lista n eh vazia
        if(l->ult == l->prim){
            l->ult = NULL;
        }
        Bloco *aux = l->prim;
        l->prim = l->prim->prox;
        free(aux);//libera o bloco
    }
}

int verificaLista(ListaD *l,int x){
    Bloco *aux = l->prim;
    while(aux != NULL){// enquanto nao chego no fim da lista
        if(aux->info == x)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

void MoveAOntoB(ListaD **l, int a, int b){
    int i;
    int pos_a;
    int pos_b;
    printf("\nMove %d onto %d\n",a,b);
    if(a == b)
        return;
    for(i = 0; i < tam_vetor; i++){
        if(verificaLista(l[i],a)){
            pos_a = i;  // posicao do vetor corresponde a A
            break;
        }
    }
    for(i = 0; i < tam_vetor; i++){
        if(verificaLista(l[i],b)){
            pos_b = i;  // posicao do vetor corresponde a B
            break;
        }
    }
    if(pos_a == pos_b)  // se estiverem no mesmo vetor, ignora
        return;
    Bloco* aux = l[pos_a]->prim;
    while(aux != NULL){ // enquanto nao chego no fim da lista
        if(aux->info == a)  // se encontro o Bloco correpondente ao valor A, para
            break;
        int valor = aux->info;  // recupero o seu valor
        aux = aux->prox;    // faco o aux apontar para o proximo Bloco da lista
        removeInicio(l[pos_a]); //Removo no inicio o Bloco da posicao A do vetor
        insereInicio(l[valor],valor);   // Depois insiro o valor removido no vetor da sua posicao correspondente
    }
    aux = l[pos_b]->prim;
    while(aux != NULL){ // enquanto nao chego no fim da lista
        if(aux->info == b)  // se encontro o Bloco correpondente ao valor B, para
            break;
        int valor = aux->info;  // recupero o seu valor
        aux = aux->prox;    // faco o aux apontar para o proximo Bloco da lista
        removeInicio(l[pos_b]); //Removo no inicio o Bloco da posicao B do vetor
        insereInicio(l[valor],valor);   // Depois insiro o valor removido no vetor da sua posicao correspondente
    }
    int valor = l[pos_a]->prim->info;   // Como parou na execucao correpondente ao seu valor, devo inseri-lo no fim.
    removeInicio(l[pos_a]);
    insereInicio(l[pos_b],valor);
}


//////////// Mesma coisa que o MoveAOntoB so que sem a parte do B

void MoveAOverB(ListaD **l, int a, int b){

    int i;
    int pos_a;
    int pos_b;
    printf("\nMove %d over %d\n",a,b);
    if(a == b)
        return;
    for(i = 0; i < tam_vetor; i++){
        if(verificaLista(l[i],a)){
            pos_a = i;
            break;
        }
    }
    for(i = 0; i < tam_vetor; i++){
        if(verificaLista(l[i],b)){
            pos_b = i;
            break;
        }
    }
    if(pos_a == pos_b)
        return;
    Bloco* aux = l[pos_a]->prim;
    while(aux != NULL){
        if(aux->info == a)
            break;
        int valor = aux->info;
        aux = aux->prox;
        removeInicio(l[pos_a]);
        insereInicio(l[valor],valor);
    }

    int valor = l[pos_a]->prim->info;
    removeInicio(l[pos_a]);
    insereInicio(l[pos_b],valor);

}



void PileAOntoB(ListaD **l, int a, int b){

    int i;
    int pos_a;
    int pos_b;
    printf("\nPile %d onto %d\n",a,b);
    if(a == b)
        return;
    for(i = 0; i < tam_vetor; i++){ // posicao do vetor corresponde a A
        if(verificaLista(l[i],a)){
            pos_a = i;
            break;
        }
    }
    for(i = 0; i < tam_vetor; i++){ // posicao do vetor corresponde a B
        if(verificaLista(l[i],b)){
            pos_b = i;
            break;
        }
    }
    if(pos_a == pos_b)  // se estiverem no mesmo vetor, ignora
        return;

    Bloco* aux = l[pos_b]->prim;
    while(aux != NULL){ // enquanto nao chego no fim da lista
        if(aux->info == b)  // se encontro o Bloco correpondente ao valor B, para
            break;
        int valor = aux->info;  // recupero o seu valor
        aux = aux->prox;    // faco o aux apontar para o proximo Bloco da lista
        removeInicio(l[pos_b]); //Removo no inicio o Bloco da posicao B do vetor
        insereInicio(l[valor],valor);   // Depois insiro o valor removido no vetor da sua posicao correspondente
    }

    aux = l[pos_a]->prim;
    while(aux != NULL){     // percorro toda a lista
      if(aux->info == a)    // se encontro o Bloco correpondente ao valor A, para
            break;
      aux = aux->prox;

    }

    while(aux != NULL){ // enquanto nao chego no fim da lista
        int valor = aux->info;  // pego o valor do Block
        insereInicio(l[pos_b],valor);   // Insiro o valor na posicao B do vetor
        aux = aux->ant; // faco o aux apontar para o Bloco anterior da lista
   }
    aux = l[pos_a]->prim; // faco o aux valer a primeira posicao do vetor da posicao A
    while(aux != NULL){ // enquanto nao for nulo
        if(aux->info == a)  // pego sua informacao correpondente ao bloco A
            break;
        removeInicio(l[pos_a]); // removo do inicio o bloco na posicao A do vetor
        aux = aux->prox;    // faco o aux apontar para o prox bloco da lista
    }

    removeInicio(l[pos_a]); // por fim eu removo o inicio da posica A, pois quando parei a execucao, ele nao fez essa posicao

}



//////////// Mesma coisa que o PileAOntoB so que sem a parte do B

void PileAOverB(ListaD **l, int a, int b){

    int i;
    int pos_a;
    int pos_b;
    printf("\nPile %d over %d\n",a,b);
    if(a == b)
        return;
    for(i = 0; i < tam_vetor; i++){
        if(verificaLista(l[i],a)){
            pos_a = i;
            break;
        }
    }
    for(i = 0; i < tam_vetor; i++){
        if(verificaLista(l[i],b)){
            pos_b = i;
            break;
        }
    }
    if(pos_a == pos_b)
        return;

    Bloco* aux = l[pos_a]->prim;
    while(aux != NULL){
      if(aux->info == a)
            break;
      aux = aux->prox;

    }

    while(aux != NULL){
        int valor = aux->info;
        insereInicio(l[pos_b],valor);
        aux = aux->ant;
   }
    aux = l[pos_a]->prim;
    while(aux != NULL){
        if(aux->info == a)
            break;
        removeInicio(l[pos_a]);
        aux = aux->prox;
    }

    removeInicio(l[pos_a]);

}

void quit(ListaD **l){

    int i;
    for(i=0; i<tam_vetor; i++){ //percorro todo o vetor de lista
        destroiLista(l[i]); // destruo a lista
        free(l[i]); // libera a memoria correpondente
    }
    free(l);    // libero o vetor

}

void Entrada(){

    FILE *entrada_arquivo;
    entrada_arquivo = fopen("entrada.txt", "r");    // abro o arquivo no modo de leitura

    if(entrada_arquivo == NULL){    // se nao existir o arquivo, da o erro
        printf("\nErro! Arquivo de entrada nao encontrado.\n");
        exit(0);
    }

    int tam=1; char bn;

    while(!feof(entrada_arquivo)){  // enquanto nao chego no fim do arquivo
        fscanf(entrada_arquivo, "%c", &bn); // recupero o valor em caracteres do arquivo
        if(bn == '\n')  // se o valor for igual a uma quebra de linha, executo o contador.
            tam++;
    }
    tam -= 2;   // diminui 2 do contador, pois 2 linhas sao referenciadas ao tamanho do vetor e ao quit final.
    rewind(entrada_arquivo);    // coloco o ponteiro do arquivo de volta para o inicio.

    struct Arquivo *arq;    // declaro o vetor para estrutura do tipo Arquivo
    arq = (struct Arquivo *) malloc (tam * sizeof(struct Arquivo)); // Aloco memoria para ele, sendo o tamanho de linhas * seu tamanho por definicao

    int i;
    for(i=0; i<tam+2; i++){ // percorro todo o arquivo
        if(i == 0){
            fscanf(entrada_arquivo, "%d", &tam_vetor); // se for a primeira linha, recupero o valor do tamanho do vetor
        }
        else if(i>0 && i<tam+1){    // se tiver entre a 2 e a penultima linha, recupero os valores correspondentes as operacoes
            fscanf(entrada_arquivo, "%s", *&arq[i-1].ata);
            fscanf(entrada_arquivo, "%d", &arq[i-1].val_a);
            fscanf(entrada_arquivo, "%s", *&arq[i-1].atb);
            fscanf(entrada_arquivo, "%d", &arq[i-1].val_b);
        }
        else{ // se for a ultima, pego o quit
            fscanf(entrada_arquivo, "%s", *&arq[i-1].qt);
        }
    }

    if(tam_vetor < 1){  // se o tamanho do vetor for menor que 1, da o erro
        printf("\nErro! O vetor deve ter no minimo o tamanho 1.\n");
        exit(0);
    }
    else if(strcmp(arq[tam].qt, "quit") != 0){  // se nao estiver escrito quit corretamente, da o erro
        printf("\nErro! Deve conter um 'quit' para finalizar o programa.\n");
        exit(0);
    }
    else{   // senao

        int o;
        for(o=0; o<tam; o++){   // para cada linha entre a segunda e a penultima, verifico:
             if(strcmp(arq[o].ata, "move") != 0 && strcmp(arq[o].ata, "pile") != 0){    // se esta escrito move e/ou pile corretamente
                 printf("\nErro! Comando nao reconhecido: %s\n", arq[o].ata);
                 exit(0);
             }
             else if(strcmp(arq[o].atb, "over") != 0 && strcmp(arq[o].atb, "onto") != 0){   // se esta escrito over e/ou onto corretamente
                 printf("\nErro! Comando nao reconhecido: %s\n", arq[o].atb);
                 exit(0);
             }
             else if(arq[o].val_a < 0 || arq[o].val_a >= tam_vetor){      // se os valores de A sao menores que 0 ou sao maiores que ou igual ao tamanho do vetor
                 printf("\nErro! Posicao do vetor nao encontrada: %d\n", arq[o].val_a);
                 exit(0);
             }
             else if(arq[o].val_b < 0 || arq[o].val_b >= tam_vetor){    // se os valores de A sao menores que 0 ou sao maiores que ou igual ao tamanho do vetor
                 printf("\nErro! Posicao do vetor nao encontrada: %d\n", arq[o].val_b);
                 exit(0);
             }

        }

    }


    int k;  // faco a impressao dos blocos/listas
    for(k=0; k<tam; k++){
        printf("\nATA:%s A:%d ATB:%s B:%d\n", arq[k].ata, arq[k].val_a, arq[k].atb, arq[k].val_b);
    }
    printf("\nQUIT:%s TAM_VETOR:%d TAM_ENTRADA:%d\n\n", arq[tam].qt, tam_vetor, tam);

    fclose(entrada_arquivo);

    Manipula(tam, arq); // chamo a funcao para manipular as operacoes

}


void Manipula(int tam_entrada, struct Arquivo *arq){


    ListaD **MyLista = (ListaD **) malloc(tam_vetor * sizeof(ListaD*)); // aloco memorio para o vetor de listas
    criaVetorListas(MyLista, 1);    // crio o vetor de listas e mando imprimir os blocos na sua posicao inicial

    int i;
    for(i=0; i<tam_entrada; i++){

        if(strcmp(arq[i].ata, "move") == 0 && strcmp(arq[i].atb, "over") == 0){ // move a over b
            MoveAOverB(MyLista, arq[i].val_a, arq[i].val_b);    // chamo a operacao
            Saida(MyLista); // logo apos mando sair e imprimo a execucao
            int j;
            for(j=0; j<tam_vetor; j++){
                printf("%d: ", j);
                imprime(MyLista[j]);
            }
        }

        if(strcmp(arq[i].ata, "move") == 0 && strcmp(arq[i].atb, "onto") == 0){ // move a onto b
            MoveAOntoB(MyLista, arq[i].val_a, arq[i].val_b);    // chamo a operacao
            Saida(MyLista); // logo apos mando sair e imprimo a execucao
            int j;
            for(j=0; j<tam_vetor; j++){
                printf("%d: ", j);
                imprime(MyLista[j]);
            }
        }

        if(strcmp(arq[i].ata, "pile") == 0 && strcmp(arq[i].atb, "over") == 0){ // pile a over b
            PileAOverB(MyLista, arq[i].val_a, arq[i].val_b);    // chamo a operacao
            Saida(MyLista); // logo apos mando sair e imprimo a execucao
            int j;
            for(j=0; j<tam_vetor; j++){
                printf("%d: ", j);
                imprime(MyLista[j]);
            }
        }

        if(strcmp(arq[i].ata, "pile") == 0 && strcmp(arq[i].atb, "onto") == 0){ // pile a onto b
            PileAOntoB(MyLista, arq[i].val_a, arq[i].val_b);    // chamo a operacao
            Saida(MyLista); // logo apos mando sair e imprimo a execucao
            int j;
            for(j=0; j<tam_vetor; j++){
                printf("%d: ", j);
                imprime(MyLista[j]);
            }
        }

        if(strcmp(arq[i].qt, "quit") == 0)  //quit
            quit(MyLista);  // chamo a operacao quit

    }

}

void Saida(ListaD **MyLista){

    FILE *saida;
    saida = fopen("saida.txt", "w+");

    int i;
    for(i=0; i<tam_vetor; i++){ // percorro todo o vetor de listas
        fprintf(saida, "%d: ", i);  // imprimo o contador(i)

        Bloco *aux = MyLista[i]->ult;   // crio um bloco auxiliar da ultima posicao da listas
        while(aux != NULL){ // enquanto o auxiliar nao for igual a null, percorro toda a lista
            fprintf(saida," %d", aux->info);    // imprimo o valor do Bloco
            aux = aux->ant; // faco o auxiliar apontar para o bloco anterior
        }
        fprintf(saida, "\n");   // imprimo a quebra de linha

    }

    fclose(saida);
}


int main(){
   Entrada();
   return 0;
}
