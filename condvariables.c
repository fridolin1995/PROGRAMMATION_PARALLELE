#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t mut;
pthread_cond_t c;
int nombre;
int seuil;


void *increment()
{

pthread_mutex_lock(&mut); // section critique
nombre=1;
while(nombre<seuil)
printf("%d\n",nombre++);
pthread_cond_signal(&c);  //reveiller le processus qui a attendu la condition
pthread_mutex_unlock(&mut);
}
void * affichage(void *arg) 
{
printf("Je suis le thread fils\n");
increment();
return NULL;
}
void  thread_join()
 {

pthread_mutex_lock(&mut);
if (nombre<seuil) 
pthread_cond_wait(&c, &mut);
pthread_mutex_unlock(&mut);
printf("la valeur final de nombre %d\n",nombre);

}
int main(int argc, char*argv[]) 
{
seuil=6;

	// Initialisation de la donnée

if(pthread_mutex_init(&mut, NULL)!= 0) {
		printf("\n mutex init failed\n");
		return EXIT_FAILURE;
}
	if(pthread_cond_init(&c, NULL)!= 0) {
		printf("\n cond init failed\n");
		return EXIT_FAILURE;
	}

printf("Je suis le thread principal \n");
pthread_t p;
pthread_create(&p, NULL, &affichage, NULL);
thread_join();
pthread_mutex_destroy(&mut);
return 0;
}
