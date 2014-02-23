/*
* TRABALHO 2 - PAA - CODIFICACAO DE HUFFMAN USANDO HEAP MINIMO
* MARCOS TREVISO - 121150107
* ASCII MODE - 128 CHARS
*/

#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

#define ASCII_SIZE 128


typedef struct _node{
    unsigned int frequence;
    char data;
    struct _node *left;
    struct _node *right;
}MinHeapNode;
 
typedef struct _heap{
	unsigned short int size;
	MinHeapNode **array;
}MinHeap;


MinHeap *createMinHeap(){
    MinHeap *new = (MinHeap*) malloc (sizeof(MinHeap));
    new->size = 0;
    new->array = (MinHeapNode**)malloc(ASCII_SIZE * sizeof(MinHeapNode*));
    return new;
}


MinHeapNode *newNode(char data, int frequence){
    MinHeapNode *new = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    new->left = new->right = NULL;
    new->data = data;
    new->frequence = frequence;
    return new;
}


void fillAsciiVector(int *vector, int value){
	int i;
	for(i=0; i<ASCII_SIZE; i++)
		vector[i] = value;
}


void printElements(int *v){
	int i;
	for(i=0; i<ASCII_SIZE; i++)
		if(v[i] != 0)
			printf("%c:%d\n", i, v[i]);
}


int main(){
	
	char c;
	int v[ASCII_SIZE], pos, amount=0;

	fillAsciiVector(v, 0);

	while(scanf("%c", &c) != EOF){
		pos = (int) c;
		if(v[pos] == 0)
			amount++;
		v[pos] += 1;	
	}

	printElements(v);

	printf("\n\n");

	//int *heap = (int*) malloc (amount * sizeof(int));

	//juntar menores recursivamente para compactacao
	//inserir valores no heap 
	//analisar balanceamentos do heap
	//verificar percorrimentro inverso para descompactacao

	
	return 0;
}





