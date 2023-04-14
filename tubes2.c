#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
int filedes[2], nbytes, nombre, readint;
 pid_t childpid;
 pipe(filedes);
if((childpid = fork()) == -1)
{
perror("fork");
exit(1);
}
if(childpid ==0)
{
close(filedes[0]); // on ferme la partie de lecture
for(nombre=1;nombre<=20;nombre++ )
{
write(filedes[1], &nombre, sizeof(int));
}
exit(0);
}
else
{
int compteur =1;    //fichier du processus pere
close(filedes[1]);
while(compteur<=17)
{
nbytes = read(filedes[0], &readint, sizeof(int)); // on lit avec read et on affiche par printf 
printf("%d",readint);
compteur++;
}
}
return (0);
}
