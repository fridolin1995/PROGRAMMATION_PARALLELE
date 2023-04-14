#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
int pid;
char *parmalist[3];
      parmalist[0]=(char*)"firefox";
      
      parmalist[1]=(char*)"overleaf";
      parmalist[2]=NULL;
execvp(parmalist[0],parmalist);
}
