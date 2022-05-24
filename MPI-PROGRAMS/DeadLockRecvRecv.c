#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc, char *argv[])
{
	int a;
	int b;
	int c;
	int myRank;
	MPI_Status status;
	if (myRank == 0)
	{
		MPI_Recv(&b, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
		MPI_Send(&a, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		c = (a + b) / 2;
	}
	else if (myRank == 1)
	{
		MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Send(&b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		c = (a + b) / 2;
	}
	else
	{
		printf("Hello from Process [ %d ]\n\n", myRank);
	}
	MPI_Finalize();
	return 0;
}
