#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define CHUNKSIZE 2
#define N     10

int main (int argc, char *argv[]) {
	int i, chunk, tid;
	float a[N], b[N], c[N];

	/* Some initializations */
	for (i=0; i < N; i++)
		a[i] = b[i] = i * 1.0;
	chunk = CHUNKSIZE;

	#pragma omp parallel shared(a,b,c,chunk) private(i, tid)
  	{
		#pragma omp for schedule(static, chunk) nowait
		for (i=0; i < N; i++)
		{
    			c[i] = a[i] + b[i];
			tid = omp_get_thread_num();
      			printf("Fluxo %d chunk %d calculou i = %d\n", tid, chunk, i);
		}
  	}  /* end of parallel region */	
}

