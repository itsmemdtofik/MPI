#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>

int main(int argc, char *argv[]){

	double startTime;
	double endTime;

	MPI_Init(&argc, &argv);
	MPI_Barrier(MPI_COMM_WORLD);

	startTime = MPI_Wtime();
	endTime = MPI_Wtime();

	for(int i = 0; i < 1000000; i++);
		printf("Process took [ %f ] seconds \n", (endTime - startTime));
	MPI_Finalize();
	printf("Enter the number of process : ");
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	return 0;
}
