/*
 * Multiplicação de matrizes
 *
 * (o número de colunas da primeira deve ser igual ao número de linhas da segunda)
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int** constroimatriz(int nl, int nc, int randomico);
int** multiplicamatriz(int** mat1,int nl1,int nc1, int** mat2, int nc2);
void imprimematriz(int** mat, int nl, int nc);

int main(int argc, char* argv[]){
	int **mat1,**mat2,**matR;
	int m1l, m1c, m2l, m2c, i, j, randomico;
	srand(time(NULL));
        
	if( argc==5 ){
		m1l = atoi(argv[1]);
		m1c = m2l = atoi(argv[2]);
		m2c = atoi(argv[3]);
		randomico = atoi(argv[4]);

		if( m1c == 0 || m1l == 0 || m2l == 0 || m2c == 0 ){
			printf("Nenhum dos quatro parâmentros pode ser nulo!\n");
			exit (1);
		}
		if(randomico != 0 && randomico != 1){
			printf("O último parâmetro deve ser 0 ou 1...\n");
			exit(2);
		}
		mat1 = constroimatriz(m1l,m1c,randomico);
		mat2 = constroimatriz(m2l,m2c,randomico);
		matR = multiplicamatriz(mat1, m1l, m1c, mat2, m2c);

	
		printf("\nMatriz 1:\n");
		imprimematriz(mat1,m1l,m1c);
		printf("Matriz 2:\n");
		imprimematriz(mat2,m2l,m2c);
		printf("Matriz resultante:\n");
		imprimematriz(matR,m1l,m2c);
	
		return 0;
        }
        else{
                printf("Número incorreto de parâmetros!\nVocê deve passar 4 parâmentros para o programa: \nnum_linhas_mat1 num_colunas_mat1_num_linhas_mat2 num_colunas_mat2 random\nOnde os tres primeiros devem ser inteiros positivos não nulos e o último deve ser 0 ou 1\n");
		exit (3);
        }
	
}

int** constroimatriz(int nl, int nc, int randomico){
	int** matriz;
	int i,j;
	matriz = (int**)malloc(sizeof(int*)*nl);
        for(i=0; i<nl; i++){
                matriz[i] = (int*)malloc(sizeof(int)*nc);
		if(randomico!=-1)
			if(randomico)
		                for(j=0; j<nc; j++)
        		                matriz[i][j]=rand()%100;
			else
	        	        for(j=0; j<nc; j++)
					scanf("%d",&matriz[i][j]);
		else
			for(j=0; j<nc; j++)
        			matriz[i][j]=0;
			
        }
	return matriz;
}
int** multiplicamatriz(int** mat1,int nl1,int nc1, int** mat2, int nc2){
	int** matriz;
	int i,j,k;
	
	clock_t tempoinicial, tempofinal;
	double tempo = 0.0;

	matriz = constroimatriz(nl1,nc2,-1);

	//inicio da medição do tempo
	tempoinicial = clock();

	//fazer aqui a lógica da multiplicação de matrizes
	for(i=0; i<nl1; i++)
		for(j=0; j<nc2; j++)
			for(k=0; k<nc1;k++)
				matriz[i][j]+=mat1[i][k]*mat2[k][j];
	
	//final da medição do tempo
	tempofinal = clock();

	tempo = (double)(tempofinal-tempoinicial)/CLOCKS_PER_SEC;

	//impressão do tempo da multiplicação
	printf("Tempo: %f seg\n",tempo);
	
	return matriz;
}

void imprimematriz(int** mat, int nl, int nc){
	int i,j;
	for(i=0; i<nl; i++){
		for(j=0; j<nc; j++){
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
