#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
int main(int argc, char *argc[])
{
    int a, b, c;
    int rank;
    MPI_Status status;
    if (rank == 0)
    {
        MPI_Send(&a, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        MPI_Recv(&b, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
        c = a + b / 2;
    }
    else if (rank == 1)
    {
        MPI_Send(&b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        c = a + b / 2;
    }
    else
    {
        printf("Hello from Process [ %d ] \n", myRank);
    }
    MPI_Finalize();
    return 0;
}