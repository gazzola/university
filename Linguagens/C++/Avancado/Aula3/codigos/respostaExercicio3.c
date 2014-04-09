/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio3.c - Resposta ao terceiro exercício da terceira aula
 */

#include <stdio.h>
#include <stdlib.h>

//---------------------------
// struct Node
//---------------------------
struct Node {
       int value;
       struct Node *next;
};

struct Node *initNode(int value) {
       struct Node *node = (struct Node *) malloc(sizeof(struct Node));

       node->next = NULL;
       node->value = value;
       return node;
}

// Libera a memória de todos os nós abaixo deste na pilha
void freeNodes(struct Node *node) {

       if (node != NULL) {
          freeNodes(node->next);
       }

       free(node);
}

//---------------------------
// struct Stack
//---------------------------
struct Stack {
       struct Node *first;
};

struct Stack *initStack() {
       struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));

       stack->first = NULL;
       return stack;
}

void push(struct Stack *stack, struct Node *node) {
     node->next = stack->first;
     stack->first = node;
}

struct Node *pop(struct Stack *stack) {
	struct Node *node = stack->first;

	// verifica se a pilha não esta vazia
	if (node != NULL) {
              stack->first = stack->first->next;
	}

	return node;	   
}

void freeStack(struct Stack *stack) {
     freeNodes(stack->first);
     free(stack);
}

int main() {
    struct Stack *stack = initStack();
    struct Node *node;

    push(stack, initNode(1));
    push(stack, initNode(2));
    push(stack, initNode(3));
    push(stack, initNode(4));
    push(stack, initNode(5));
    push(stack, initNode(6));
    push(stack, initNode(7));
    push(stack, initNode(8));
    push(stack, initNode(9));
    push(stack, initNode(10));

    node = pop(stack);

    while (node != NULL) {
		printf("%d\n", node->value);
		free(node);
		node = pop(stack);
    }


    freeStack(stack);
    return 0;
}
