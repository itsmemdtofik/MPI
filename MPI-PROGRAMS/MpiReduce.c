#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc, char* argv[]){
	int rootRank;
	int size;
	int myRank;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if(size != 4){
		printf("This application meant to be run with 4 processes\n");
		MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
	}

	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	int reductionResult = 0;
	printf("Sending my rank from process [ %d ] \n", myRank);
	MPI_Reduce(&myRank, &reductionResult, 1, MPI_INT, MPI_SUM, rootRank, MPI_COMM_WORLD);
	
	if(myRank == rootRank){
		printf("The sum of all ranks is = [ %d ] \n", reductionResult);
	}

		MPI_Finalize();
		return 0;
}
