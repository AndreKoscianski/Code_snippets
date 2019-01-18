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

int GTurn;

bool GWant[2];

#define NLOOP 10222000


void *doSomeThing (void *aid) {

    unsigned long  i = 0;

    long int id = ((long int) aid);

   for(i = 0; i < NLOOP; i++) {

      GWant[id] = 1;
      GTurn     = 1-id;

      while (((1-id) == GTurn) && GWant[1-id]) ;

      Gn = Gn + (1 - (2 * id));

      GWant[id] = 0;

	}

   return NULL;
}



//===========================================================

int main (void) {


    if (pthread_create (&tid1, NULL, &doSomeThing, (void*) 0)) {puts ("erro1"); exit(0);}
    if (pthread_create (&tid2, NULL, &doSomeThing, (void*) 1)) {puts ("erro2"); exit(0);}

    pthread_join (tid1, NULL);
    pthread_join (tid2, NULL);

    printf ("\nResultado Final = %d\n", Gn);

    return 0;
}
