#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	char message[30];
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	printf("[processo %d] Meu rank eh %d num total de %d processos\n", getpid(), rank, size);

	if(rank == 0)
		strcpy(message, "Oi, mundo\0");

	MPI_Bcast(message, 30, MPI_CHAR, 0, MPI_COMM_WORLD);

	if(rank != 0)
		printf("[processo %d] (%d) – Recebi %s\n", getpid(), rank, message);

	MPI_Finalize();
	return 0;
}

