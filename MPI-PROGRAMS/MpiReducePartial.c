#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
	int root_rank = 0, size, my_rank, sum=0, reduction_result=0;
	int arr[4]={1,2,3,4};
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(size != 4)
	{
		printf("This application is meant to be run with 4 MPI processes.\n");
		MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
	}

    /*Find partial sum*/
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	sum = sum + arr[my_rank];
	printf("My rank is %d and the partial sum is %d \n", my_rank, sum);

    /*Each MPI process sends its rank to reduction, root MPI process collects the result*/
	MPI_Reduce(&sum, &reduction_result, 1, MPI_INT, MPI_SUM, root_rank, MPI_COMM_WORLD);
	if(my_rank == root_rank)
	{
		printf("The sum of all ranks is %d.\n", reduction_result);
	}

	MPI_Finalize();
	return 0;
}