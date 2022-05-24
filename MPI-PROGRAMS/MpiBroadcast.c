#include <stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc, char* argv[]){
	int myRank;
	int count;
	const int root = 0;
	int sendBuffer = 111;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
    
	if(myRank == root){
		printf("I have sent the number : \n");
	}
    sendBuffer = sendBuffer + myRank;
	MPI_Bcast(&sendBuffer, 1, MPI_INT, root, MPI_COMM_WORLD);
	printf("Before broadcast Process [ %d ] : after broadcast [ %d ] \n", myRank, sendBuffer);
	MPI_Finalize();
	return 0;
}
