#include <stdio.h>

#define SIZE 2

int det(int m[SIZE][SIZE]){
	return (m[0][0] * m[1][1]) - (m[0][1]*m[1][0]);
}


int main(){
	
	int matrix[SIZE][SIZE];
	int i, j, d;
	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			printf("Digite um numero para o elemento %d-%d: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}

	d = det(matrix);
	printf("\nDeterminante: %d\n", d);

	return 0;
}