#include<stdio.h>
#include<mpi.h>
int main(int argc, char *argv[]){
	int myRank;
	int size;
	int sendNumber;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(myRank == 0){
		sendNumber = 999;
		MPI_Send(&sendNumber, 1, MPI_INT, 1, 3, MPI_COMM_WORLD);
	}else if(myRank == 1){
		MPI_Recv(&sendNumber, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		printf("Process [ %d ] Received number [ %d ] from process [ %d ] in message [ %d ]\n", myRank, sendNumber, status.MPI_SOURCE, status.MPI_TAG);
	}else{
		printf("Hello from process [ %d ]\n", myRank);
	}
	MPI_Finalize();
	return 0;
}