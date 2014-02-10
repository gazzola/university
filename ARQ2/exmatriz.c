#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define TAM 1000

int m1[TAM][TAM];
int m2[TAM][TAM];
int m3[TAM][TAM];

double crono(){
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec / 1e6;
}


int main(){
	
	srand(time(NULL));
	int i,k,j;

	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			m1[i][j] = rand() % 1000000;
			m2[i][j] = rand() % 1000000;
			m3[i][j] = 0;
		}
	}

	double tempo = crono();

	for(i=0; i<TAM; i++)	
		for(j=0; j<TAM; j++)
			for(k=0; k<TAM; k++)
				m3[i][j] += m1[i][k]*m2[k][j];


	tempo = crono() - tempo;
	//tempo = (double)(crono() - tempo)/CLOCKS_PER_SEC;

    printf("\n\nTEMPO DE EXECUCAO: %.25lfs\n\n", tempo);

	return 0;
}