#include <stdio.h>
#include <stdlib.h>

void par_impar(int *a, int N){
    int i, j, swap;
    for(j=0;j<N;j++){
        for(i=0;i<N;i=i+2){
            if(a[i] > a[i+1]){
                swap = a[i];
                a[i] = a[i+1];
                a[i+1] = swap;
            }
        }
        for(i=1;i<N;i=i+2){
            if(a[i] > a[i+1]){
                swap = a[i];
                a[i] = a[i+1];
                a[i+1] = swap;
            }
        }
    }
    printf("O vetor ordenado: ");
    for(i=0; i<N; i++){
	printf("%d ", a[i]);
    }
    printf("\n");
    	
}

int main (int argc, char **argv){
	int *a;
	int N, i;

	printf("Informe o número de elementos:\n");
	scanf("%d", &N);

	a = (int*)malloc(sizeof(int)*N);

	for(i=0; i<N; i++){
		printf("Informe o elemento %d:\n", i);
		scanf("%d", &a[i]);
	}

	par_impar(a, N);

}
