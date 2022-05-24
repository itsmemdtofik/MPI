#include<mpi.h>
#include<stdio.h>
int main(int argc, char *argv[]){
	int myRank;
	int size;
	int sendNumber;
	int recvBuffer;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(myRank == 0){
		sendNumber = 555;
		MPI_Send(&sendNumber, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}else if(myRank == 1){
		sendNumber = 777;
		MPI_Send(&sendNumber, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
	}while(1){
		MPI_Recv(&recvBuffer, 1, MPI_INT, MPI_ANY_SOURCE,MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		printf("Process [ %d ] receieved number [ %d ] from Process [ %d ] in message [ %d ]\n", myRank, sendNumber, status.MPI_SOURCE, status.MPI_TAG);
	}
	MPI_Finalize();
	return 0;
}
