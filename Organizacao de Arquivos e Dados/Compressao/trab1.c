/*
* Trabalho de Compressao de Arquivos
* Bruno, Gustavo, Marcos, Matheus, Paulo e Wolgan
*
* Original					   18.629  bytes
* Sequência de tamanho 2		9.373  bytes	49,685973482 %
* Sequência de tamanho 3		6.473  bytes	65,253100005 %
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

typedef struct __Node{
	char cod, data[N + 1];
	struct __Node *front;
}Node;

typedef Node* List;

/*
* Cria uma lista vazia
*/
void createList(List *l){
	*l = NULL;
}

/*
* Insere na lista e retorna o código da sequência
*/
char insertList(List *l, char data[N + 1]){
	Node *new = (Node *) malloc(sizeof(Node));
	int i;

	new->front = NULL;

	for(i = 0; i < N; ++i)
		new->data[i] = data[i];
	new->data[i] = '\0';

	if(*l == NULL){
		new->cod = '0';
		*l = new;
	}
	else{
		Node *aux;
		for(aux = *l; aux->front != NULL; aux = aux->front);
		new->cod = aux->cod + 1;
		aux->front = new;
	}
	return new->cod;
}

/*
* Busca sequência na lista, se existe retorna o cod, senão '0'
*/
char searchList(List *l, char data[N + 1]){
	Node *aux;
	for(aux = *l; aux != NULL; aux = aux->front)
		if(strcmp(aux->data, data) == 0)
			return aux->cod;
	return '!';
}

void destroyList(List *l){
	Node *aux, *aux2;
	for(aux = *l; aux != NULL;){
		aux2 = aux;
		aux = aux->front;
		free(aux2);
	}
	*l = NULL;
}

int main(){
	char seq[N+1], cod;
	Node *aux;
	List l;

	createList(&l);
	while(scanf("%3s", seq) != EOF){
		cod = searchList(&l, seq);
		if(cod == '!')
			cod = insertList(&l, seq);
		printf("%c", cod);
	}

	for(aux = l; aux != NULL; aux = aux->front)
		fprintf(stderr, "%s%c", aux->data, aux->cod);

	destroyList(&l);

	return 0;

}