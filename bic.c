 #include<unistd.h>
  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
  #include<sys/wait.h>
  int main()
  {
printf("entre la valeur de x\n");
  int P[3];
double x;
  char message[50];
  pipe(P);
  int pid=fork();
while(x !=0)
{
if(x<0)
{
printf("message d'avertissement\n");
}
else
{
printf("je depose dans le tube le message :%s", message);
}
}
 if(pid==0)
  {

  printf("message du pere au fils\n");
  printf(message,"hello pere\n");
  write(P[1],message,sizeof(message));
  printf("je depose dans le tube le message :%s",message);
 exit(1);
  }

  else
{
 read(P[0],message,sizeof(message));
 printf("le fils a dit:%s",message);

wait(NULL);

}
   
return 0;     
}
