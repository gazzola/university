/******************************************
*
* TRABALHO DE PROJETO E ANALISE DE ALGORITMOS
* Resolver corretamente o primeiro trabalho
* Marcos Vinicius Treviso - 121150107
* 
* EXECUTAR (LINUX): 
* ./execname < ../colecoes/colecao1.txt
*
* Ou use o arquivo run_c.sh na raiz
*
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


int *allocateVector(int m){
	int *vector = (int*) calloc(m, sizeof(int));
	return vector;
}

int **allocateMatrix(int m, int n){
	int i;
	int **matrix = (int**) calloc(m, sizeof(int*));
	for(i=0; i<m; ++i)
		matrix[i] = (int*) calloc(n, sizeof(int*));
	return matrix;
}

void vectorFreeAllocation(int *vector){
	free(vector);
}

void matrixFreeAllocation(int **matrix, int m){
	int i;
	for(i=0; i<m; ++i)
		free(matrix[i]);
	free(matrix);
}


//complexity: O(n.maxSize)
int binaryKnapsackMatrix(int **matrix, int n, int *weight, int *rank, int maxSize){
	
	int x, i, a, b, vi, pi, pos;
	
	for(x=0; x<=maxSize; ++x){
		for(i=1; i<=n; ++i){
			pos = i-1;
			a = matrix[pos][x];

			vi = rank[pos];
			pi = weight[pos];

			if(x-pi >= 0){
				b = vi + matrix[pos][x-pi];
				if(a < b)
					a = b;
			}

			matrix[i][x] = a;
		}
	}

	return matrix[n][maxSize];
}



void swapVectors(int *vB, int *vC, int maxSize){
	int i;
	for(i=0; i<=maxSize; ++i)
		vB[i] = vC[i];
}

void swapVectorsPointers(int **vB, int **vC){
	int *temp = *vB;
	*vB = *vC;
	*vC = temp;  
}


//complexity: O(n.maxSize)
int binaryKnapsackVector(int **vB, int **vC, int n, int *weight, int *rank, int maxSize){
	
	int x, i, a, b, vi, pi;

	for(x=0; x<n; ++x){
		for(i=0; i<=maxSize; ++i){
			a = (*vB)[i];
			
			vi = rank[x];
			pi = weight[x];

			if(i-pi >= 0){
				b = vi + (*vB)[i-pi];
				if(a < b)
					a = b;
			}

			(*vC)[i] = a;
		}

		swapVectorsPointers(&(*vB), &(*vC));
		//swapVectors(*vB, *vC, maxSize);
		
	}

	return (*vC)[maxSize];
}



double crono(){
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec / 1e6;
}


int main(){
	
	srand(time(NULL));
	int maxSize, ammount, aux, id, count=0, 
		*weight, *rank;

	//int **matrix;
	int *vectorBefore, *vectorCurrent;


	//get the maxSize of bag and ammount of elements
	scanf("%d %d", &maxSize, &ammount);


	//set allocations
	weight = allocateVector(ammount);
	rank = allocateVector(ammount);
	vectorBefore = allocateVector(maxSize+1);
	vectorCurrent = allocateVector(maxSize+1);
	//matrix = allocateMatrix(ammount+1, maxSize+1);


	//get the values contained in file
	aux = ammount;
	while(aux--){
		scanf("%d %d %d", &id, &weight[count], &rank[count]);
		count++;
	}


	//calcule time of binaryKnapsack function
	double timer = crono();
	int result = binaryKnapsackVector(&vectorBefore, &vectorCurrent, ammount, weight, rank, maxSize);
	//int result = binaryKnapsackMatrix(matrix, ammount, weight, rank, maxSize);
	timer = crono() - timer;


	//clean memory
	vectorFreeAllocation(weight);
	vectorFreeAllocation(rank);
	vectorFreeAllocation(vectorBefore);
	vectorFreeAllocation(vectorCurrent);
	//matrixFreeAllocation(matrix, ammount+1);


	printf("\nRESULTADO: %d\nTEMPO DE EXECUCAO: %.25lfs\n\n", result, timer);
	
	return 0;
}