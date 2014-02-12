#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "fun.c"


int main(){

	raiz novo = NULL;

	inserir(&novo, 8);
	inserir(&novo, 3);
	inserir(&novo, 10);
	inserir(&novo, 1);
	inserir(&novo, 6);
	inserir(&novo, 14);
	inserir(&novo, 4);
	inserir(&novo, 7);
	inserir(&novo, 13);

    printf("EM ORDEM: ");
	em_ordem(&novo);
	printf("\nPRE ORDEM: ");
	pre_ordem(&novo);
	printf("\nPOS ORDEM: ");
	pos_ordem(&novo);
	printf("\n");

	return 0;
}
