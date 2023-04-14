#include<stdio.h>
#include<pthread.h>

void *WriteToSTDOUT(void* message)
{
fprintf(stdout,"Thread A~: %s\n",(char*)message);
return NULL;
}
int 
main(void)
{
void*ptr;

pthread_t threads;
pthread_create(&threads,NULL,WriteToSTDOUT,(void*)"bonjour MON ENFANT TU VAS BIEN");
pthread_join(threads,&ptr);
return 0;
} 
