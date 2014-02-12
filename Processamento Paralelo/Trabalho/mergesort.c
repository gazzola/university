/*
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ms/call  ms/call  name
100.00      0.02     0.02    99999     0.00     0.00  intercala
  0.00      0.02     0.00        1     0.00     0.00  imprimi
  0.00      0.02     0.00        1     0.00    20.00  mergesort


maior tempo na função intercala, pois ela é a que divide e conquista os sub-problemas.

*/

#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

#define TAMANHO 1000000

/* Intercala as seqüências v[p]..v[q-1] e v[q]..v[r] */
void intercala (int p, int q, int r, int v[]) {
  int i, j, k;
  int w[TAMANHO];

  i = p;
  j = q;
  k = 0;

  while (i < q && j <= r){
    if (v[i] <= v[j])
      w[k++] = v[i++];
    else
      w[k++] = v[j++];
  }

  while (i < q)
    w[k++] = v[i++];

  while (j <= r)
    w[k++] = v[j++];

  for (i = p; i <= r; i++)
    v[i] = w[i-p];

}

void mergesort (int p, int r, int v[]) {
  if (p < r) {
    int q = (p + r)/2;
    #pragma omp task if(q-p > 1000000)
    {
      mergesort (p, q, v);
    }
    #pragma omp task
    {
      mergesort (q+1, r, v);
    }
    #pragma omp taskwait
    {
      intercala (p, q+1, r, v);
    }
  }
}

void imprimi(int vetor[]){
  int i;
  for(i = 0; i<TAMANHO; i++){
      if(i != 0 && vetor[i - 1] > vetor[i]){
    //printf("%d ",vetor[i]);
        printf("gamb");
      }
  }

}

int main () {
  double tempo;
  srand(time(NULL));
  int vetor[TAMANHO];

  int i;

  for(i = 0; i < TAMANHO; i++){
    vetor[i] = (rand()%TAMANHO)+1;
  }
  tempo = omp_get_wtime();

  #pragma omp parallel
  {
    #pragma omp single
    {
      mergesort (0, TAMANHO-1, vetor);
    }
  }

  tempo = omp_get_wtime() - tempo;
  imprimi(vetor);
  printf("%lf\n", tempo);

  return 0;
}
