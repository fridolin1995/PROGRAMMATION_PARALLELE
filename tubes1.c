#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
 {
int n;
int filedes[2];
     char buffer[10];
const   char *message = "0,1,2,3,4,5,6,7,8,9,10 ";
  pipe(filedes);
 write(filedes[1], message, strlen(message));
if((n = read(filedes[0],buffer, 9 ))>=0)

{
printf(" read the %d  enters are: %s",n, buffer);
}
else
perror("read");
exit(0);

}

