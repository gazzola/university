#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int *sndbuffer, *recvbuffer;
	int rank, i, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	sndbuffer = (int *)malloc(size*sizeof(int));
	recvbuffer = (int *)malloc(size*sizeof(int));

	printf("[processo %d] (%d) buffer envio: ", getpid(), rank);
	for(i=0; i<size; i++){ 
		sndbuffer[i] = i*i+rank;
		printf("%d ", sndbuffer[i]);		
	}
	printf("\n");	

	MPI_Alltoall(sndbuffer, 1, MPI_INT, recvbuffer, 1, MPI_INT, MPI_COMM_WORLD);

	printf("[processo %d] (%d) buffer recebido: ", getpid(), rank);
	for(i=0; i<size; i++) 
		printf("%d ", recvbuffer[i]);		
	printf("\n");	

	MPI_Finalize();
	return 0;
}


