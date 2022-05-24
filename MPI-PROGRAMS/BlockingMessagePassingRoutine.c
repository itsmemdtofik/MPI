#include<mpi.h>
#include<stdio.h>
int main(int argc, char *argv[]){
	int rank;
	int size;
	int sendNumber;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0){
       sendNumber = 777;
       MPI_Send(&sendNumber, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}else if(rank == 1){
		MPI_Recv(&sendNumber, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Process [ %d ] Received number from Process [ %d ] in Message [ %d ] :\n", rank, sendNumber, size);
	}else{
		printf("Hello from process [%d]\n", rank);
	}
	MPI_Finalize();
	return 0;
}