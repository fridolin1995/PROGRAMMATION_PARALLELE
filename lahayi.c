#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

     
     int main()
          {
           int pid1= fork();
           if(pid1==0)
           {
          printf("je suis le fils :"" 
pid: %d ppid: %d\n" ,getpid ,getppid());
 sleep(60);
       exit(0);
               }
       
      waitpid(pid,NULL,0);
      
          printf("mon fils a deja termine son execution :"" pid: %d\n" ,pid);
        return 0;
 
              }/*fin main */
     

