#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int value;
	struct _node *next;
}Node;

typedef struct _stack{
	Node *first;
}Stack;


enum bool{
	true, false
};

typedef enum bool boolean;


boolean emptyStack(Stack **stack){
	return ((*stack)->first == NULL) ? true : false;
}

void initStack(Stack **stack){
	*stack = (Stack*) malloc(sizeof(Stack));
	(*stack)->first = NULL;
}

void push(Stack **stack, Node *node){
	node->next = (*stack)->first;
	(*stack)->first = node;
	printf("push: %d\n", node->value);
}

Node *pop(Stack **stack){
	if((*stack)->first == NULL)
		return NULL;

	Node *temp = (*stack)->first;
	(*stack)->first = temp->next;
	printf("pop: %d\n", temp->value);
	return temp;
}

Node *newNode(int value){
	Node *aux = (Node*)malloc(sizeof(Node));
	aux->value = value;
	aux->next = NULL;
	return aux;
}

void freeNodes(Node **node){
	Node *aux = (*node)->next;

	while(aux != NULL){
		Node *temp = aux;
        aux = aux->next;
        free(temp);
	}

	free(node);
}

void freeStack(Stack **stack){
	if(emptyStack(&(*stack)) == false)
		freeNodes(&(*stack)->first);

	(*stack)->first = NULL;
}

void printNodes(Node **node){
	Node *aux = (*node);
	while(aux != NULL){
		printf("%d ", aux->value);
		aux = aux->next;
	}
}

void printStack(Stack **stack){
	printf("\n");
	if(emptyStack(&(*stack)) == false)
		printNodes(&(*stack)->first);
	printf("\n\n");
}



int main(){

	Stack *stack;

	initStack(&stack);
	push(&stack, newNode(5));
	push(&stack, newNode(2));
	push(&stack, newNode(3));
	push(&stack, newNode(8));
	push(&stack, newNode(9));
	push(&stack, newNode(6));
	push(&stack, newNode(1));
	push(&stack, newNode(7));

	printStack(&stack);

	Node *node = pop(&stack);
	node = pop(&stack);
	node = pop(&stack);
	node = pop(&stack);
	node = pop(&stack);
	node = pop(&stack);
	node = pop(&stack);
	free(node);
	

	printStack(&stack);
	freeStack(&stack);

	return 0;

}