#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 10

int main( int argc, char** argv ) {
	int myrank, size;
	int i, somalocal, somatotal;
	int vet[TAM]; 

	MPI_Init( &argc, &argv );
	MPI_Comm_rank( MPI_COMM_WORLD, &myrank ); 
	MPI_Comm_size( MPI_COMM_WORLD, &size ); 

	if(myrank == 0)
		for(i=0; i<TAM; i++)
			vet[i]=1;

	MPI_Bcast(vet, TAM, MPI_INT, 0, MPI_COMM_WORLD);

	printf("[processo %d] (%d) vet: ", getpid(), myrank);
	for(i=0; i<TAM; i++)
		printf("%d ", vet[i]);
	printf("\n");			
	
	for(i=(TAM/size)*myrank ; i<((TAM/size)*(myrank+1)); i++)
		somalocal += vet[i]; 

	printf("[processo %d] (%d) somalocal: %d\n", getpid(), myrank, somalocal);		

	MPI_Reduce(&somalocal, &somatotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if(myrank == 0) 
		printf("[processo %d] (%d) somatotal: %d\n", getpid(), myrank, somatotal);		

	MPI_Finalize();
	return 0;
}


