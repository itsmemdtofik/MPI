#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>
#define BUFSIZE 100

void ErrorHandler(int errorCode){

	char errorString[BUFSIZE];
	int errorClass;
	int lengthOfTheString;
	if(errorCode != MPI_SUCCESS){

		MPI_Error_class(errorCode, &errorClass);
		MPI_Error_string(errorCode, errorString, &lengthOfTheString);
		printf("%d and %s \n", errorClass, errorString);
	}

}

int main(int argc, char *argv[]){

	int myRank;
	int size;
	int errorCode;
	int number;

	MPI_Init(&argc, &argv);

	errorCode = MPI_Comm_size(MPI_COMM_WORLD, &size);
	ErrorHandler(errorCode);
	errorCode = MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	ErrorHandler(errorCode);

	if(myRank == 0){
		printf("Enter the number : \n");
		scanf("%d", &number);
	}
	MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("I have recieved number [ %d ] from process [ %d ]\n", number, myRank);
	MPI_Finalize();
	printf("\n");
	return 0;
}