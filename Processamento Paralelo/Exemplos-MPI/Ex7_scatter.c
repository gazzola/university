#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int *sndbuffer, recvbuffer;
	int rank, size, i;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	sndbuffer = (int *)malloc(size*sizeof(int));

	if(rank == 0){
		printf("[processo %d] (%d) envia: ", getpid(), rank);	
		for(i=0; i<size; i++){ 
			sndbuffer[i] = i*i;
			printf("%d ", sndbuffer[i]);
		}
		printf("\n");
	}

	MPI_Scatter(sndbuffer, 1, MPI_INT, &recvbuffer, 1, MPI_INT, 0, MPI_COMM_WORLD);

	printf("[processo %d] (%d) – Recebi %d\n", getpid(), rank, recvbuffer);

	MPI_Finalize();
	return 0;
}

