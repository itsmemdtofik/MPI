#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

int main(int argc, char* argv[]){

	int size;
	int myRank;
	char sendBuffer[10] = "TOFI";
	char *recvBuffer;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	int len = strlen(sendBuffer);
	recvBuffer = (char *)malloc(size * len * sizeof(char)); 

	/*Each MPI process sends its sendBuffer to root process which collet the data in rank order*/
	printf("Sending data [ %s ] from process [ %d ] \n", sendBuffer, myRank);
	MPI_Allgather(sendBuffer, 4, MPI_CHAR, recvBuffer, 4, MPI_CHAR, MPI_COMM_WORLD);

	/*Display gathered result*/
	printf("The gathered data at process [ %d ] is = [ %s ]\n", myRank, recvBuffer);

	MPI_Finalize();
	return 0;

}