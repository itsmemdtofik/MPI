#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    int myRank;
    MPI_Status status;

    if (myRank == 0)
    {
        MPI_Send(&a, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        MPI_Recv(&b, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
        c = a + b / 2;
    }
    else if (myRank == 1)
    {
        MPI_Send(&b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        c = a + b / 2;
        printf("Procces [ %d ] receieved number [ %d ] from Process 0 \n", myRank, a);
    }
    else
    {
        printf("Hello from process [ %d ] \n\n", myRank);
    }
    MPI_Finalize();
    return 0;
}