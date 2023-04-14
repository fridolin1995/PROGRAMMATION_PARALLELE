#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
     
     int main()
          {
           int pid1= fork();
          
          
         printf("je suis le fils\n");
      
        int pid2= fork();
          printf("je suis chez le pere\n");
         
 printf("je suis  le fils de lambert\n");
              }/*fin main */
