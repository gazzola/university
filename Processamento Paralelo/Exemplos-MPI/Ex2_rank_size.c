#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int rank, size;
	
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	printf("[processo %d] Oi Mundo! Meu rank eh %d num total de %d processos\n", getpid(), rank, size);

	MPI_Finalize();
	return 0;
}

