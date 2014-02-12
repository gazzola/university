#include <stdio.h>
#include <string.h>
#define TAM 2

int main(){
	char ant[TAM + 1], atual[TAM + 1];
	int ocorrencias;

	scanf("%2s", &ant);
	ocorrencias = 1;
	while(scanf("%2s", &atual) != EOF){
		if(strcmp(ant, atual) == 0)
			ocorrencias = ocorrencias + 1;
		else{
			if(ocorrencias == 1)
				printf("%2s", ant);
			else
				printf("%d%2s", ocorrencias, ant);
			ant = atual;
			ocorrencias = 1;
		}
	}
	return 0;
}
