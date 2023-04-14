#include <stdio.h>
   #include <mpi.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>
   
  
   #define send_data_tag 2001
   #define return_data_tag 2002

  
 
   
   int main(int argc, char **argv) 
   {
       int sum, total_sum, num_rows;
num_rows=5;
 int array[num_rows];
      MPI_Status status;
      int my_id, ierr, i, num_procs,root_process;


      ierr = MPI_Init(&argc, &argv);
      
      root_process = 0;
      
     
      
      ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
      ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

      if(my_id == 3) 

      
      total_sum=0;

         for(i = 0; i < num_rows; i++) 
{
            scanf("%d", &array[i]);
            total_sum=total_sum+array[i];
         }

        printf("La somme totale calculee est :  %d\n:",total_sum );

           

            ierr = MPI_Send( &total_sum, 1, MPI_INT,2, send_data_tag, MPI_COMM_WORLD);
         }

        

         else{
            
            ierr = MPI_Recv( &total_sum, 1, MPI_INT, 0,send_data_tag, MPI_COMM_WORLD, &status);
  
      
     
          total_sum = total_sum/num_rows;
 printf("La moyenne calculee est :  %d\n:",total_sum );
         }

         
      
      ierr = MPI_Finalize();
return 0;
   }
