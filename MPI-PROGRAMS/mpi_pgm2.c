#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc , char *argv[]){
	int returns;
	returns = MPI_Init(&argc,&argv);
	if(returns == MPI_SUCCESS){
		printf("Successfully setup MPI environement\n");
	}else{
		printf("Setting up environement got failed\n");
	}
	returns = MPI_Finalize();
	if(returns == MPI_SUCCESS){
		printf("MPI environment closed\n");
	}else{
		printf("failed to create mpi environment\n");
	}
	printf("\n\n");
	return 0;
}