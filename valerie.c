#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
         int main()
             {
       const char *prog="Texmaker";
       int pid1=fork();
          if (pid1==0)
               {
         execlp(prog,prog,NULL);
exit(0);
}

return 0;
}
