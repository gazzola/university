#include <stdlib.h>
#include <stdio.h>

void bubblesort(int n, int *x);
 
int main(int argc, char **argv) {
 
	int *x; 
	int num, i;
	
	printf("Informe o número de elementos:\n");
	scanf("%d", &num);

	x = (int*)malloc(sizeof(int)*num);

	for(i=0; i<num; i++){
		printf("Informe o elemento %d:\n", i);
		scanf("%d", &x[i]);
	}
 
	bubblesort(num, x);
	return 0;
 }

 
void bubblesort( int n, int *x){
      int aux;
      int j, i;
       
      for(i = 0; i < n-1; i++){
         for(j=i+1; j < n ; j++){
            if(x[i] > x[j]){
               aux = x[i];
               x[i] = x[j];
               x[j] = aux;
            }
         }
   }
   printf("O vetor ordenado: ");
   for(i=0; i<n; i++){
	printf("%d ", x[i]);
    }
    printf("\n");
}
