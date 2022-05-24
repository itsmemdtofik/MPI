#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
	int myRank;
	int rankSize;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	MPI_Comm_size(MPI_COMM_WORLD,&rankSize);
	printf("The process rank is = %d\n", myRank);
	printf("The process size is = %d\n",rankSize);
	MPI_Finalize();
	printf("\n");
	return 0;
}
