#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
     
     int main()
          {
           int pid1= fork();
           (pid1==0)
           {
           printf("je suis le fils\n");
       exit(0);
               }
        else
      {
          printf("je suis chez le pere\n");
        exit(0);
              }
              }/*fin main */
