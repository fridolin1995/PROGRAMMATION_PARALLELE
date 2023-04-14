#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
     
     int main()
          {
           int pid1= fork();
          if(pid1==0)
          
         printf("je suis le fils\n");
      sleep(30);
        int pid2= fork();
       if(pid2==0)
          printf("je suis chez le pere\n");
            sleep(20);
        int pid3= fork();
     if(pid3==0)
 printf("je suis  le fils de lambert\n");
              }/*fin main */
