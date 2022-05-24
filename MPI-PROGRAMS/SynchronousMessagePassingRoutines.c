#include<stdio.h>
#include<mpi.h>
int main(int argc, char *argv[]){
	int myRank;
	int size;
	int sendNumber;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	if(myRank == 0){
		sendNumber = 9999;
		MPI_Ssend(&sendNumber, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}else if(myRank == 1){
		MPI_Recv(&sendNumber, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process 1 has recieved number [ %d ] from Process 0 \n", sendNumber);
	}else{
		printf("Hello from Process %d\n", myRank);
	}
	MPI_Finalize();
	return 0;
}
