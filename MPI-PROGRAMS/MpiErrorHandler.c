#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<mpi.h>

void ErrorHandler(int errorCode);

int main(int argc, char* argv[]){

	int c = 3;
	int size;
	int myRank;
	int len;
	int errorCode;

	MPI_Init(&argc, &argv);
	MPI_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

	errorCode = MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
	errorCode = MPI_Comm_size(MPI_COMM_WORLD, &size);

	ErrorHandler(errorCode);
	printf("Number of Processes = [ %d ] and My Rank is = [ %d ]\n", size, myRank);
	MPI_Finalize();
	return 0;
}

void ErrorHandler(int errorCode){

	if(errorCode != MPI_SUCCESS){
		char errorString[BUFSIZ];
		int lenthOfString;
		int errorClass;
		MPI_Error_class(errorCode, &errorClass);
		MPI_Error_string(errorCode, errorString, &lenthOfString);
		printf("[ %d ] and [ %s ] \n", errorClass, errorString);
	}
}