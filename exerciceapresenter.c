#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h> 
#include<sys/wait.h>
void *ma_fonction1(void*arg)
{
printf(" A \n");
return NULL; 
}

void *ma_fonction2(void*arg)
{
printf(" B \n"); 
return NULL; 
}
int main(void)
{
pthread_t tid1,tid2;
int i=0;
int err1;
int err2;
void *ptr;
err1=pthread_create(&(tid1),NULL, ma_fonction1,NULL);
err2=pthread_create(&(tid2),NULL, ma_fonction2,NULL);
if(err1!=0)
{
printf("\n Le thread n'est pas crée  ");
}
else
{
int pthread_join(pthread_t tid1, void **ptr);
printf("\n Je suis A et j'ai fini \n");
void pthread_exit(void *ptr);/*pour spécifier la valeur du Thread*/
}

if(err2!=0)
{
printf("\n Thread2 n'est pas cree\n");
}

else
{
int pthread_join(pthread_t tid2, void **ptr);/*pour attendre qu'un thread se termine*/
printf("\n je suis B et j'ai fini\n");
void pthread_exit(void *ptr);/*pour spécifier la valeur du Thread*/
}
return 0;
}

