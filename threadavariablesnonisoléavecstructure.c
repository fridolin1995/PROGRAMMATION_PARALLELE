#include<unistd.h>
#include<stdio.h>
#include<pthread.h> 
#include<string.h>
#include<math.h>
#define taille 4            //librairie indiquant la taille du tableau

struct tableau 
{
int x;
int contenu [taille];     //  declaration de la taille du tableau
};
void* init(void*arg)
{
int psc0=0;         //psc singifie produit scalaire
int psc,U,V;
struct tableau*p =(struct tableau*)arg;
for(int k=0;k<taille;k++)     //boucle for definissant la taille du tableau
{
(*p).contenu[k]=k;
U=(*p).contenu[k];
}
printf("%d\n",U);
}
int main()
{
int psc;
struct tableau r;
struct tableau p;
pthread_t t[1];
int 
err1=pthread_create(&(t[0]),NULL,init,&p); //err1 code retournant le pthread crée
sleep(5);
return 0;
}



