#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

#define TAMANHO 100000


/* Intercala as seqüências v[p]..v[q-1] e v[q]..v[r] */
void intercala (int p, int q, int r, int v[]) {
  int i, j, k;
  int w[TAMANHO];

  i = p;
  j = q;
  k = 0;

  while (i < q && j <= r) {
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
    mergesort (p, q, v);
    mergesort (q+1, r, v);
    intercala (p, q+1, r, v);
//    mostra_vetor(v);
  }
}

void imprimi(int vetor[]){
    int i;
    for(i = 0; i <= TAMANHO; i++){
        printf(" %d ",vetor[i]);
	}

}

int main () {

    srand(time(NULL));
    int vetor[TAMANHO];

    int i;

	for(i = 0; i < TAMANHO; i++){
		vetor[i] = (rand()%TAMANHO)+1;
	}

  mergesort (0, TAMANHO - 1, vetor);

    imprimi(vetor);

  return 0;
}
