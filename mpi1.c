#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int main(int argc,char **argv)
 {
  	int ierr, num_procs, my_id;
  	ierr= MPI_Init(&argc, &argv);
  	
  	/* find out My process ID, and how many process were started.*/
  	
  	ierr= MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
  	ierr= MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
  	
  	printf("Hello world! I'm process %i out of %i processes \n",my_id, num_procs);
  	
 sleep(1);
   MPI_Finalize();
   
return 0;
}
