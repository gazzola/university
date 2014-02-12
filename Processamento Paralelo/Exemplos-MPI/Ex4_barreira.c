#include <mpi.h>
#include <stdio.h>


int main(int argc, char **argv) {
	int rank,size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	printf("[processo %d] Meu rank eh %d num total de %d processos\n", getpid(), rank, size);

	if(rank == 0) {
		printf("(%d) -> [processo %d] Primeiro a escrever!\n", getpid(), rank);
		MPI_Barrier(MPI_COMM_WORLD);
	}else  {
		MPI_Barrier(MPI_COMM_WORLD);
		printf("(%d) -> [processo %d] Agora posso escrever!\n", getpid(), rank);
	}

	MPI_Finalize();
	return 0;
}

