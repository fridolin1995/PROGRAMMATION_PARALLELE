#include<stdio.h>
#include<mpi.h>
MPI_Status status;
int main (int argc, char** argv)
{
MPI_Init(&argc, &argv);
int rank;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
int size;
MPI_Comm_size(MPI_COMM_WORLD, &size);
int root=0;
int dest=2;
int number;
if (rank==0)
{
 number =5;
    MPI_Send(&number, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
}
else if (rank==2)
{
    MPI_Recv(&number, 1, MPI_INT,root,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);//&status);
printf("Process  %d received number %d from process 0\n",rank, number);

}
    
return 0;
}
