#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() //fonction principal
{
int tableau[1], nbytes, nombre, readint; //declarations des variables
 pid_t childpid;
 pipe(tableau);
if((childpid = fork()) == -1)
{
perror("fork");
exit(1);
}
if(childpid ==0)
{
close(tableau[0]);
 // on ferme la partie de lecture dans le processus fils
for(nombre=10;nombre>=4;nombre-- ) 
//on commence la boucle for
{
write(tableau[1], &nombre, sizeof(int)); 
//on ecrit les variables dans la boucles
}
exit(0);
}//on quitte le boucle for 
else
{
int compteur =1; 
   // initialisation du compteur de nombre dans le  processus pere
close(tableau[1]);
while(compteur<=7) // début du boucle while
{
nbytes = read(tableau[0], &readint, sizeof(int)); // on lit les variables avec read et on affiche par printf 
printf("%d",readint); //on fait affichage des nombres
compteur++;
}
}
return (0);
}
