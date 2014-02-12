#include <stdio.h>
#define MAX 10

int buscaSequencial(int *x, int *v){
	int i;
	for(i=0; i<MAX; i++){
		if(v[i] == *x) 
			return i;	
	}
	return -1;
}

int main(){
	
	int v[MAX] = {1,2,3,4,5,6,7,8,9,10};
	int x;

	printf("Digite um valor a ser encontrado: ");
	scanf("%d", &x);
	x = buscaSequencial(&x, v);
	(x != -1) ? printf("encontrado!, indice:%d", x) : printf("nao encontrado!");

	return 0;
}