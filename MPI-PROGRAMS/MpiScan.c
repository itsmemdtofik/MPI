#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc, char *argv[]){

	int rootRank = 0;
	int size;
	int myRank;
	int result = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	/*Each process sends its rank to the SCAN method*/
	MPI_Scan(&myRank,&result, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

	printf("The scanned result in Process [ %d ] is = [ %d ] \n", myRank, result);
	MPI_Finalize();
	return 0;
}
