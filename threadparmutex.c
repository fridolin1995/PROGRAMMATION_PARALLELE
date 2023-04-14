#include<unistd.h>
#include<stdio.h>
#include<pthread.h> 
#include<string.h>
#include<math.h>
#define taille 4            //librairie indiquant la taille du tableau
int U=0;
struct tableau 
{
int i;
int contenu1[taille];
int contenu2[taille];
pthread_mutex_t mutex;    //  declaration de la taille du tableau
};
void* init(void*arg)
{
int psc0=0;         //psc singifie produit scalaire
pthread_t tid =pthread_self();
struct tableau *p = (struct tableau*) arg;
pthread_mutex_lock(&(*p).mutex); //section critique
while((*p).i<taille)
{
  (*p).contenu1[(*p).i]=(*p).i;
  (*p).contenu2[(*p).i]=(*p).i+1;

U=U+((*p).contenu1[(*p).i])*((*p).contenu2[(*p).i]);
(*p).i++;
printf(" la valeur de U calculée est %d\n calculée par pthread %ld\n ",U,tid);
pthread_mutex_unlock(&(*p).mutex);
}
sleep(1);

}

int main()
{
struct tableau p;

p.i=0;

pthread_t t[2];
int err=pthread_mutex_init(&p.mutex,NULL);

   int err1=pthread_create(&(t[0]),NULL,init,&p);
printf("creation du thread numero %ld\n ",t[0]);
  int err2=pthread_create(&(t[1]),NULL,init,&p);
printf("creation du thread numero %ld\n ",t[1]);
sleep(5);
pthread_mutex_destroy(&p.mutex);
return 0;
}

