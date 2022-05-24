#include <stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<string.h>

int main(int argc, char* argv[]){

    int rootRank = 0;
    int size;
    int myRank;
    char sendBuffer[10] = "AA";
    char *recvBuffer;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

    int len = strlen(sendBuffer);
    sendBuffer[len - 2] = sendBuffer[len - 2] + myRank;
    recvBuffer = (char *)malloc(size * len * sizeof(char));

    /*Each MPI process sends its sendBuffer to root process which collects the data in rank order.*/
    printf("Sending data [ %s ] from process [ %d ] \n", sendBuffer, myRank);
    MPI_Gather(sendBuffer, len, MPI_CHAR, recvBuffer, len, MPI_CHAR, rootRank, MPI_COMM_WORLD);

    /*Display the result in Root*/
    if(myRank == rootRank){
    	printf("The gathered data at root is = [ %s ] \n", recvBuffer);
    }

    MPI_Finalize();
    return 0;
}