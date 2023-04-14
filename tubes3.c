#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
int filedes[2], nbytes, nombre, readint;
 pid_t childpid;
int Tableau[10];
 pipe(filedes);
if((childpid = fork()) == -1)
{
perror("fork");
exit(1);
}
if(childpid ==0)
{
close(filedes[0]);
for(nombre=1;nombre>10;nombre++ )
{
Tableau[nombre]=nombre+1; 
}
write(filedes[1], &Tableau, sizeof(int));

exit(0);
}
else
{
int compteur =1;
close(filedes[1]);
while(compteur<=9)
{
nbytes = read(filedes[0], &readint, sizeof(int));
printf("%d",readint);
compteur++;
}
}
return (0);
}
