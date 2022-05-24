#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	int rank;
	int sendNumber;
	int size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank == 0){
		sendNumber = 555;
		MPI_Ssend(&sendNumber, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Sent number is = %d", sendNumber);
		printf("\n");
	}else if(rank == 1){
		for(int i = 0; i < 10000; i++){
			for(int j = 0; j < 100000; j++){
		}
	}
		MPI_Recv(&sendNumber, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Recieved number %d from process with rank %d",sendNumber, rank);
		printf("\n");
	}else{
		printf("Hello from process %d",rank);
		printf("\n");
	}
	MPI_Finalize();
	printf("\n");
	return 0;
}

