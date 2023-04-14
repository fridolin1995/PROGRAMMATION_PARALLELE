#include<unistd.h>
#include<stdio.h>
#include<pthread.h> //une fonction retournant le id du thread crée


void * ma_fonction(void*arg)

{
printf("hello world affiche par le thread %ld\n", pthread_self() ); 
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
void pthread_exit(void * ptr);
sleep(60);
pthread_detach(tid);
}
return 0;
} 
