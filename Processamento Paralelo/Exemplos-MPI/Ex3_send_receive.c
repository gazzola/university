#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	int rank,size,tag=0,i;
	MPI_Status status;
	char msg[20];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0) {
		strcpy(msg,"Oi, mundo\0");
		for(i=1;i<size;i++){
			printf("[processo %d] Meu rank eh %d e estou enviando a mensagem <%s> para o processo de rank %d\n", getpid(), rank, msg, i);
			MPI_Send(msg, 20, MPI_CHAR, i, tag, MPI_COMM_WORLD);
		}
	}else {
		MPI_Recv(msg, 20, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
		printf("[processo: %d] Meu rank eh %d e recebi a mensagem <%s>\n", getpid(), rank, msg);
	}
	MPI_Finalize();
	return 0;
}

