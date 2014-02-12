/*
* Imprimir triangular superior
*/

#include <stdio.h>

#define NL 3
#define NC 3

int main(){

	int i, j;
	int mat[NL][NC] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(i=0; i<NL; i++){
        for(j=0; j<NC; j++){
            if(i < j)
                printf(" %.2d ", mat[i][j]);
            else
                printf(" __ ");
        }
        printf("\n");
    }

    return 0;

}
