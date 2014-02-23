/*
* HEAP MIN - BASIC FUNCTIONS
*/

#include <stdio.h>
#include <stdlib.h>


int issetNode(int node, int *size){
	return (node < *size);
}

int getFather(int *heap, int node){
	return heap[(int) node/2];
}

int getLeftSon(int *heap, int node, int *size){
	node = node*2;
	if(issetNode(node, &(*size)))
		return heap[node];
	return -1;
}

int getRightSon(int *heap, int node, int *size){
	node = node*2 + 1;
	if(issetNode(node, &(*size)))
		return heap[node];
	return -1;
}

void rollUp(int *heap, int node, int *size){
	int temp, pos;
	while(getFather(heap, node) > heap[node]){
		temp = getFather(heap, node);
		pos = node/2;
		heap[pos] = heap[node];
		heap[node] = temp;
		node = pos;
	}
}

void rollDown(int *heap, int node, int *size){
	int temp, pos;
	while(heap[node] > getLeftSon(heap, node, &(*size)) || heap[node] > getRightSon(heap, node, &(*size))){
		if(getRightSon(heap, node, &(*size)) < getLeftSon(heap, node, &(*size)))
			pos = node*2 + 1;
		else
			pos = node*2;

		if(!issetNode(node, &(*size)))
			break;

		temp = heap[pos];
		heap[pos] = heap[node];
		heap[node] = temp;
		node = pos;
	}
}


void swap(int *heap, int node1, int node2){
	int temp = heap[node1];
	heap[node1] = heap[node2];
	heap[node2] = temp;
}


void heapify(int *heap, int node, int *size){
	int bigger = node;

	if(getLeftSon(heap, node, &(*size)) < heap[node] && getLeftSon(heap, node, &(*size)) != -1)
		bigger = node*2;

	if(getRightSon(heap, node, &(*size)) < heap[bigger] && getRightSon(heap, node, &(*size)) != -1)
		bigger = node*2 + 1;

	if(bigger != node){
		swap(heap, node, bigger);
		heapify(heap, bigger, &(*size));
	}
}


void buildHeap(int *heap, int *size){
	int i;
	for(i = (*size)/2; i>0; --i)
		heapify(heap, i, &(*size));
}

void insertNodeWithoutRoll(int *heap, int node, int *size, int *capacity){
	int pos = (*size);
	if(*size + 1 > *capacity){
		printf("Numero maximo de nodos no heap!\n");
		exit(0);
	}
	
	heap[pos] = node;
	(*size) += 1;
}


int extractMin(int *heap, int *size){
	int temp = heap[1];
	int pos = (*size)-1;
	heap[1] = heap[pos];
	*size -= 1;
	rollDown(heap, 1, &(*size));
	return temp;
}


void insertNode(int *heap, int node, int *size, int *capacity){
	int pos = (*size);
	if(*size + 1 > *capacity){
		printf("Numero maximo de nodos no heap!\n");
		exit(0);
	}
	
	heap[pos] = node;
	(*size) += 1;
	rollUp(heap, pos, &(*size));
}


void printHeap(int *heap, int *size){
	int i=1, nl=2;
	while(i < (*size)){
		printf("%d ", heap[i]);
		i++;
		if(i == nl){
			nl *= 2;
			printf("\n");
		}
	}
}



void iniatlize(int *heap, int *size){
	*size = 1;
	heap[0] = -1;
}


int main(int argc, char **argv){

	if(argc < 2){
        printf("\nErro! Informe a capacidade maxima do heap.\n");
        return 1;
    }

	int capacity = atoi(argv[1]);
	int *heap = (int*) malloc (capacity*sizeof(int));
	int size;

	iniatlize(heap, &size);

	insertNode(heap, 3, &size, &capacity);
	insertNode(heap, 7, &size, &capacity);
	insertNode(heap, 5, &size, &capacity);
	insertNode(heap, 8, &size, &capacity);
	insertNode(heap, 13, &size, &capacity);
	insertNode(heap, 6, &size, &capacity);
	insertNode(heap, 12, &size, &capacity);
	insertNode(heap, 15, &size, &capacity);
	insertNode(heap, 8, &size, &capacity);

	insertNode(heap, 4, &size, &capacity);

	printHeap(heap, &size);
	printf("\n");

	int min = extractMin(heap, &size);
	printf("\nMIN: %d\n", min);

	printHeap(heap, &size);

	printf("\n");
	return 0;
}