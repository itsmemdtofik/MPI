#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc, char *argv[]){

	int rootRank = 0;
	int size;
	int myRank;
	int sendBuffer = 111;
	int recvBuffer[4];

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(size != 4){
		printf("This application is meant to be run with 4 processes\n\n");
		MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
	}
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	
	/*Each MPI process send buffer to root processes which collect the data in rank oerder*/
	printf("Sending data [ %d ] from process [ %d ] \n\n", sendBuffer, myRank);
	MPI_Gather(&sendBuffer, 1, MPI_INT, &recvBuffer, 1, MPI_INT, rootRank, MPI_COMM_WORLD);

	/*Display result in root*/
	if(myRank == rootRank){
		printf("The gathered data is \n");
		for(int i = 0; i < 4; i++)
			printf("[ %d ]\n", recvBuffer[i]);
	}

	MPI_Finalize();
	return 0;
}