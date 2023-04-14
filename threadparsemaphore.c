#include<unistd.h>
#include<stdio.h>
#include<pthread.h> 
#include<string.h>
#include<math.h>
#include<semaphore.h>
#define taille 4            //librairie indiquant la taille du tableau
int U=0;
struct tableau 
{
int i;
int contenu1[taille];
int contenu2[taille];
sem_t semaphore;    
};
void* init(void*arg)
{
int psc0=0;       
pthread_t tid =pthread_self();
struct tableau *p=(struct tableau*)arg;

sem_wait(&(*p).semaphore); 
while((*p).i<taille)
{
  (*p).contenu1[(*p).i]=(*p).i;
  (*p).contenu2[(*p).i]=(*p).i+1;

U=U+((*p).contenu1[(*p).i])*((*p).contenu2[(*p).i]);
(*p).i++;
printf(" la valeur de U calculée est %d\n calculée par pthread %ld\n ",U,tid);
sem_post(&(*p).semaphore);
}
sleep(1);

}

int main()
{
struct tableau p;

p.i=0;

pthread_t t[3];
sem_init(&p.semaphore,0,1);

   int err1=pthread_create(&(t[0]),NULL,init,&p);
printf("creation du thread numero %ld\n ",t[0]);
  int err2=pthread_create(&(t[1]),NULL,init,&p);
printf("creation du thread numero %ld\n ",t[1]);
int err3=pthread_create(&(t[2]),NULL,init,&p);
printf("creation du thread numero %ld\n ",t[2]);
sleep(5);
sem_destroy(&p.semaphore);
return 0;
}
