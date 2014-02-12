#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	MPI_Init(&argc, &argv);

	printf("[processo %d] Oi Mundo!\n", getpid());
	
	MPI_Finalize();
	return 0;
}
