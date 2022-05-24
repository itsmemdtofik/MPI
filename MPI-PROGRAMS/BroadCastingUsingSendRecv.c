#include<stdio.h>
#include<stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]){
	int i;
	int rootRank = 0;
	int myRank;
	int size;
	int recv;
	int recvBuffer;
	int sendBuffer = 777;
    
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	if(myRank == 0){
		for(i = 1; i < size; i++)
			MPI_Send(&sendBuffer, 1, MPI_INT, i, 2, MPI_COMM_WORLD);
	}else if(myRank == 1){
		MPI_Recv(&recvBuffer, 1,MPI_INT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Procces [ %d ] receieved number [ %d ] from Process 0 \n", myRank, recvBuffer);
	}else{
		printf("Hello from Process [ %d ] \n\n", myRank);
	}
	MPI_Finalize();
	return 0;
}