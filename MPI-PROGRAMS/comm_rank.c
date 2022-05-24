#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, char *argv[])
{

	int myRank;
	int size;
	int sendBuffer = 111;
	int recvBuffer[4];
	int root = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	int N;
	int buffer1[10];
	int number;

	if (size != 4)
	{
		printf("This will work only with process : \n");
		MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
	}

	if(myRank == 0){
		printf("Enter the size of an array : \n");
		scanf("%d", &N);
		printf("Enter the elements of an array : \n");
		for(int i = 0 ; i < size; i++){
			scanf("%d", &buffer1[i]);
		}

	}
	
	MPI_Recv(&buffer1, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	for(int i = 0; i < N; i++){
		printf("We have recieved number [ %d ] from process [ %d ] :\n", buffer1[i], myRank);
	}
	printf("\n");
	MPI_Finalize();
	return 0;
}