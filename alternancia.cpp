/*------------------------------------------------------


para compilar

  g++ threads.cpp -lpthread

  ------------------------------------------------------
*/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h> 
#include <semaphore.h>

pthread_t tid1, tid2;

static sem_t Gsem;

int Gn = 0;
int Gk = 0;
volatile int GTurn;
volatile bool GWant[2];

#define NLOOP 1222000

volatile bool uh = false;

void *doSomeThing0 (void *aid) {

   printf ("pid %d  tid %d\n", getpid(), (int) pthread_self());

   unsigned long  i = 0;

   for(i = 0; i < NLOOP; i++) {

      GTurn    = 1;

      while (1 == GTurn) Gk++;

if (uh) exit(0); uh = true;
      Gn = Gn + 1; //putchar ('-');putchar ('\n');
uh = false;
	}
   GTurn    = 1;
   return NULL;
}

void *doSomeThing1 (void *aid) {

   printf ("pid %d  tid %d\n", getpid(), (int) pthread_self());

   unsigned long  i = 0;

   for(i = 0; i < NLOOP; i++) {

      GTurn    = 0;

      while (0 == GTurn) Gk++;

if (uh) exit(0); uh = true;
      Gn = Gn - 1; // putchar ('+');putchar ('\n');
uh = false;
	}
   GTurn    = 0;
   return NULL;
}


//===========================================================

int main (void) {

    GWant[0] = GWant[1] = 0;

//doSomeThing0(0);
//doSomeThing1(0);

    printf ("\nInicialmente = %d\n", Gn);

    if (pthread_create (&tid1, NULL, &doSomeThing0, (void*) 0)) {puts ("erro1"); exit(0);}
    if (pthread_create (&tid2, NULL, &doSomeThing1, (void*) 1)) {puts ("erro2"); exit(0);}

    pthread_join (tid1, NULL);                //printf ("voila\numa pequena\n pausa\n");
    pthread_join (tid2, NULL);

    printf ("\nResultado Final = %d       %d\n", Gn, Gk);

    return 0;
}
