#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N     10

int main (int argc, char *argv[]) {
	int tid, i;
  	double a[N], b[N], c[N];

	/* Inicializacoes */
  	for (i=0; i < N; i++)  
    		a[i] = b[i] = i * 1.0;

  	printf("Fim da inicializacao sequencial.\n");

  	#pragma omp parallel for private(tid, i)
  	for (i=0; i<N; i++) 
	{
    		tid = omp_get_thread_num();
    		c[i] = a[i] + b[i];
      		printf("Fluxo %d calculando i = %d.\n", tid, i);
  	}
  	printf("Fim da parte paralela.\n");
}

