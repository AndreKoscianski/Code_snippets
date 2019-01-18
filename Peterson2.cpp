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

sem_t Gsem;

int Gk = 0;
volatile int Gn = 0;
volatile int GTurn;
volatile bool GWant[2];

#define NLOOP 1222000

void *doSomeThing0 (void *aid) {

   printf ("pid %d  tid %d\n", getpid(), (int) pthread_self());

   unsigned long  i = 0;

   for(i = 0; i < NLOOP; i++) {

      GWant[0] = 1;
      GTurn    = 1;

      while (GWant[1] && (1 == GTurn));// Gk++;

      Gn = Gn + 1; //puts ("+");

      GWant[0] = 0;
	}
   return NULL;
}

void *doSomeThing1 (void *aid) {

   printf ("pid %d  tid %d\n", getpid(), (int) pthread_self());

   unsigned long  i = 0;

   for(i = 0; i < NLOOP; i++) {

      GWant[1] = 1;
      GTurn    = 0;

      while (GWant[0] && (0 == GTurn));// Gk++;

      Gn = Gn - 1; //puts ("-");

      GWant[1] = 0;
	}
   return NULL;
}


//===========================================================

int main (void) {

    GWant[0] = GWant[1] = 0;

//doSomeThing0(0);
//doSomeThing1(0);

    printf ("\nInicialmente = %d\n", Gn);

    if (pthread_create (&tid1, NULL, &doSomeThing0, (void*) 0)) {puts ("erro1"); }
    if (pthread_create (&tid2, NULL, &doSomeThing1, (void*) 1)) {puts ("erro2"); }

    puts ("\nexecutando\n");

    pthread_join (tid1, NULL);                //printf ("voila\numa pequena\n pausa\n");
    pthread_join (tid2, NULL);

    printf ("\nResultado Final = %d       %d\n", Gn, Gk);

    return 0;
}
