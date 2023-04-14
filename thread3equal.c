#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h> //une fonction retournant le id du thread crée
#include<stdlib.h>

void * ma_fonction(void*arg)
{
printf("hello world affiche par le thread %ld\n", pthread_self() );
pthread_t i= pthread_self(); //dans id on trouve le id crée
return NULL;
}
int main(void)
{
pthread_t tid;
int i= 0;
int err;
void*ptr;
err= pthread_create(&(tid),NULL,ma_fonction,NULL);
if( err!=0)
{
printf("\n can't create thread:[%s]",strerror(err));
}
else
{
int pthread_join(pthread_t tid,void *ptr);
printf("\n Thread created successfully ");
sleep(10);
printf("\n id");
if(pthread_equal(i,tid)== 0) //mettre deux valeurs identiques dans pthread 
{
printf("\n meme thread en effet");
}
else
{
printf("\n erreur");
}
void pthread_exit(void * ptr);
pthread_detach(tid);
}
return 0;
} 
