#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int main(int argc, char *argv[]){
	int myRank;
	int size;
	int dataSend = 12345;
	int received;
	int bufferAttachedSized;
	bufferAttachedSized = MPI_BSEND_OVERHEAD + sizeof(int);
	char *bufferAttched;
	bufferAttched = (char *)malloc(bufferAttachedSized);

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	if(myRank == 0){
		MPI_Buffer_attach(bufferAttched, bufferAttachedSized);
		printf("Sender [ %d ] sent value [ %d ] \n", myRank, dataSend);
		MPI_Bsend(&dataSend, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Buffer_detach(&bufferAttched, &bufferAttachedSized);
		free(bufferAttched);
	}else if(myRank == 1){
		MPI_Recv(&received, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Receiver [ %d ] receieved value : [ %d ] \n", myRank, received);
	}else{
		printf("Process from [ %d ] \n", myRank);
	}
	MPI_Finalize();
	return 0;
}
