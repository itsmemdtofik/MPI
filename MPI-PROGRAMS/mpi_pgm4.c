#include<mpi.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
	int sendNumber;
	int recvNumber;
	int size;
	int rank;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank == 0){
		printf("Enter the number : ");
		scanf("%d",&sendNumber);
		MPI_Send(&sendNumber, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("The number %d has transferred to reciever : 1",sendNumber);
	}else if(rank == 1){
		MPI_Recv(&recvNumber, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		printf("The message has been received from sender  : %d",recvNumber);
	}
	MPI_Finalize();
	return 0;
}