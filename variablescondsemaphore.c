#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>

sem_t semaphore;
pthread_cond_t c;
int nombre;
int seuil;


void *increment()
{

sem_wait(&semaphore); // section critique
nombre=1;
while(nombre<seuil)
printf("%d\n",nombre++);
pthread_cond_signal(&c);  //reveiller le processus qui a attendu la condition
sem_post(&semaphore);
}
void * affichage(void *arg) 
{
printf("Je suis le thread fils\n");
increment();
return NULL;
}
void  thread_join()
 {

sem_wait(&semaphore);
if (nombre<seuil) 
pthread_cond_wait(&c, &semaphore);
sem_post(&semaphore);
printf("la valeur final de nombre %d\n",nombre);

}
int main(int argc, char*argv[]) 
{
seuil=6;

	// Initialisation de la donnée

if(sem_init(&semaphore,0,1)!= 0) {
		printf("\n semaphore init failed\n");
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
sem_destroy(&semaphore);
return 0;
}
