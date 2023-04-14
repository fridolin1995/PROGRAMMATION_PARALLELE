#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
 {
int n;
int filedes[2];
     char buffer[1025];
const   char *message = "Lecons sur la communicatios inter processus";
  pipe(filedes);
 write(filedes[1], message, strlen(message));
if((n = read(filedes[0],buffer,1024 ))>=0)

{
printf("read %d bytes from the pipe: %s",n, buffer);
}
else
 perror("read");
 exit(0);
}


