         //réponses

 //Le programme ci-dessous affiche deux resultal:
 
 //Thread est créé 

 //Hello world affiche par le thread 140210699650816 
 
         //programme

#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/wait.h>


pthread_t tid[5];
void*ma_fonction(void*arg)
{
printf("\n Hello world affiche par le thread %ld\n",pthread_self());

return NULL;
}
int main(void)
{
int i=0;
int err;
while(i<1)
{
	err=pthread_create(&(tid[i]),NULL,&ma_fonction,NULL);
if(err!=0)
printf("\n Thread n'est pas créé :[%s]",strerror(err));
else
printf(" Thread est créé \n" );

i++;
}
sleep(5);
return 0;
}

