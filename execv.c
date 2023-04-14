#include<sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include<sys/wait.h>
#include <string.h>
#include <stdlib.h>
int main()
        {
   char *parmalist[2];
         parmalist[0]=(char*)"./home";
   	 parmalist[1]=NULL;
	int pid;
         pid= fork();
	 if(pid==0)

			 
{execvp(parmalist[0],parmalist);

}
return 0;

  } 

        	
     
