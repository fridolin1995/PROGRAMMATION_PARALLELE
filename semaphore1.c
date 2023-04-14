#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>


// Nombre total de thread
#define NB_THREAD 4
// Limite de l'incrément
#define INCREMENT_LIMIT 10

// Tableau contenant les threads
pthread_t threads[NB_THREAD];

// Structure de données contenant le semaphore
typedef struct semaphore_data {
	int fact;
int i;
	sem_t semaphore;//      
} sem_data;

// Fonction exécutée dans le thread
void * job(void *arg) 
{
	sem_data *md = (sem_data*) arg;

sem_wait(&(*md).semaphore);
	
for (int l=0;l<3;l++)
{

 (*md).i++; 
 (*md).fact=(*md).fact*(*md).i;
if((*md).i==INCREMENT_LIMIT)
break;
 
}
printf("La valeur courante de factoriel est %d, elle est calculee par le thread numero %ld\n ", (*md).fact, pthread_self());
sem_post(&(*md).semaphore); 
		
		// Pause l'exécution du thread pendant 1 seconde
		sleep(1);
 return 0;	
	
}

// Fonction principale
int main() {
	// Création du mutex
	sem_data md;
	// Initialisation de la donnée
	md.fact = 1;
    md.i =0 ;
	// Initialisation du mutex
	if (sem_init(&md.semaphore,NULL) != 0) {
		printf("\n mutex init failed\n");
		return EXIT_FAILURE;
	}
	// Boucle de création des threads
int k=0;
for (int k = 0; k < NB_THREAD; k++)

	 {
		// Création du thread et passage de la structure par référence
		int err = pthread_create(&threads[k], NULL, job, &md);


 
	}
	// En attente des threads
	for (int i = 0; i < NB_THREAD; i++) {
		pthread_join(threads[i], NULL);
	}
	// Destruction du mutex
	sem_destroy(&md.semaphore);
	return 0;


}
